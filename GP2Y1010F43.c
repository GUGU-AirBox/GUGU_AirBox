/***************************************************************************
* 文件名          : GP2Y1010F43.c
* 概括            : 夏普GP2Y1010F43 颗粒物传感器
* 版本号          : v0.1
* 作者            : 兰州
* 日期            : 2019-11-3
* 更改日志        :
* 日期         版本      作者                更改内容
* 2019/11/3    v0.1      兰州                初稿
***************************************************************************/

#include "GP2Y1010F43.h"
#include "Delay.h"

void PM25_Init()
{
  //ADC1 AIN3 PD2 悬浮输入
  PM25VO_DDR = 0;
  PM25VO_CR1 = 0;
  PM25VO_CR2 = 0;
  
  //LEDPIN PA1 推挽输出
  PM25LED_DDR = 1; 
  PM25LED_CR1 = 1; 
  PM25LED_CR2 = 0;
  PM25_LED_OFF(); //默认关闭
  
  //ADC参数配置
  ADC_CR1 = 0x00;  //ADC时钟，单次转换，关闭ADC
  ADC_CR2 |= 0x08; //右对齐模式，其他保持默认
}
void PM25_Read(unsigned int* _out_val)
{
  PM25_LED_ON(); //开启LED电源
  ADC_CSR = PM25_ADC_CHANEL;  //选择通道
  unsigned char ADC_H,ADC_L;  
  unsigned int res = 0;   
  for(unsigned char i = 0; i < ADCSAMPLETIMES; i++)
  {
    ADC_CR1 |= 0x01;  //启动ADC 启动ADC电源  
    delay_ms(50);      //延时 等待ADC启动  
    ADC_CR1 |= 0x01;  //再次启动ADC转换  
    while((ADC_CSR&0x80) == 0); //等待ADC转换结束  
    ADC_H = ADC_DRH;  //左对齐 先读高八位  
    ADC_L = ADC_DRL;  //读取低位值  
    res += ((ADC_H << 8) + ADC_L); //两个八位数据合并成一个16位数据  
  }
  *_out_val = res / ADCSAMPLETIMES;
  PM25_LED_OFF(); //关闭LED电源
}