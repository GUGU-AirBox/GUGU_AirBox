/***************************************************************************
* 文件名          : ADC.c
* 概括            : ADC配置及读值相关函数 
* 版本号          : v1.0
* 作者            : 兰州
* 日期            : 2018/4/12
* 更改日志        :
* 日期         版本      作者                更改内容
* 2018/4/10    v0.1      兰州              添加文件、实现相关功能
* 2018/4/12    v1.0      兰州              代码、注释整理 初定
***************************************************************************/

#include "ADC.h"

/***************************************************************************
* 函数名          : ADC_Init
* 功能            : ADC、ADC通道引脚初始化
* 输入参数        : 无
* 输出            : 无
* 日期&作者       : 2018/4/10 由 兰州 创建
***************************************************************************/
void ADC_Init()
{
  //ADC输入脚 悬浮输入
  ADCPIN_DDR = 0;
  ADCPIN_CR1 = 0;
  ADCPIN_CR2 = 0;
  
  //ADC参数配置
  ADC_CR1 = 0x00;  //ADC时钟，单次转换，关闭ADC
  ADC_CR2 |= 0x08; //右对齐模式，其他保持默认
}

/***************************************************************************
* 函数名          : ADC_Read
* 功能            : 从ADC相关寄存器读取AD转换的结果
* 输入参数        : 参数1：unsigned int* buf ，2Byte大小，用来保存AD转换的值
* 输出            : 无
* 日期&作者       : 2018/4/10 由 兰州 创建
***************************************************************************/
void ADC_Read(unsigned int* buf)
{
  ADC_CSR = ADCCHANEL;  //选择通道
  unsigned int DELAY_TIMES = 50;
  unsigned char ADC_H,ADC_L;  
  unsigned int res = 0;   
  for(unsigned char i = 0; i < ADCSAMPLETIMES; i++)
  {
    ADC_CR1 |= 0x01;  //启动ADC 启动ADC电源  
    while(DELAY_TIMES--){asm("nop");}      //延时 等待ADC启动  
    ADC_CR1 |= 0x01;  //再次启动ADC转换  
    while((ADC_CSR&0x80) == 0); //等待ADC转换结束  
    ADC_H = ADC_DRH;  //左对齐 先读高八位  
    ADC_L = ADC_DRL;  //读取低位值  
    res += ((ADC_H << 8) + ADC_L); //两个八位数据合并成一个16位数据  
  }
  *buf = res / ADCSAMPLETIMES;
}
