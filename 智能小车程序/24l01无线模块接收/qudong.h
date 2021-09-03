#ifndef __qudong_h__
#define __qudong_h__

#include "common.h"
#include"delay.h"
#include "nRF24L01_RX.h"

sbit in1=P0^1;    //iN1 iN2 Ϊ�ҵ��    //in1=0;in2=1;ǰת
sbit in2=P0^0;	  						
sbit in3=P0^2;    //iN3 iN4 Ϊ����	//in3=1;in4=0;ǰת
sbit in4=P0^3;

void zhixian(void);
void stop(void);
void houtui(void);
void kuaizuozhuan(void);
void kuaiyouzhuan(void);
void manzuozhuan(void);
void manyouzhuan(void);
void qudong(void);


#endif