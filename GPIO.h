/***************************************************************************
* 文件名          : GPIO.h
* 概括            : MCU GPIO定义
* 版本号          : v1.0
* 作者            : 兰州
* 日期            : 2019年10月26日13:04:54
* 更改日志        :
* 日期         版本      作者                更改内容
* 2019/10/26   v0.1      兰州                添加文件
***************************************************************************/

#ifndef _GPIO_CONFIG_H_
#define _GPIO_CONFIG_H_

#include <iostm8s103f3.h>

//WIFI状态指示灯 使用PA3 引脚
#define WIFI_LED_ODR PA_ODR_ODR3
#define WIFI_LED_DDR PA_DDR_DDR3
#define WIFI_LED_CR1 PA_CR1_C13
#define WIFI_LED_CR2 PA_CR2_C23

//用宏的方式代替函数实现
#define WIFI_LED_ON()  WIFI_LED_ODR = 0
#define WIFI_LED_OFF() WIFI_LED_ODR = 1

void GPIO_Init();               //ULED IO 初始化


#endif