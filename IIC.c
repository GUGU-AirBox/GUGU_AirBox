#include "IIC.h"

/***************************************************************************
* 函数名          : IIC_Init
* 功能            : STM8S硬件IIC的初始化
* 输入参数        : 无
* 输出            : 无
* 日期&作者       : 2018/4/11 由 兰州 创建
***************************************************************************/
void IIC_Init()
{					
    CLK_PCKENR1 |= 0x10;                //使能I2C时钟     
    I2C_CR2_bit.SWRST = 1;              //复位I2C寄存器
    asm("nop");asm("nop");              //等待复位完成
    asm("nop");asm("nop");              
    I2C_CR2_bit.SWRST = 0;            	//清除复位设置
    I2C_FREQR_bit.FREQ = 16;      	//Freq = 16M
    I2C_CCRH_bit.F_S = 1;   		//用于快速模式
    I2C_CCRH_bit.DUTY = 0;
    I2C_CCRL = 40;           		//设置I2C的时钟频率为200KHZ  I2CFreq = PCLK1 / CCR / DUTY[位]= 16MHZ / 40 / 2 = 200KHZ   
    I2C_TRISER_bit.TRISE = 16 + 1;								
    I2C_CR1_bit.PE = 1;		        //打开I2C(使能I2C)	
}

/***************************************************************************
* 函数名          : IIC_Write
* 功能            : 向设备地址subaddr，寄存器地址Byte_addr写入num个数据
* 输入参数        : 参数1：unsigned char subaddr ：设备地址
                    参数2：unsigned char Byte_addr ：寄存器地址
                    参数3：unsigned char *buffer ：存放要写入数据的数组的首地址
                    参数4：unsigned short num ：要写入的数据个数
* 输出            : 无
* 日期&作者       : 2018/4/11 由 兰州 创建
***************************************************************************/
void IIC_Write(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num)
{
  while(I2C_SR3_bit.BUSY == 1); //等待IIC总线空闲

  I2C_CR1_bit.PE = 1;           //使用IIC
  I2C_CR2_bit.START = 1;        //发送起始信号
  
  while(I2C_SR1_bit.SB == 0);	//等待起始信号产生
  I2C_SR1;                      //读状态寄存器1并清空其标志位
  I2C_DR = subaddr << 1;	//发送器件地地址 + 写信号，并清除SB标志位
  while(I2C_SR1_bit.ADDR == 0);	//等待器件地址发送完成
  I2C_SR1;                      //读状态寄存器1并清空其标志位
  I2C_SR3;		        //读状态寄存器3清除发送器件地址标志位
  
  I2C_DR = Byte_addr;           //发送寄存器地址
  while(I2C_SR1_bit.BTF == 0);  //等待寄存器地址发送完成
  I2C_SR1;	                //读状态寄存器1并清空其标志位

  while(num > 0)
  {
    I2C_DR = *buffer;		//发送数据
    while(I2C_SR1_bit.BTF == 0);//等待移位发送器发送完成
    I2C_SR1;		        //读状态寄存器1并清空其标志位
    buffer++;
    num--;
  }
  I2C_CR2_bit.STOP = 1;   	//发送停止信号结束数据传输
}

/***************************************************************************
* 函数名          : IIC_Read
* 功能            : 从设备地址subaddr，寄存器地址Byte_addr 读出num个数据
* 输入参数        : 参数1：unsigned char subaddr ：设备地址
                    参数2：unsigned char Byte_addr ：寄存器地址
                    参数3：unsigned char *buffer ：存放读出的数据的数组的首地址
                    参数4：unsigned short num ：要读取的数据个数
* 输出            : 无
* 日期&作者       : 2018/4/11 由 兰州 创建
***************************************************************************/
void IIC_Read(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num)
{
  I2C_CR2_bit.ACK = 1;	        //产生应答信号
  
  I2C_CR2_bit.START = 1;	//发送起始信号
  while(I2C_SR1_bit.SB == 0);	//等待起始信号产生
  
  I2C_SR1;		        //读状态寄存器1并清空其标志位
  I2C_DR = subaddr << 1;	//发送器件地地址 + 写标志，并清除SB标志位
  while(I2C_SR1_bit.ADDR == 0);	//等待器件地址发送完成
  I2C_SR1;                      //读状态寄存器1并清空其标志位
  I2C_SR3;		        //读状态寄存器3清除发送器件地址标志位
  
  I2C_DR = Byte_addr;           //发送寄存器地址
  while(I2C_SR1_bit.BTF == 0);  //等待寄存器地址发送完成
  I2C_SR1;	                //读状态寄存器1并清空其标志位
  
  I2C_CR2_bit.START = 1;        //重新发送起始信号
  while(I2C_SR1_bit.SB == 0);   //等待起始信号产生

  I2C_SR1;		        //读状态寄存器1并清空其标志位
  I2C_DR = (char)((subaddr << 1) |0x01 );       //发送器件地地址，并清除SB标志位
  while(I2C_SR1_bit.ADDR == 0); //等待器件地址发送完成
  I2C_SR1;                      //读状态寄存器1并清空其标志位
  I2C_SR3;		        //读状态寄存器3清除发送器件地址标志位
  
  while(num)
  {
    if(num == 1)
    {
        I2C_CR2_bit.ACK = 0;          //最后一个字节不产生应答信号
        I2C_CR2_bit.STOP = 1;         //发送停止信号结束数据传输
    }

    while(I2C_SR1_bit.RXNE == 0);//等待发送完成
    I2C_SR1;                    //读状态寄存器1并清空其标志位

    *buffer = I2C_DR;	
    buffer++;
    num--;
  }
}