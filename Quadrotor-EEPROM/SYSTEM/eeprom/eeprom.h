#ifndef __EEPROM_H
#define __EEPROM_H
#include "stm32f4xx.h" 





#define  AT24C02_ADDRESS		0xA0                                     //A0��A1��A2���ӵ�




					  
u8 AT24C02_Read_1Byte(u8 BYTE_ADDRESS);						                   //��ָ����ַ��ȡ1���ֽڵ�����
void AT24C02_Write_1Byte(u8 BYTE_ADDRESS,u8 DATA);		               //��ָ����ַд��1���ֽڵ�����
void AT24C02_Read_nByte(u8 BYTE_ADDRESS,u8 *temp,u8 n);              //��ָ����ַ��ʼд��n���ֽڵ�����
void AT24C02_Write_nByte(u8 BYTE_ADDRESS,u8 *temp,u8 n);  	         //��ָ����ַ��ʼ����n���ֽڵ�����
u16 AT24C02_Read_16Bit(u8 BYTE_ADDRESS);                             //ָ����ַ��ʼ��������Ϊ16bit������
void AT24C02_Write_16Bit(u8 BYTE_ADDRESS,u16 DATA);                  //ָ����ַ��ʼд�볤��Ϊ16bit������
u32 AT24C02_Read_32Bit(u8 BYTE_ADDRESS);                             //ָ����ַ��ʼ��������Ϊ32bit������
void AT24C02_Write_32Bit(u8 BYTE_ADDRESS,u32 DATA);                  //ָ����ַ��ʼд�볤��Ϊ32bit������
u8 AT24C02_Check(void);                                              //�������








#endif
















