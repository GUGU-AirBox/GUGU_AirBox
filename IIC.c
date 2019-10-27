#include "IIC.h"

/***************************************************************************
* ������          : IIC_Init
* ����            : STM8SӲ��IIC�ĳ�ʼ��
* �������        : ��
* ���            : ��
* ����&����       : 2018/4/11 �� ���� ����
***************************************************************************/
void IIC_Init()
{					
    CLK_PCKENR1 |= 0x10;                //ʹ��I2Cʱ��     
    I2C_CR2_bit.SWRST = 1;              //��λI2C�Ĵ���
    asm("nop");asm("nop");              //�ȴ���λ���
    asm("nop");asm("nop");              
    I2C_CR2_bit.SWRST = 0;            	//�����λ����
    I2C_FREQR_bit.FREQ = 16;      	//Freq = 16M
    I2C_CCRH_bit.F_S = 1;   		//���ڿ���ģʽ
    I2C_CCRH_bit.DUTY = 0;
    I2C_CCRL = 40;           		//����I2C��ʱ��Ƶ��Ϊ200KHZ  I2CFreq = PCLK1 / CCR / DUTY[λ]= 16MHZ / 40 / 2 = 200KHZ   
    I2C_TRISER_bit.TRISE = 16 + 1;								
    I2C_CR1_bit.PE = 1;		        //��I2C(ʹ��I2C)	
}

/***************************************************************************
* ������          : IIC_Write
* ����            : ���豸��ַsubaddr���Ĵ�����ַByte_addrд��num������
* �������        : ����1��unsigned char subaddr ���豸��ַ
                    ����2��unsigned char Byte_addr ���Ĵ�����ַ
                    ����3��unsigned char *buffer �����Ҫд�����ݵ�������׵�ַ
                    ����4��unsigned short num ��Ҫд������ݸ���
* ���            : ��
* ����&����       : 2018/4/11 �� ���� ����
***************************************************************************/
void IIC_Write(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num)
{
  while(I2C_SR3_bit.BUSY == 1); //�ȴ�IIC���߿���

  I2C_CR1_bit.PE = 1;           //ʹ��IIC
  I2C_CR2_bit.START = 1;        //������ʼ�ź�
  
  while(I2C_SR1_bit.SB == 0);	//�ȴ���ʼ�źŲ���
  I2C_SR1;                      //��״̬�Ĵ���1��������־λ
  I2C_DR = subaddr << 1;	//���������ص�ַ + д�źţ������SB��־λ
  while(I2C_SR1_bit.ADDR == 0);	//�ȴ�������ַ�������
  I2C_SR1;                      //��״̬�Ĵ���1��������־λ
  I2C_SR3;		        //��״̬�Ĵ���3�������������ַ��־λ
  
  I2C_DR = Byte_addr;           //���ͼĴ�����ַ
  while(I2C_SR1_bit.BTF == 0);  //�ȴ��Ĵ�����ַ�������
  I2C_SR1;	                //��״̬�Ĵ���1��������־λ

  while(num > 0)
  {
    I2C_DR = *buffer;		//��������
    while(I2C_SR1_bit.BTF == 0);//�ȴ���λ�������������
    I2C_SR1;		        //��״̬�Ĵ���1��������־λ
    buffer++;
    num--;
  }
  I2C_CR2_bit.STOP = 1;   	//����ֹͣ�źŽ������ݴ���
}

/***************************************************************************
* ������          : IIC_Read
* ����            : ���豸��ַsubaddr���Ĵ�����ַByte_addr ����num������
* �������        : ����1��unsigned char subaddr ���豸��ַ
                    ����2��unsigned char Byte_addr ���Ĵ�����ַ
                    ����3��unsigned char *buffer ����Ŷ��������ݵ�������׵�ַ
                    ����4��unsigned short num ��Ҫ��ȡ�����ݸ���
* ���            : ��
* ����&����       : 2018/4/11 �� ���� ����
***************************************************************************/
void IIC_Read(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num)
{
  I2C_CR2_bit.ACK = 1;	        //����Ӧ���ź�
  
  I2C_CR2_bit.START = 1;	//������ʼ�ź�
  while(I2C_SR1_bit.SB == 0);	//�ȴ���ʼ�źŲ���
  
  I2C_SR1;		        //��״̬�Ĵ���1��������־λ
  I2C_DR = subaddr << 1;	//���������ص�ַ + д��־�������SB��־λ
  while(I2C_SR1_bit.ADDR == 0);	//�ȴ�������ַ�������
  I2C_SR1;                      //��״̬�Ĵ���1��������־λ
  I2C_SR3;		        //��״̬�Ĵ���3�������������ַ��־λ
  
  I2C_DR = Byte_addr;           //���ͼĴ�����ַ
  while(I2C_SR1_bit.BTF == 0);  //�ȴ��Ĵ�����ַ�������
  I2C_SR1;	                //��״̬�Ĵ���1��������־λ
  
  I2C_CR2_bit.START = 1;        //���·�����ʼ�ź�
  while(I2C_SR1_bit.SB == 0);   //�ȴ���ʼ�źŲ���

  I2C_SR1;		        //��״̬�Ĵ���1��������־λ
  I2C_DR = (char)((subaddr << 1) |0x01 );       //���������ص�ַ�������SB��־λ
  while(I2C_SR1_bit.ADDR == 0); //�ȴ�������ַ�������
  I2C_SR1;                      //��״̬�Ĵ���1��������־λ
  I2C_SR3;		        //��״̬�Ĵ���3�������������ַ��־λ
  
  while(num)
  {
    if(num == 1)
    {
        I2C_CR2_bit.ACK = 0;          //���һ���ֽڲ�����Ӧ���ź�
        I2C_CR2_bit.STOP = 1;         //����ֹͣ�źŽ������ݴ���
    }

    while(I2C_SR1_bit.RXNE == 0);//�ȴ��������
    I2C_SR1;                    //��״̬�Ĵ���1��������־λ

    *buffer = I2C_DR;	
    buffer++;
    num--;
  }
}