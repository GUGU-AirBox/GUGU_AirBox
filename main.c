#include <iostm8s103f3.h>
#include "GPIO.h"
#include "UART.h"
#include "ADC.h"
#include "TIM2_Delay.h"
#include "SHT20.h"
#include "GP2Y1010F43.h"
#include "WS2812b.h"

void main( void )
{
  CLK_CKDIVR = 0x00;     //时钟设置 0分频 主频 16Mhz
  
  asm("sim");//关中断  

  TIM2_Init();
  GPIO_Init();
  UART1_Init();
  ADC_Init();
  SHT20_Init();
  PM25_Init();
  WS2812b_Init();

  asm("rim");//开中断

  unsigned int          temp = 0; // VOC值
  unsigned short        t = 0; 
  unsigned short        rh = 0;
  unsigned int          pm25 = 0;
  
  while(1)
  {
//    ADC_Read(&temp);
//    SHT20_ReadHuniAndTemprature(&t,&rh);
//    PM25_Read(&pm25);
//    UART1_SendChar((unsigned char)(temp >> 8));
//    UART1_SendChar((unsigned char)(temp));
//    UART1_SendChar((unsigned char)(t >> 8));
//    UART1_SendChar((unsigned char)(t));
//    UART1_SendChar((unsigned char)(rh >> 8));
//    UART1_SendChar((unsigned char)(rh));
//    UART1_SendChar((unsigned char)(pm25 >> 8));
//    UART1_SendChar((unsigned char)(pm25));
    T0H();
    DelayMs(1000);
  }
}
