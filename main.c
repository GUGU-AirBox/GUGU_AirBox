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
  CLK_CKDIVR = 0x00;     //ʱ������ 0��Ƶ ��Ƶ 16Mhz
  
  asm("sim");//���ж�  
  GPIO_Init();
  UART1_Init();
  ADC_Init();
  
  asm("rim");//���ж�

  unsigned int temp = 0; // VOCֵ
  
  while(1)
  {
    ADC_Read(&temp);
    printf("VOC:%d",temp);
    Sleep(50000);
  }
}
