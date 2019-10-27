/***************************************************************************
* 文件名          : ADC.h
* 概括            : ADC配置及读值相关函数 
* 版本号          : v1.0
* 作者            : 兰州
* 日期            : 2018/4/12
* 更改日志        :
* 日期         版本      作者                更改内容
* 2018/4/10    v0.1      兰州              添加文件、实现相关功能
* 2018/4/12    v1.0      兰州              代码、注释整理 初定
***************************************************************************/

#ifndef _ADC_H_
#define _ADC_H_
#include <iostm8s103f3.h>

//ADC采集通道引脚配置
#define ADCPIN_IDR PC_IDR_DDR4
#define ADCPIN_CR1 PC_CR1_C14
#define ADCPIN_CR2 PC_CR2_C24
#define ADCPIN_DDR PC_DDR_DDR4

//ADC采样求平均次数
#define ADCSAMPLETIMES 5
//ADC通道 AN2 PC4
#define ADCCHANEL 0x02 

void ADC_Init();                        //ADC初始化
void ADC_Read(unsigned int* buf);       //从ADC读值

#endif