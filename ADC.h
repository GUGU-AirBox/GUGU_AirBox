/***************************************************************************
* �ļ���          : ADC.h
* ����            : ADC���ü���ֵ��غ��� 
* �汾��          : v1.0
* ����            : ����
* ����            : 2018/4/12
* ������־        :
* ����         �汾      ����                ��������
* 2018/4/10    v0.1      ����              ����ļ���ʵ����ع���
* 2018/4/12    v1.0      ����              ���롢ע������ ����
***************************************************************************/

#ifndef _ADC_H_
#define _ADC_H_
#include <iostm8s103f3.h>

//ADC�ɼ�ͨ����������
#define ADCPIN_IDR PC_IDR_DDR4
#define ADCPIN_CR1 PC_CR1_C14
#define ADCPIN_CR2 PC_CR2_C24
#define ADCPIN_DDR PC_DDR_DDR4

//ADC������ƽ������
#define ADCSAMPLETIMES 5
//ADCͨ�� AN2 PC4
#define ADCCHANEL 0x02 

void ADC_Init();                        //ADC��ʼ��
void ADC_Read(unsigned int* buf);       //��ADC��ֵ

#endif