#ifndef __xunji_h__
#define __xunji_h__

#include "common.h"
#include"delay.h"
#include "nRF24L01_RX.h"
#include"qudong.h"

//����Ѱ��̽ͷ,���������
//��⵽�˺��߷��ص͵�ƽ,��Ӧָʾ����
sbit HW1=P1^0;//��һ��̽ͷ
sbit HW2=P1^1;//�ڶ���̽ͷ
sbit HW3=P1^2;//������̽ͷ
sbit HW4=P1^3;//���ĸ�̽ͷ


void xunji(void);

#endif