/***************************************************************************
* 文件名          : WS2812b.h
* 概括            : WS2812b 5050RGB LED驱动
* 版本号          : v0.1
* 作者            : 兰州
* 日期            : 2019/11/17
* 更改日志        :
* 日期         版本      作者                更改内容
* 2019/11/17    v0.1     兰州              创建内容
***************************************************************************/

#ifndef _WS2812B_
#define _WS2812B_

#include <iostm8s103f3.h>

//WS2812b PIN PD4
#define WS2812_ODR PD_ODR_ODR4
#define WS2812_DDR PD_DDR_DDR4
#define WS2812_CR1 PD_CR1_C14
#define WS2812_CR2 PD_CR2_C24

#define WS2812_High() WS2812_ODR = 1
#define WS2812_Low() WS2812_ODR = 0

void WS2812b_Init(void);                   //初始化引脚
void SetRGB(unsigned char nums, unsigned char* R, unsigned char* G, unsigned char* B);          //设置颜色

void T0H();
void T0L();
void T1H();
void T1L();
void RES();

#endif