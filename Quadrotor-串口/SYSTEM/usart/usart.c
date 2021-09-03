#include "usart.h"	


u8 TxBuffer[256];
u8 TxCounter=0;
u8 count=0; 

 


void USART1_Init(u32 bound)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);   //ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);  //ʹ��USART1ʱ��
 

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);  //GPIOA9����ΪUSART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10����ΪUSART1
	
	//USART1�˿�����
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;    //GPIOA9��GPIOA10
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;             //���ù���
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	       //�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;           //���츴�����
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;             //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);                  //��ʼ��PA9��PA10

  //USART1��ʼ������
	USART_InitStructure.USART_BaudRate=bound;                                          //����������
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;                          //�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits=USART_StopBits_1;                               //һ��ֹͣλ
	USART_InitStructure.USART_Parity=USART_Parity_No;                                  //����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;      //��Ӳ������������
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;	                       //�շ�ģʽ
  USART_Init(USART1,&USART_InitStructure);                                           //��ʼ������1
	
	//Usart1 NVIC����
  NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;                   //����1�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;             //��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;		                //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;			                //IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	                                    //����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);     //ʹ�ܽ����ж�
  USART_Cmd(USART1,ENABLE);                        //ʹ�ܴ���1 
	USART_ClearITPendingBit(USART1,USART_IT_TXE);
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}


 


void USART1_IRQHandler(void)
{
	u8 com_data;
  //�����ж�
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		com_data=USART1->DR;
		USART_SendData(USART1,com_data);///////////////��ʱʹ��
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//��������ж�
	}
	//�����ж�
	if(USART_GetITStatus(USART1,USART_IT_TXE))
	{	
		USART1->DR=TxBuffer[TxCounter++];         
		if(TxCounter==count)
		{
			USART_ITConfig(USART1,USART_IT_TXE,DISABLE);//�ر�TXE�������жϣ��ж�
		}	
		USART_ClearITPendingBit(USART1,USART_IT_TXE);//��������ж�		
	}
}



void USART1_Send(u8 *DataToSend,u8 data_num)
{
  u8 i;
	for(i=0;i<data_num;i++)
	{
		TxBuffer[count++]=*(DataToSend+i);
	}
	if(!USART_GetITStatus(USART1,USART_IT_TXE))
	{
		USART_ITConfig(USART1,USART_IT_TXE,ENABLE); //�򿪷����ж�
	}
}


 



