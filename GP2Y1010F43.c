/***************************************************************************
* �ļ���          : GP2Y1010F43.c
* ����            : ����GP2Y1010F43 �����ﴫ����
* �汾��          : v0.1
* ����            : ����
* ����            : 2019-11-3
* ������־        :
* ����         �汾      ����                ��������
* 2019/11/3    v0.1      ����                ����
***************************************************************************/

#include "GP2Y1010F43.h"
#include "TIM2_Delay.h"

void PM25_Init()
{
  //ADC1 AIN3 PD2 ��������
  PM25VO_DDR = 0;
  PM25VO_CR1 = 0;
  PM25VO_CR2 = 0;
  
  //LEDPIN PA1 �������
  PM25LED_DDR = 1; 
  PM25LED_CR1 = 1; 
  PM25LED_CR2 = 0;
  PM25_LED_OFF(); //Ĭ�Ϲر�
  
  //ADC��������
  ADC_CR1 = 0x00;  //ADCʱ�ӣ�����ת�����ر�ADC
  ADC_CR2 |= 0x08; //�Ҷ���ģʽ����������Ĭ��
}
void PM25_Read(unsigned int* _out_val)
{
  ADC_CSR = PM25_ADC_CHANEL;  //ѡ��ͨ��
  unsigned char ADC_H,ADC_L;  
  unsigned int res[10] = {0};   
  for(unsigned char i = 0; i < ADCSAMPLETIMES; i++)
  {
    ADC_CR1 |= 0x01;  //����ADC ����ADC��Դ  
    DelayMs(5);      //��ʱ �ȴ�ADC����  
    
    PM25_LED_ON();      //��LED��Դ
    DelayUs(285);       //�����ֲ�ȴ�280us
    ADC_CR1 |= 0x01;    //����ADת��  
    DelayUs(40);        //�����ȴ�40us
    while((ADC_CSR&0x80) == 0); //�ȴ�ADCת������  
    PM25_LED_OFF();     //�ر�LED��Դ
    DelayUs(4200);      //�ȴ�ʣ�µ�
    
    ADC_H = ADC_DRH;  //����� �ȶ��߰�λ  
    ADC_L = ADC_DRL;  //��ȡ��λֵ  
    res[i] = ((ADC_H << 8) + ADC_L); //������λ���ݺϲ���һ��16λ����  
  }
  *_out_val = res[0];
}