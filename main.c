#include <iostm8s103f3.h>
#include "GPIO.h"
#include "UART.h"

void Sleep(unsigned int times)
  {
    for(int i = 0; i < times * 1000; i++)
      asm("nop");
  }

void main( void )
{
  GPIO_Init();
  UART1_Init();

  while(1)
  {
    WIFI_LED_ON();
    Sleep(5000);
    WIFI_LED_OFF();
    Sleep(5000);
    UART1_SendString("Hello!");
  }
}
