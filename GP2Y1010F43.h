/***************************************************************************
* �ļ���          : GP2Y1010F43.h
* ����            : ����GP2Y1010F43 �����ﴫ����
* �汾��          : v0.1
* ����            : ����
* ����            : 2019-11-3
* ������־        :
* ����         �汾      ����                ��������
* 2019/11/3    v0.1      ����                ����
***************************************************************************/

#ifndef _SHARP_GP2Y_
#define _SHARP_GP2Y_

#include <iostm8s103f3.h>

//�����ﴫ���� ADC�ɼ�ͨ������ PD2
#define PM25VO_IDR PD_IDR_DDR2
#define PM25VO_CR1 PD_CR1_C12
#define PM25VO_CR2 PD_CR2_C22
#define PM25VO_DDR PD_DDR_DDR2

//�����ﴫ���� LED���� PIN PA2
#define PM25LED_ODR PA_ODR_ODR2
#define PM25LED_DDR PA_DDR_DDR2
#define PM25LED_CR1 PA_CR1_C12
#define PM25LED_CR2 PA_CR2_C22

//�����ﴫ���� ADCͨ�� PD2 AIN3
#define PM25_ADC_CHANEL 0x03
#define ADCSAMPLETIMES 5

//�����ﴫ���� ��������ܿ���
#define PM25_LED_ON()   PM25LED_ODR = 0
#define PM25_LED_OFF()  PM25LED_ODR = 1

void PM25_Init();
void PM25_Read(unsigned int* _out_val);

#endif
