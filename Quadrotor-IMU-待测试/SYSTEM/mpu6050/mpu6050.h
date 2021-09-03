#ifndef _MPU6050_H_
#define _MPU6050_H_
#include "stm32f4xx.h"


//extern uint8_t	GYRO_Offset;	
//extern uint8_t	ACC_Offset;
//extern uint32_t I2C_Erro;



u8 MPU6050_Init(void);
void MPU6050_Data_Read(void);
void MPU6050_Offset(void);
void MPU6050_Data_Compose(void);



struct _acc
{
	int16_t x;
	int16_t y;
	int16_t z;
};
extern struct _acc acc;
extern struct _acc filter_acc;
extern struct _acc offset_acc;


struct _gyro
{
	int16_t x;
	int16_t y;
	int16_t z;
};
extern struct _gyro gyro;
extern struct _gyro filter_gyro;
extern struct _gyro offset_gyro;


#define MPU6050_ADDRESS      			  MPU6050_ADDRESS_AD0_LOW
#define MPU6050_ADDRESS_AD0_LOW     0xD0      //��AD0���Žӵ͵�ƽʱ     0xD0=0x68<<1
#define MPU6050_ADDRESS_AD0_HIGH    0xD2      //��AD0���ŽӸߵ�ƽʱ     0xD2=0x69<<1


#define SELF_TEST_X         0x0D        //X�Լ�Ĵ���
#define SELF_TEST_Y         0x0E        //Y�Լ�Ĵ���
#define SELF_TEST_Z         0x0F        //Z�Լ�Ĵ���
#define SELF_TEST_A         0x10        //A�Լ�Ĵ���
#define SMPLRT_DIV      	 	0x19        //����Ƶ�ʷ�Ƶ��
#define CONFIG           		0x1A        //���üĴ���
#define GYRO_CONFIG      		0x1B        //����������
#define ACCEL_CONFIG     		0x1C        //���ٶȼ�����
#define MOT_THR          		0x1F        //�˶������ֵ
#define FIFO_EN          		0x23        //FIFOʹ��
#define I2C_MST_CTRL     		0x24        //IIC��������
#define I2C_SLV0_ADDR    		0x25        //IIC�ӻ�0��ַ
#define I2C_SLV0_REG     		0x26        //IIC�ӻ�0�Ĵ���
#define I2C_SLV0_CTRL    		0x27        //IIC�ӻ�0����
#define I2C_SLV1_ADDR    		0x28        //IIC�ӻ�1��ַ
#define I2C_SLV1_REG     		0x29        //IIC�ӻ�1�Ĵ���
#define I2C_SLV1_CTRL    		0x2A        //IIC�ӻ�1����
#define I2C_SLV2_ADDR   	 	0x2B        //IIC�ӻ�2��ַ
#define I2C_SLV2_REG     		0x2C        //IIC�ӻ�2�Ĵ���
#define I2C_SLV2_CTRL    		0x2D        //IIC�ӻ�2����
#define I2C_SLV3_ADDR    		0x2E        //IIC�ӻ�3��ַ
#define I2C_SLV3_REG     		0x2F        //IIC�ӻ�3�Ĵ���
#define I2C_SLV3_CTRL    		0x30        //IIC�ӻ�3����
#define I2C_SLV4_ADDR    		0x31        //IIC�ӻ�4��ַ
#define I2C_SLV4_REG     		0x32        //IIC�ӻ�4�Ĵ���
#define I2C_SLV4_DO      		0x33
#define I2C_SLV4_CTRL    		0x34        //IIC�ӻ�4����
#define I2C_SLV4_DI      		0x35
#define I2C_MST_STATUS   		0x36        //IIC����״̬
#define INT_PIN_CFG      		0x37        //������·ʹ�����üĴ���
#define INT_ENABLE       		0x38        //�ж�ʹ�ܼĴ���
#define INT_STATUS       		0x3A        //�ж�״̬�Ĵ���
#define ACCEL_XOUT_H     		0x3B        //X����ٶȸ�λ
#define ACCEL_XOUT_L     		0x3C        //X����ٶȵ�λ
#define ACCEL_YOUT_H     		0x3D        //Y����ٶȸ�λ
#define ACCEL_YOUT_L     		0x3E        //Y����ٶȵ�λ
#define ACCEL_ZOUT_H    		0x3F        //Z����ٶȸ�λ
#define ACCEL_ZOUT_L     		0x40        //Z����ٶȸ�λ
#define TEMP_OUT_H       		0x41        //�¶Ȳ�����λ
#define TEMP_OUT_L       		0x42        //�¶Ȳ�����λ
#define GYRO_XOUT_H      		0x43        //X�������Ǹ�λ
#define GYRO_XOUT_L      		0x44        //X�������ǵ�λ
#define GYRO_YOUT_H      		0x45        //Y�������Ǹ�λ
#define GYRO_YOUT_L      		0x46        //Y�������ǵ�λ
#define GYRO_ZOUT_H      		0x47        //Z�������Ǹ�λ
#define GYRO_ZOUT_L      		0x48        //Z�������ǵ�λ
#define EXT_SENS_DATA_00 		0x49        //�ⲿ������0����
#define EXT_SENS_DATA_01 		0x4A        //�ⲿ������1����
#define EXT_SENS_DATA_02 		0x4B        //�ⲿ������1����
#define EXT_SENS_DATA_03 		0x4C        //�ⲿ������3����
#define EXT_SENS_DATA_04 		0x4D        //�ⲿ������4����
#define EXT_SENS_DATA_05 		0x4E        //�ⲿ������5����
#define EXT_SENS_DATA_06 		0x4F        //�ⲿ������6����
#define EXT_SENS_DATA_07 		0x50        //�ⲿ������7����
#define EXT_SENS_DATA_08 		0x51        //�ⲿ������8����
#define EXT_SENS_DATA_09 		0x52        //�ⲿ������9����
#define EXT_SENS_DATA_10 		0x53        //�ⲿ������10����
#define EXT_SENS_DATA_11 		0x54        //�ⲿ������11����
#define EXT_SENS_DATA_12 		0x55        //�ⲿ������12����
#define EXT_SENS_DATA_13 		0x56        //�ⲿ������13����
#define EXT_SENS_DATA_14 		0x57        //�ⲿ������14����
#define EXT_SENS_DATA_15 		0x58        //�ⲿ������15����
#define EXT_SENS_DATA_16 		0x59        //�ⲿ������16����
#define EXT_SENS_DATA_17 		0x5A        //�ⲿ������17����
#define EXT_SENS_DATA_18 		0x5B        //�ⲿ������18����
#define EXT_SENS_DATA_19 		0x5C        //�ⲿ������19����
#define EXT_SENS_DATA_20 		0x5D        //�ⲿ������20����
#define EXT_SENS_DATA_21 		0x5E        //�ⲿ������21����
#define EXT_SENS_DATA_22 		0x5F        //�ⲿ������22����
#define EXT_SENS_DATA_23 		0x60        //�ⲿ������23����
#define I2C_SLV0_DO      		0x63        //IIC�ӻ�0�������
#define I2C_SLV1_DO      		0x64        //IIC�ӻ�1�������
#define I2C_SLV2_DO      		0x65        //IIC�ӻ�2�������
#define I2C_SLV3_DO      		0x66        //IIC�ӻ�3�������
#define I2C_MST_DELAY_CTRL  0x67        //IIC������ʱ����   
#define SIGNAL_PATH_RESET   0x68        //�ź�ͨ����λ
#define MOT_DETECT_CTRL     0x69        //�˶�������
#define USER_CTRL        		0x6A        //�û�����
#define PWR_MGMT_1       		0x6B        //��Դ����1
#define PWR_MGMT_2       		0x6C        //��Դ����2
#define FIFO_COUNTH      		0x72        //FIFO�����Ĵ�����15:8��
#define FIFO_COUNTL      		0x73        //FIFO�����Ĵ�����7��0��
#define FIFO_R_W         		0x74        //FIFO��/д
#define WHO_AM_I         		0x75        //����˭





#endif

