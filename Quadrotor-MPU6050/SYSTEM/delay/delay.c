#include "delay.h"



static u8  fac_us=0;//us��ʱ������			   
static u16 fac_ms=0;//ms��ʱ������


//��ʼ���ӳٺ���
void delay_init(u8 SYSCLK)                                   //SYSCLK:ϵͳʱ��
{
 	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);      //SYSTICK��ʱ�ӹ̶�ΪHCLKʱ�ӵ�1/8  =21
	fac_us=SYSCLK/8;                                           //����ÿ��us��Ҫ��systickʱ����     =21000
	fac_ms=(u16)fac_us*1000;                                   //����ÿ��ms��Ҫ��systickʱ����   
}								    


 

//��ʱnus
//ע��:nus��ֵ,��Ҫ����(2^24-1)/21=798915us
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL=0x01;          //��ʼ���� 
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL=0x00;       //�رռ�����
	SysTick->VAL=0X00;       //��ռ�����	 
}



//��ʱnms
//ע��:nms��ֵ,��Ҫ����(2^24-1)/21000=798ms 
void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           //��ռ�����
	SysTick->CTRL=0x01;          //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL=0x00;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	  	    
} 

			 



























