#include "dma-adc.h"


u16 ADC_Buffer[1];	//���ADCת��������12bitԭʼ����




void ADC1_CH5_Config(void)
{
	GPIO_InitTypeDef        GPIO_InitStructure;
	ADC_InitTypeDef         ADC_InitStructure;
	ADC_CommonInitTypeDef   ADC_CommonInitStructure;


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);   //ʹ��GPIOAʱ�� 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);    //ʹ��ADC1ʱ��


	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&GPIO_InitStructure);


	ADC_CommonInitStructure.ADC_Mode=ADC_Mode_Independent;                    //����ģʽ
	ADC_CommonInitStructure.ADC_Prescaler=ADC_Prescaler_Div4;                 //4��Ƶ���ʹADC��ʱ��Ƶ�ʵ���36M
	ADC_CommonInitStructure.ADC_DMAAccessMode=ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay=ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);



	ADC_InitStructure.ADC_Resolution=ADC_Resolution_12b;                      //12λת����ʽ
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;                               //��ɨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode=ENABLE;                          //����ģʽ 
	ADC_InitStructure.ADC_ExternalTrigConvEdge=ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion=1;                                  //��ͨ��ת��ʱӦ�޸Ĵ˴�
	ADC_Init(ADC1,&ADC_InitStructure);



	ADC_RegularChannelConfig(ADC1,ADC_Channel_5,1,ADC_SampleTime_3Cycles);   //����ADC����ͨ������
	ADC_DMARequestAfterLastTransferCmd(ADC1,ENABLE);                         //ADCת����ɺ�������//��DMA����
	ADC_DMACmd(ADC1,ENABLE);                                                  /* Enable ADC3 DMA */
	ADC_Cmd(ADC1,ENABLE);                                                     /* Enable ADC3 */
	ADC_SoftwareStartConv(ADC1);                                              //�������ת��
}









 
void DMA2_CH0_STREAM0_Config(void)
{
	DMA_InitTypeDef    DMA_InitStructure;


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);                       //DMA2ʱ��ʹ��



	DMA_InitStructure.DMA_Channel=DMA_Channel_0;
	DMA_InitStructure.DMA_PeripheralBaseAddr=(u32)&ADC1->DR;
	DMA_InitStructure.DMA_Memory0BaseAddr=(u32)ADC_Buffer;
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralToMemory;                     //����DMA����Ϊ����//���ڴ�
	DMA_InitStructure.DMA_BufferSize=1;                                       //��ͨ������ʱ����Ҫ�޸�
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;            //�����ַ����
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Disable;                    //�����ַ����
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;         //���ַ�//ʽ
	DMA_InitStructure.DMA_Mode=DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority=DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode=DMA_FIFOMode_Disable;
	DMA_InitStructure.DMA_FIFOThreshold=DMA_FIFOThreshold_HalfFull;
	DMA_InitStructure.DMA_MemoryBurst=DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst=DMA_PeripheralBurst_Single;
	DMA_Init(DMA2_Stream0,&DMA_InitStructure);
	DMA_Cmd(DMA2_Stream0,ENABLE);
}
 






void ADC1_CH5_DMA2_CH0_STREAM0_Init(void)
{
	DMA2_CH0_STREAM0_Config();
	ADC1_CH5_Config();
}





