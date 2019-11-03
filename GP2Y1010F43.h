/***************************************************************************
* 文件名          : GP2Y1010F43.h
* 概括            : 夏普GP2Y1010F43 颗粒物传感器
* 版本号          : v0.1
* 作者            : 兰州
* 日期            : 2019-11-3
* 更改日志        :
* 日期         版本      作者                更改内容
* 2019/11/3    v0.1      兰州                初稿
***************************************************************************/

#ifndef _SHARP_GP2Y_
#define _SHARP_GP2Y_

#include <iostm8s103f3.h>

//颗粒物传感器 ADC采集通道定义 PD2
#define PM25VO_IDR PD_IDR_DDR2
#define PM25VO_CR1 PD_CR1_C12
#define PM25VO_CR2 PD_CR2_C22
#define PM25VO_DDR PD_DDR_DDR2

//颗粒物传感器 LED开关 PIN PA2
#define PM25LED_ODR PA_ODR_ODR2
#define PM25LED_DDR PA_DDR_DDR2
#define PM25LED_CR1 PA_CR1_C12
#define PM25LED_CR2 PA_CR2_C22

//颗粒物传感器 ADC通道 PD2 AIN3
#define PM25_ADC_CHANEL 0x03
#define ADCSAMPLETIMES 5

//颗粒物传感器 发光二极管开关
#define PM25_LED_ON()   PM25LED_ODR = 0
#define PM25_LED_OFF()  PM25LED_ODR = 1

void PM25_Init();
void PM25_Read(unsigned int* _out_val);

#endif
