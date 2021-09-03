#ifndef _IMU_H_
#define	_IMU_H_
#include "stm32f4xx.h"



#define Kp       2.0f      //��������            	
#define Ki       0.005f    //�������� 
#define halfT    0.0005f   //�������ڵ�һ��




extern float a_x,a_y,a_z,m_x,m_y,m_z;
extern float Roll,Pitch,Yaw;



void Data_Change(void);
void IMU_Init(void);
void IMU_Update(float acc_x,float acc_y,float acc_z,float gyro_x,float gyro_y,float gyro_z,float mag_x,float mag_y,float mag_z);





#endif


