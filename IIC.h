/***************************************************************************
* �ļ���          : IIC.h
* ����            : Ӳ��IIC�ĳ�ʼ����������װ
* �汾��          : v1.0
* ����            : ����
* ����            : 2018/4/12
* ������־        :
* ����         �汾      ����                ��������
* 2018/4/11    v1.0      ����              Ӳ��IIC�ĳ�ʼ���ͳ�����װ
***************************************************************************/

#ifndef _IIC_H_
#define _IIC_H_

#include <iostm8s103f3.h>

void IIC_Init();
void IIC_Read(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num);
void IIC_Write(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num); 


#endif