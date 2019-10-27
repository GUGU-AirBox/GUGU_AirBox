/***************************************************************************
* �ļ���          : SHT20.h
* ����            : SHT20��ʪ�ȴ�������װ
* �汾��          : v0.1
* ����            : ����
* ����            : 2019/10/27
* ������־        :
* ����         �汾      ����                ��������
* 2019/10/27    v0.1     ����                ��SHT20��ʪ�ȴ�������ع��ܽ��з�װ
***************************************************************************/

#ifndef _SHT20_H_
#define _SHT20_H_

#include "IIC.h"

// �Ĵ�����ַ����
#define SHT20_WRITE_ADDR        0x80    //д��ַ
#define SHT20_READ_ADDR         0x81    //����ַ
#define SHT20_MEASURE_RH_HM     0XE5    //����ģʽ��ȡʪ��
#define SHT20_MEASURE_T_HM      0XE3    //����ģʽ��ȡ�¶�
#define SHT20_MEASURE_RH_NHM    0XF5    //������ģʽ��ʪ��
#define SHT20_MEASURE_T_NHM     0XF3    //������ģʽ���¶�
#define SHT20_READ_REG          0XE7
#define SHT20_WRITE_REG         0XE6
#define SHT20_SOFT_RESET        0XFE    //������

#define CRC8_POLYNOMIAL         0x131   //CRC8�Ķ���ʽ
void SHT20_Init();
void SHT20_ReadHuniAndTemprature(unsigned short* _outT, unsigned short* _outRH);

#endif