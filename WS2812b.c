/***************************************************************************
* 文件名          : WS2812b.c
* 概括            : WS2812b 5050RGB LED驱动
* 版本号          : v0.1
* 作者            : 兰州
* 日期            : 2019/11/17
* 更改日志        :
* 日期         版本      作者                更改内容
* 2019/11/17    v0.1     兰州              创建内容
***************************************************************************/

#include "WS2812b.h"
#include "TIM2_Delay.h"

void WS2812b_Init(void)
{
  WS2812_DDR = 1;
  WS2812_CR1 = 1;     //推挽输出
  WS2812_CR2 = 1;     //高速模式
  WS2812_ODR = 0;     //先别输出
}


#define _nop_() asm("nop")
 
#define delay1NOP()	_nop_();
#define delay2NOP()	delay1NOP();_nop_();
#define delay3NOP()	delay2NOP();_nop_();
#define	delay4NOP()	delay3NOP();_nop_();
#define	delay5NOP()	delay4NOP();_nop_();
#define	delay6NOP()	delay5NOP();_nop_();
#define	delay7NOP()	delay6NOP();_nop_();
#define	delay8NOP()	delay7NOP();_nop_();
#define	delay9NOP()	delay8NOP();_nop_();
#define	delay10NOP()	delay9NOP();_nop_();
#define	delay11NOP()	delay10NOP();_nop_();
#define	delay12NOP()	delay11NOP();_nop_();
#define	delay13NOP()	delay12NOP();_nop_();
#define	delay14NOP()	delay13NOP();_nop_();
#define	delay15NOP()	delay14NOP();_nop_();


#define PIN_H() WS2812_ODR = 1
#define PIN_L() WS2812_ODR = 0


typedef unsigned char u8;
typedef unsigned int u32;

static void outPut(u8* color, short len){
  while(1)
  {
    if(--len >= 0x0){
      if(color[len] & 0x80){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x40){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x20){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x10){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x08){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x04){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x02){
       PIN_H();delay11NOP();
       PIN_L();delay1NOP();
      }else{
       PIN_H();delay1NOP();
       PIN_L();delay11NOP();
      }
      if(color[len] & 0x01){
       PIN_H();delay11NOP();
       PIN_L();
      }else{
       PIN_H();delay1NOP();
       PIN_L();
      }
    }
    else{
      break;
    }
  }
}

//0码高电平时间 0.4μs ±150ns
void T0H(){
  u8 size = 24 * 3;
  u8 color[24*3] = {0};
  u8 i = 0;
  u8 j = 0;
  u8 k = 0;
  u8 l = 0;
  for(; i < 255; i+=20)
  {
    for(; j < 255; j+=20)
    {
      for(; k < 255; k+=20)
      {
        for(; l < size; l+=3)
        {
          color[l] = i;
          color[l+1] = j;
          color[l+2] = k;
        }
        outPut(color,size);
        DelayMs(10);
      }
    }
  }
  
}


//0码低电平时间 0.85μs ±150ns
void T0L(){
  PD_ODR_ODR4 = 0;
  PD_ODR_ODR4 = 0;
}

//1码高电平时间 0.85μs ±150ns
void T1H();

//1码高电平时间 0.4μs ±150ns
void T1L();

//帧单位， 低电平时间50μs以上
void RES();

