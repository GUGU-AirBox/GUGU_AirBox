/***************************************************************************
* �ļ���          : GPIO.h
* ����            : MCU GPIO����
* �汾��          : v1.0
* ����            : ����
* ����            : 2019��10��26��13:04:54
* ������־        :
* ����         �汾      ����                ��������
* 2019/10/26   v0.1      ����                ����ļ�
***************************************************************************/

#ifndef _GPIO_CONFIG_H_
#define _GPIO_CONFIG_H_

#include <iostm8s103f3.h>

//WIFI״ָ̬ʾ�� ʹ��PA3 ����
#define WIFI_LED_ODR PA_ODR_ODR3
#define WIFI_LED_DDR PA_DDR_DDR3
#define WIFI_LED_CR1 PA_CR1_C13
#define WIFI_LED_CR2 PA_CR2_C23

//�ú�ķ�ʽ���溯��ʵ��
#define WIFI_LED_ON()  WIFI_LED_ODR = 0
#define WIFI_LED_OFF() WIFI_LED_ODR = 1

void GPIO_Init();               //ULED IO ��ʼ��


#endif