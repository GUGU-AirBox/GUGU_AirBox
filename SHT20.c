#include "SHT20.h"
#include "TIM2_Delay.h"

/***************************************************************************
* 函数名          : SHT20_Init
* 功能            : SHT20初始化，包括IIC初始化和SHT20的初始设定
* 输入参数        : 无
* 输出            : 无
* 日期&作者       : 2019/10/27 由 兰州 创建
***************************************************************************/
void SHT20_Init()
{
  IIC_Init();
}

/***************************************************************************
* 函数名          : CRC_Check
* 功能            : CRC计算，检查元件返回数据的正确性
* 输入参数        : unsigned char* data     数据
                    unsigned int length     数据长度
                    unsigned char checkSum  校验值
* 输出            : 无
* 日期&作者       : 2019/10/27 由 兰州 创建
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
  unsigned char checkSum = 0;   // 校验值
  unsigned char buf[2];         // buffer
  unsigned short tmp = 0;       // 暂存
  
  // 读温度数据
  IIC_Read(SHT20_WRITE_ADDR,SHT20_MEASURE_T_HM,buf,2);
  tmp = ((buf[0] << 8) + buf[1]) & ~0x0003; //拼合为温度数据并去掉去掉bit0 bit1的状态位
  *_outT = (unsigned short)((-46.85 + 175.72 / 65536 * (float)tmp) * 100); //穿出去为原数据 * 100 去掉小数位
  
  DelayMs(50);
  
  // 读湿度数据
  IIC_Read(SHT20_WRITE_ADDR,SHT20_MEASURE_RH_HM,buf,2);
  tmp = ((buf[0] << 8) + buf[1]) & ~0x0003; //拼合为温度数据并去掉去掉bit0 bit1的状态位
  *_outRH = (unsigned short)((((float)tmp * 0.00190735) - 6) * 100); //穿出去为原数据 * 100 去掉小数位
}
