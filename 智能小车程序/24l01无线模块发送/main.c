#include "common.h"
#include "nRF24L01_TX.h"
#include"delay.h"


void main(void)
{
	P0=0xff;//��ʼ��IO��
	P1=0xff;
	P2=0xff;
	P3=0xff;
	delay_us(100);
	nRF24L01_Init();//NRF24L01��ʼ��
	while(1)
	{
		if(Key1==0)
		{
			delay_ms(10);
			if(Key1==0)
			{		
				nRF24L01_Set_TX_Mode(&TX_Buffer1[0]);//��������
				while(Check_Ack());//�ȴ��������
				LED1=0;
				delay_ms(10);
			}
		}
		if(Key2==0)
		{
			delay_ms(10);
			if(Key2==0)
			{		
				nRF24L01_Set_TX_Mode(&TX_Buffer2[0]);//��������
				while(Check_Ack());//�ȴ��������
				LED2=0;
				delay_ms(10);
			}
		}
		if(Key3==0)
		{
			delay_ms(10);
			if(Key3==0)
			{		
				nRF24L01_Set_TX_Mode(&TX_Buffer3[0]);//��������
				while(Check_Ack());//�ȴ��������
				LED3=0;
				delay_ms(10);
			}
		}
		if(Key4==0)
		{
			delay_ms(10);
			if(Key4==0)
			{		
				nRF24L01_Set_TX_Mode(&TX_Buffer4[0]);//��������
				while(Check_Ack());//�ȴ��������
				LED4=0;
				delay_ms(10);
			}
		}
//		if(Key5==0)
//		{
//			delay_ms(10);
//			if(Key5==0)
//			{		
//				nRF24L01_Set_TX_Mode(&TX_Buffer5[0]);//��������
//				while(Check_Ack());//�ȴ��������
//				LED5=0;
//				delay_ms(10);
//			}
//		}
//		if(Key6==0)
//		{
//			delay_ms(10);
//			if(Key6==0)
//			{		
//				nRF24L01_Set_TX_Mode(&TX_Buffer6[0]);//��������
//				while(Check_Ack());//�ȴ��������
//				LED6=0;
//				delay_ms(10);
//			}
//		}
//		if(Key7==0)
//		{
//			delay_ms(10);
//			if(Key7==0)
//			{		
//				nRF24L01_Set_TX_Mode(&TX_Buffer7[0]);//��������
//				while(Check_Ack());//�ȴ��������
//				LED7=0;
//				delay_ms(10);
//			}
//		}
//		if(Key8==0)
//		{
//			delay_ms(10);
//			if(Key8==0)
//			{		
//				nRF24L01_Set_TX_Mode(&TX_Buffer8[0]);//��������
//				while(Check_Ack());//�ȴ��������
//				LED8=0;
//				delay_ms(10);
//			}
//		}
		else
		{
			LED1=1;
			LED2=1;
			LED3=1;
			LED4=1;
			LED5=1;
			LED6=1;
			LED7=1;
			LED8=1;
		}			
	}
}