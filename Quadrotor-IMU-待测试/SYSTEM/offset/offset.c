#include "offset.h"
 
 
 Xmax=0.37
 Xmin=-0.57
Ymax=0.44
Ymin=-0.49
x_temp=1;
y_temp=(Xmax-Xmin)/(Ymax-Ymin);
MagX=(Xmax-Xmin)/2-Xmax;   
MagY=(Ymax-Ymin)/2-Ymax;



void SYSTICK_INIT(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);                //ʱ��ʹ��

	TIM_TimeBaseStructure.TIM_Period=0xffff;                           //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������5000Ϊ500ms
	TIM_TimeBaseStructure.TIM_Prescaler=84-1;                          //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  1Mhz�ļ���Ƶ��  
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;              //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;          //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);                     //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_Cmd(TIM4, ENABLE);
}


float GET_NOWTIME(void)//���ص�ǰsystick������ֵ,32λ
{
	float temp=0 ;
	static uint32_t now=0; // �������ڼ��� ��λ us

 	now=TIM4->CNT;//����16λʱ��
   	TIM4->CNT=0;
	temp=(float)now/2000000.0f;          //�����s���ٳ���2�ó��������ڵ�һ��

	return temp;
}