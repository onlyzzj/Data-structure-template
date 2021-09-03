#include "math.h"
	
	
	
float Gyro_angle_x,Gyro_angle_y,Gyro_angle_z;
float Gyro_radian_x,Gyro_radian_y,Gyro_radian_z;
float Acc_gram_x,Acc_gram_y,Acc_gram_z;
float Acc_speed_x,Acc_speed_y,Acc_speed_z;
float Mag_gauss_x,Mag_gauss_y,Mag_gauss_z;





//������������16λADCֵתΪ��/ÿ�� 
void MPU6050_Gyro_Angle(s16 gyro_x,s16 gyro_y,s16 gyro_z)
{
	Gyro_angle_x=((float)gyro_x)/MPU6050_Gyro_angle_2000;
	Gyro_angle_y=((float)gyro_y)/MPU6050_Gyro_angle_2000;
	Gyro_angle_z=((float)gyro_z)/MPU6050_Gyro_angle_2000;
}





//�����������ɶ�/ÿ��תΪ����/ÿ�� 
void MPU6050_Gyro_Radian(float angle_x,float angle_y,float angle_z)
{
	Gyro_radian_x=angle_x*180/3.141592f;
	Gyro_radian_y=angle_y*180/3.141592f;
	Gyro_radian_z=angle_z*180/3.141592f;
}






//���ٶȼ�������16λADCֵתΪg 
void MPU6050_Acc_Gram(s16 acc_x,s16 acc_y,s16 acc_z)
{
	Acc_gram_x=((float)acc_x)/MPU6050_Acc_Gram_8;
	Acc_gram_y=((float)acc_y)/MPU6050_Acc_Gram_8;
	Acc_gram_z=((float)acc_z)/MPU6050_Acc_Gram_8;
}



//���ٶȼ�������gתΪm/s^2 
void MPU6050_Acc_Speed(float gram_x,float gram_y,float gram_z)
{
	Acc_speed_x=gram_x*9.8f;
	Acc_speed_y=gram_y*9.8f;
	Acc_speed_z=gram_z*9.8f;
}




//������������12λADCֵתΪ��˹
void HMC5883L_Mag_Gauss(s16 mag_x,s16 mag_y,s16 mag_z)
{
	Mag_gauss_x=((float)mag_x)/HMC5883L_Mag_Gauss_13;
	Mag_gauss_y=((float)mag_y)/HMC5883L_Mag_Gauss_13;
	Mag_gauss_z=((float)mag_z)/HMC5883L_Mag_Gauss_13;
}





/*******************************************************************************
���ټ��� 1/Sqrt(x)��Դ������3��һ�δ��룬�����0x5f3759df���������Ĵ����4�� 	
*******************************************************************************/
float invSqrt(float x) 
{
	float halfx = 0.5f * x;
	float y = x;
	long i = *(long*)&y;
	i = 0x5f3759df - (i>>1);
	y = *(float*)&i;
	y = y * (1.5f - (halfx * y * y));
	return y;
}



