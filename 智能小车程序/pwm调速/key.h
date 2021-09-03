#ifndef  __key_h_
#define  __key_h_

#include "common.h"

extern int x;
extern int y;

sbit zuo_Key_add=P2^1; //��������
sbit zuo_Key_dec=P2^3; //��������
sbit you_Key_add=P2^2; //�ҵ������
sbit you_Key_dec=P2^0; //�ҵ������

void zuo_speed_high(void);
void zuo_speed_low(void);
void you_speed_high(void);
void you_speed_low(void);

#endif