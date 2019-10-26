#include <iostm8s103f3.h>
#include "GPIO.h"
#include "UART.h"
#include "ADC.h"

void Sleep(unsigned int times)
  {
    for(int i = 0; i < times * 1000; i++)
      asm("nop");
  }

void main( void )
{
  CLK_CKDIVR = 0x00;     //时钟设置 0分频 主频 16Mhz
  
  asm("sim");//关中断  
  GPIO_Init();
  UART1_Init();
  ADC_Init();
  
  asm("rim");//开中断

  unsigned int temp = 0; // VOC值
  
  while(1)
  {
    ADC_Read(&temp);
    printf("VOC:%d",temp);
    Sleep(50000);
  }
}
