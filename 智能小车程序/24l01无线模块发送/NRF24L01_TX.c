#include "nRF24L01_TX.h"
#include"delay.h"

uchar sta; //״̬���� 
uchar code TX_Addr[]={0x34,0x43,0x10,0x10,0x01};//���͵�ַ
uchar code TX_Buffer1[]={0xfe};
uchar code TX_Buffer2[]={0xfb};
uchar code TX_Buffer3[]={0xfd};
uchar code TX_Buffer4[]={0xf7};
uchar code TX_Buffer5[]={0xef};
uchar code TX_Buffer6[]={0xdf};
uchar code TX_Buffer7[]={0xbf};
uchar code TX_Buffer8[]={0x7f};
uchar RX_Buffer[RX_DATA_WITDH];

//nRF24L01��ʼ��
void nRF24L01_Init(void)
{
	CE=0;//����ģʽ��
	CSN=1;
	SCK=0;
	IRQ=1;
}

//SPIʱ����
uchar SPI_RW(uchar byte)
{
	uchar i;
	for(i=0;i<8;i++)//һ�ֽ�8λѭ��8��д��
	{
		if(byte&0x80)//����������λ��1
			MOSI=1;//��NRF24L01д1
		else //����д0
			MOSI=0;
		byte<<=1;//��һλ�Ƶ����λ
		SCK=1;//SCK���ߣ�д��һλ���ݣ�ͬʱ��ȡһλ����
		if(MISO)
			byte|=0x01;
		SCK=0;//SCK����
	}
	return byte;//���ض�ȡһ�ֽ� 
}


//SPIд�Ĵ���һ�ֽں���
//reg:�Ĵ�����ַ
//value:һ�ֽڣ�ֵ��
uchar SPI_W_Reg(uchar reg,uchar value)
{
	uchar status;//����״̬
	CSN=0;//SPIƬѡ
	status=SPI_RW(reg);//д��Ĵ�����ַ��ͬʱ��ȡ״̬
	SPI_RW(value);//д��һ�ֽ�
	CSN=1;//
	return status;//����״̬
}

//SPI��һ�ֽ�
uchar SPI_R_byte(uchar reg)
{
	uchar reg_value;
	CSN=0;//SPIƬѡ
	SPI_RW(reg);//д���ַ
	reg_value=SPI_RW(0);//��ȡ�Ĵ�����ֵ
	CSN=1;
	return reg_value;//���ض�ȡ��ֵ
}


//SPI��ȡRXFIFO�Ĵ�������
//reg:�Ĵ�����ַ
//Dat_Buffer:�������ȡ������
//DLen:���ݳ���
uchar SPI_R_DBuffer(uchar reg,uchar *Dat_Buffer,uchar Dlen)
{
	uchar status,i;
	CSN=0;//SPIƬѡ
	status=SPI_RW(reg);//д��Ĵ�����ַ��ͬʱ״̬
	for(i=0;i<Dlen;i++)
	{
		Dat_Buffer[i]=SPI_RW(0);//�洢����
	}
	CSN=1;
	return status;
}
//SPI��TXFIFO�Ĵ���д������
//reg:д��Ĵ�����ַ
//TX_Dat_Buffer:�����Ҫ���͵�����
//Dlen:���ݳ���	
uchar SPI_W_DBuffer(uchar reg,uchar *TX_Dat_Buffer,uchar Dlen)
{
	uchar status,i;
	CSN=0;//SPIƬѡ������ʱ��
	status=SPI_RW(reg);
	for(i=0;i<Dlen;i++)
	{
		SPI_RW(TX_Dat_Buffer[i]);//��������
	}
	CSN=1;
	return status;	
}
//���÷���ģʽ
void nRF24L01_Set_TX_Mode(uchar *TX_Data)
{
	CE=0;//������д�Ĵ���֮ǰһ��Ҫ�������ģʽ�����ģʽ��
	SPI_W_DBuffer(W_REGISTER+TX_ADDR,TX_Addr,TX_ADDR_WITDH);/*д�Ĵ���ָ��+���սڵ��ַ+��ַ���*/
	SPI_W_DBuffer(W_REGISTER+RX_ADDR_P0,TX_Addr,TX_ADDR_WITDH);/*Ϊ�˽����豸Ӧ���źţ�����ͨ��0��ַ�뷢�͵�ַ��ͬ*/
	SPI_W_DBuffer(W_TX_PLOAD,TX_Data,TX_DATA_WITDH);/*д��Ч���ݵ�ַ+��Ч����+��Ч���ݿ��*/
	SPI_W_Reg(W_REGISTER+EN_AA,0x01);/*����ͨ��0�Զ�Ӧ��*/
	SPI_W_Reg(W_REGISTER+EN_RX_ADDR,0x01);/*ʹ�ܽ���ͨ��0*/
	SPI_W_Reg(W_REGISTER+SETUP_RETR,0x0a);/*�Զ��ط���ʱ250US+86US���ط�10��*/
	SPI_W_Reg(W_REGISTER+RF_CH,0x40);/*(2400+40)MHZѡ����Ƶͨ��0X40*/
	SPI_W_Reg(W_REGISTER+RF_SETUP,0x07);/*1Mbps����,���书��:0DBM,�������Ŵ�������*/
	SPI_W_Reg(W_REGISTER+CONFIG,0x0e);/*����ģʽ,�ϵ�,16λCRCУ��,CRCʹ��*/
	CE=1;//��������
	delay_ms(5);/*CE�ߵ�ƽ����ʱ������10US����*/
}

uchar Check_Rec(void)
{
	uchar status;
	sta=SPI_R_byte(R_REGISTER+STATUS);
	if(RX_DR)
	{
		CE=0;
		SPI_R_DBuffer(R_RX_PLOAD,RX_Buffer,RX_DATA_WITDH);
		status=1;
	}
	SPI_W_Reg(W_REGISTER+STATUS,0xff);
	return status;	
}
//���Ӧ���ź�
uchar Check_Ack(void)
{
	sta=SPI_R_byte(R_REGISTER+STATUS);//��ȡ�Ĵ�״̬
	if(TX_DS||MAX_RT)//���TX_DS��MAX_RTΪ1,������жϺ����TX_FIFO�Ĵ�����ֵ
	{
		SPI_W_Reg(W_REGISTER+STATUS,0xff);
		CSN=0;
		SPI_RW(FLUSH_TX);//���û����һ��ֻ�ܷ�һ�����ݣ����Ҫע��
		CSN=1;
		return 0;
	}
	else
		return 1;
}
