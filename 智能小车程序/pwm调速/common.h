#ifndef  __common_h_
#define  __common_h_

#include <reg52.h>
  
typedef  unsigned int uint;
typedef	 unsigned char uchar;


sbit EN1=P1^1;
sbit EN2=P1^2;
sbit in1=P0^0;    //iN1 iN2 Ϊ�ҵ��    //in1=0;in2=1;ǰת
sbit in2=P0^1;	  						
sbit in3=P0^2;    //iN3 iN4 Ϊ����	//in3=1;in4=0;ǰת
sbit in4=P0^3;


#endif