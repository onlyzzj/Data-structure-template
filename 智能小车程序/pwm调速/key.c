#include"key.h"
#include"delay.h"

int x=0;
int y=0;

void zuo_speed_low(void)//��������ռ�ձȣ���������
{
	if(zuo_Key_dec==0)
	{
		delayms(10);
		if(zuo_Key_dec==0)
		{	
			while(!zuo_Key_dec);//�ȴ����ɿ�
	    	x=x+5;
	   		if(x>=100)
	    	{
	     		x=100;
	    	} 
	   	}
	}
}


void zuo_speed_high(void)//��������ռ�ձȣ���������
{
	if(zuo_Key_add==0)
	{
	   	delayms(10);
	   	if(zuo_Key_add==0)
	   	{	
			while(!zuo_Key_add);//�ȴ����ɿ�
	    	x=x-5;
	   		if(x<=0)
	    	{
	     		x=0;
	    	} 
	   	}
	} 
}


void you_speed_low(void)//��������ռ�ձȣ��ҵ������
{
	if(you_Key_dec==0)
	{
		delayms(10);
		if(you_Key_dec==0)
		{	
			while(!you_Key_dec);//�ȴ����ɿ�
	    	y=y+5;
	   		if(y>=100)
	    	{
	     		y=100;
	    	} 
	   	}
	}
}

void you_speed_high(void)//��������ռ�ձȣ��ҵ������
{
	if(you_Key_add==0)
	{
	   	delayms(10);
	   	if(you_Key_add==0)
	   	{	
			while(!you_Key_add);//�ȴ����ɿ�
	    	y=y-5;
	   		if(y<=0)
	    	{
	     		y=0;
	    	} 
	   	}
	} 
}




