#include "pwm_out.h"

 
void TIM1_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 	     //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;    //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=10000-1;                     //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_Prescaler=42-1;                  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;               //�ظ��Ĵ����������Զ�����pwmռ�ձ�
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);               //��ʼ����ʱ��1
	
	
	
	

	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;                 //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;     //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;         //�������:TIM����Ƚϼ��Ե�
	TIM_OCInitStructure.TIM_Pulse=INIT_DUTY;                             //���ô�װ�벶��ȽϼĴ���������ֵ
	//���漸�������Ǹ߼���ʱ���Ż��õ���ͨ�ö�ʱ����������
  TIM_OCInitStructure.TIM_OCNPolarity=TIM_OCNPolarity_Low;          //���û������������
	TIM_OCInitStructure.TIM_OutputNState=TIM_OutputNState_Disable;     //ʹ�ܻ��������
	TIM_OCInitStructure.TIM_OCIdleState=TIM_OCIdleState_Set;          //���������״̬
	TIM_OCInitStructure.TIM_OCNIdleState=TIM_OCNIdleState_Reset;      //�����󻥲������״̬


  //PWM1ģʽ���ã�ͨ��1
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);                 //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
	//PWM1ģʽ���ã�ͨ��2
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);
	//PWM1ģʽ���ã�ͨ��3
	TIM_OC3Init(TIM1,&TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM1,TIM_OCPreload_Enable);
	//PWM1ģʽ���ã�ͨ��4
	TIM_OC4Init(TIM1,&TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);


                
 
	TIM_CtrlPWMOutputs(TIM1,ENABLE);                                 //�߼���ʱ������Ҫд
  TIM_ARRPreloadConfig(TIM1,ENABLE); 
	TIM_Cmd(TIM1,ENABLE);
}
 




void PWM_Out_Init(void)
{		 					 	
	GPIO_InitTypeDef GPIO_InitStructure;
		  
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE); 	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14;           
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                    //���ù���
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;	            //�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;                  //���츴�����
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;                    //����
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_TIM1);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1); 
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_TIM1);
  GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_TIM1);
	
	TIM1_Init();	
}  







//PWMд����
void MOTOR_Run(s16 pwm[MOTOR_Num])
{		
	u8 i;
	for(i=0;i<MOTOR_Num;i++)
	{
		if(pwm[i]>MOTOR_Max)  
			pwm[i]=MOTOR_Max;		
		else if(pwm[i]<MOTOR_Min)  
			pwm[i]=MOTOR_Min;
	}
	TIM1->CCR1=INIT_DUTY+pwm[0]*PWM_RADIO;
	TIM1->CCR2=INIT_DUTY+pwm[1]*PWM_RADIO;
	TIM1->CCR3=INIT_DUTY+pwm[2]*PWM_RADIO;
	TIM1->CCR4=INIT_DUTY+pwm[3]*PWM_RADIO;
}



void MOTOR_Stop(void)
{
	TIM1->CCR1=INIT_DUTY;
	TIM1->CCR2=INIT_DUTY;
	TIM1->CCR3=6000;
//	TIM1->CCR4=INIT_DUTY;
	TIM1->CCR4=9999;
}
