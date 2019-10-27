#include <iostm8s103f3.h>
#include "GPIO.h"
#include "UART.h"
#include "ADC.h"
#include "Delay.h"
#include "SHT20.h"

void main( void )
{
  CLK_CKDIVR = 0x00;     //时钟设置 0分频 主频 16Mhz
  delay_init(16);
  
  asm("sim");//关中断  

  GPIO_Init();
  UART1_Init();
  ADC_Init();
  SHT20_Init();

  asm("rim");//开中断

  unsigned int temp = 0; // VOC值
  unsigned short t = 0; 
  unsigned short rh = 0;
  
  while(1)
  {
    ADC_Read(&temp);
    SHT20_ReadHuniAndTemprature(&t,&rh);
    //printf("VOC:%d T:%.2f RH:.2f%",temp,t/100.0,rh/100.0);
    delay_ms(820);
  }
}
