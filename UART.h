/***************************************************************************
* �ļ���          : UART.h
* ����            : UART�ĳ�ʼ��������������װ
* �汾��          : v0.1
* ����            : ����
* ����            : 2018/4/1
* ������־        :
* ����         �汾                  ��������
* 2018/4/1    v0.1                   ����ļ�
***************************************************************************/

#ifndef _UART_H_
#define _UART_H_

//#include <stdio.h>
#include <iostm8s103f3.h>

//������
#define BAUD_RATE 115200

void UART1_Init();                       //UART1��ʼ��
void UART1_SendChar(unsigned char c);   //���͵����ֽ�                                
void UART1_SendCharA(unsigned char* data , unsigned char length); //�����ֽ�����
void UART1_SendString(unsigned char* str);//�����ַ��� ���ַ�����'/0'��β

#endif