#include "eeprom.h" 
#include "iic.h"
#include "delay.h" 				 





//��AT24C02ָ����ַ����1���ֽڵ�����
//BYTE_ADDRESS:��ʼ�����ĵ�ַ  
//temp:����������
u8 AT24C02_Read_1Byte(u8 BYTE_ADDRESS)
{				  
	u8 temp;	
	IIC_Read_1Byte(AT24C02_ADDRESS,BYTE_ADDRESS,&temp);   
	return temp;
}






//��AT24C02ָ����ַд��1���ֽڵ�����
//BYTE_ADDRESS:д�����ݵ�Ŀ�ĵ�ַ    
//DATA:Ҫд�������
void AT24C02_Write_1Byte(u8 BYTE_ADDRESS,u8 DATA)
{				
	IIC_Write_1Byte(AT24C02_ADDRESS,BYTE_ADDRESS,DATA);	
}








//��AT24C02�����ָ����ַ��ʼ����n���ֽڵ�����
//BYTE_ADDRESS :��ʼ�����ĵ�ַ      AT24C02Ϊ0~255
//Buffer:���������׵�ַ
//n:Ҫ�������ݵĸ���
void AT24C02_Read_nByte(u8 BYTE_ADDRESS,u8 *temp,u8 n)
{
	u8 i;
	for(i=0;i<n;i++)
	{
		*temp++=AT24C02_Read_1Byte(BYTE_ADDRESS++);	
	}
}  









//��AT24C02�����ָ����ַ��ʼд��n���ֽڵ�����
//BYTE_ADDRESS :��ʼд��ĵ�ַ      AT24C02Ϊ0~255
//Buffer:���������׵�ַ
//n:Ҫд�����ݵĸ���
void AT24C02_Write_nByte(u8 BYTE_ADDRESS,u8 *temp,u8 n)
{
	u8 i;
	for(i=0;i<n;i++)
	{
		AT24C02_Write_1Byte(BYTE_ADDRESS++,*temp++);
	}
}










//��AT24C02�����ָ����ַ��ʼ��������Ϊ16bit������
//BYTE_ADDRESS:��ʼ�����ĵ�ַ 
//temp:����������
//2:Ҫд�����ݵ��ֽڳ���
u16 AT24C02_Read_16Bit(u8 BYTE_ADDRESS)
{  	
	u8 i;
	u16 temp=0;
	for(i=0;i<2;i++)
	{
		temp<<=8;
		temp+=AT24C02_Read_1Byte(BYTE_ADDRESS+2-i-1); 	 				   
	}
	return temp;												    
}






//��AT24C02�����ָ����ַ��ʼд�볤��Ϊ16bit������
//BYTE_ADDRESS:��ʼд��ĵ�ַ  
//DATA:���������׵�ַ
//2:Ҫд�����ݵ��ֽڳ���
void AT24C02_Write_16Bit(u8 BYTE_ADDRESS,u16 DATA)
{  	
	u8 i;
	for(i=0;i<2;i++)
	{
		AT24C02_Write_1Byte(BYTE_ADDRESS+i,(DATA>>(8*i))&0xff);
	}												    
}






//��AT24C02�����ָ����ַ��ʼ��������Ϊ32bit������
//BYTE_ADDRESS:��ʼ�����ĵ�ַ 
//temp:����������
//4:Ҫд�����ݵ��ֽڳ���
u32 AT24C02_Read_32Bit(u8 BYTE_ADDRESS)
{  	
	u8 i;
	u32 temp=0;
	for(i=0;i<4;i++)
	{
		temp<<=8;
		temp+=AT24C02_Read_1Byte(BYTE_ADDRESS+4-i-1); 	 				   
	}
	return temp;												    
}







//��AT24C02�����ָ����ַ��ʼд�볤��Ϊ32bit������
//BYTE_ADDRESS:��ʼд��ĵ�ַ  
//DATA:���������׵�ַ
//4:Ҫд�����ݵ��ֽڳ���
void AT24C02_Write_32Bit(u8 BYTE_ADDRESS,u32 DATA)
{  	
	u8 i;
	for(i=0;i<4;i++)
	{
		AT24C02_Write_1Byte(BYTE_ADDRESS+i,(DATA>>(8*i))&0xff);
	}												    
}














//���AT24C02�Ƿ�����
//��������2402�����һ����ַ(255)���洢��־��.
//����0:���ʧ��
//����1:���ɹ�
u8 AT24C02_Check(void)
{
	u8 temp;
	temp=AT24C02_Read_1Byte(255);          //����ÿ�ο�����дAT24C02		   
	if(temp==0X55)
	{
		return 1;	
	}	
	else                                   //�ų���һ�γ�ʼ�������
	{
		AT24C02_Write_1Byte(255,0X55);
		temp=AT24C02_Read_1Byte(255);	  
		if(temp==0X55)
			return 1;
	}
	return 0;											  
}





