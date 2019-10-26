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

//WIFI״ָ̬ʾ�� ʹ��PB5 ����
#define WIFI_LED_ODR PB_ODR_ODR5
#define WIFI_LED_DDR PB_DDR_DDR5
#define WIFI_LED_CR1 PB_CR1_C15
#define WIFI_LED_CR2 PB_CR2_C25

//�ú�ķ�ʽ���溯��ʵ��
#define WIFI_LED_ON()  WIFI_LED_ODR = 0
#define WIFI_LED_OFF() WIFI_LED_ODR = 1

void GPIO_Init();               //ULED IO ��ʼ��


#endif