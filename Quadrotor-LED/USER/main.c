#include "delay.h"
#include "led.h"



int main(void)
{  
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	while(1)
	{
		LED1_ON;
		LED2_OFF;
		delay_ms(500);
		LED1_OFF;
		LED2_ON;
		delay_ms(500);
	}
}
