#include "data_transfer.h"
#include "dma-adc.h"
#include "usart.h"	
#include "delay.h"



int main(void)
{  
	u32 temp;
	delay_init(168);
	USART1_Init(500000);	
	ADC1_CH5_DMA2_CH0_STREAM0_Init();
	while(1)
	{
		temp=ADC_Buffer[0]*3300/0xfff;         //�����temp��ʵ�ʵ�ѹ��1000��
		Send_Senser2(temp,0);
	}
}
