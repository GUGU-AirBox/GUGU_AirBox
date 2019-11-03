#include <iostm8s103f3.h>
#include "GPIO.h"
#include "UART.h"
#include "ADC.h"
#include "Delay.h"
#include "SHT20.h"
#include "GP2Y1010F43.h"

void main( void )
{
  CLK_CKDIVR = 0x00;     //ʱ������ 0��Ƶ ��Ƶ 16Mhz
  delay_init(16);
  
  asm("sim");//���ж�  

  GPIO_Init();
  UART1_Init();
  ADC_Init();
  SHT20_Init();
  PM25_Init();

  asm("rim");//���ж�

  unsigned int          temp = 0; // VOCֵ
  unsigned short        t = 0; 
  unsigned short        rh = 0;
  unsigned int          pm25 = 0;
  
  while(1)
  {
    ADC_Read(&temp);
    SHT20_ReadHuniAndTemprature(&t,&rh);
    PM25_Read(&pm25);
    UART1_SendChar((unsigned char)(temp >> 8));
    UART1_SendChar((unsigned char)(temp));
    UART1_SendChar((unsigned char)(t >> 8));
    UART1_SendChar((unsigned char)(t));
    UART1_SendChar((unsigned char)(rh >> 8));
    UART1_SendChar((unsigned char)(rh));
    UART1_SendChar((unsigned char)(pm25 >> 8));
    UART1_SendChar((unsigned char)(pm25));
    delay_ms(820);
  }
}
