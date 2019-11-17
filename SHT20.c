#include "SHT20.h"
#include "TIM2_Delay.h"

/***************************************************************************
* ������          : SHT20_Init
* ����            : SHT20��ʼ��������IIC��ʼ����SHT20�ĳ�ʼ�趨
* �������        : ��
* ���            : ��
* ����&����       : 2019/10/27 �� ���� ����
***************************************************************************/
void SHT20_Init()
{
  IIC_Init();
}

/***************************************************************************
* ������          : CRC_Check
* ����            : CRC���㣬���Ԫ���������ݵ���ȷ��
* �������        : unsigned char* data     ����
                    unsigned int length     ���ݳ���
                    unsigned char checkSum  У��ֵ
* ���            : ��
* ����&����       : 2019/10/27 �� ���� ����
***************************************************************************/
unsigned char CRC_Check(unsigned char* data, unsigned int length, unsigned char checkSum)
{
  unsigned char tmp = 0;
  unsigned char bit = 0;
  unsigned char i =0;
  for(i = 0; i < length; ++i)
  {
    tmp ^= (data[i]);
    for(bit = 0; bit > 0; --bit)
    {
      if(tmp & 0x80) tmp = ( tmp << 1) ^ CRC8_POLYNOMIAL;
      else tmp = (tmp << 1);
    }
  }
  
  if(tmp != checkSum) return 1;
  else return 0;
}

void SHT20_ReadHuniAndTemprature(unsigned short* _outT, unsigned short* _outRH)
{
  unsigned char checkSum = 0;   // У��ֵ
  unsigned char buf[2];         // buffer
  unsigned short tmp = 0;       // �ݴ�
  
  // ���¶�����
  IIC_Read(SHT20_WRITE_ADDR,SHT20_MEASURE_T_HM,buf,2);
  tmp = ((buf[0] << 8) + buf[1]) & ~0x0003; //ƴ��Ϊ�¶����ݲ�ȥ��ȥ��bit0 bit1��״̬λ
  *_outT = (unsigned short)((-46.85 + 175.72 / 65536 * (float)tmp) * 100); //����ȥΪԭ���� * 100 ȥ��С��λ
  
  DelayMs(50);
  
  // ��ʪ������
  IIC_Read(SHT20_WRITE_ADDR,SHT20_MEASURE_RH_HM,buf,2);
  tmp = ((buf[0] << 8) + buf[1]) & ~0x0003; //ƴ��Ϊ�¶����ݲ�ȥ��ȥ��bit0 bit1��״̬λ
  *_outRH = (unsigned short)((((float)tmp * 0.00190735) - 6) * 100); //����ȥΪԭ���� * 100 ȥ��С��λ
}
