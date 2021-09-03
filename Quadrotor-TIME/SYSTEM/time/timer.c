#include "timer.h"
#include "led.h"
#include "delay.h"



void TIM2_Init(void)//1ms����һ���ж�   1000*84/84M=0.001s
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);            //ʹ��TIM3ʱ��
	 
  TIM_TimeBaseInitStructure.TIM_Period=5000-1; 	                 //�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=8400-1;                  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;  //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);             //��ʼ��TIM3
	
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;                  //��ʱ��2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;     //��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;            //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);                       //����ʱ��3�����ж�
	TIM_Cmd(TIM2,ENABLE);                                          //ʹ�ܶ�ʱ��3
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);	
}



//��ʱ��2�жϷ�����
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)) //����ж�
	{
		LED1_ON;
		delay_ms(500);
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //����жϱ�־λ
	}
}
