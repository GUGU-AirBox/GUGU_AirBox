/***************************************************************************
* 文件名          : UART.c
* 概括            : UART的初始化及基本操作封装
* 版本号          : v1.0
* 作者            : 兰州
* 日期            : 2018/4/1
* 更改日志        :
* 日期         版本                更改内容
* 2018/4/1    v0.1                 添加文件
* 2018/4/2    v0.2                 实现UART1的基本发送、接收
* 2018/4/12   v1.0                 完善函数，添加、修改注释 初定
***************************************************************************/

#include "UART.h"

/***************************************************************************
* 函数名          : UART1_Init
* 功能            : UART1初始化
* 输入参数        : 无
* 输出            : 无
* 日期&作者       : 2018/4/2 由 兰州 创建
***************************************************************************/
void UART1_Init()
{
  //UART1初始化 
  
  UART1_CR2=0x00;
  
  //波特率 9600bps 校验位无 数据位8 停止位1
  UART1_CR1=0x00;
  UART1_CR3=0x00;
  unsigned int baud = 16000000 / BAUD_RATE;     //设定串口相应波特率与串口时钟的分频数
  
  //波特率设定 先写BRR2 , 再写BRR1
  UART1_BRR2 = ((unsigned char)((baud & 0xf000) >> 8)) | ((unsigned char)(baud & 0x000f));       //先写波特比率的高4位与低4位
  UART1_BRR1 = ((unsigned char)((baud & 0x0ff0) >> 4));                                          //后写波特比率的中间8位
  
  //允许接收，发送，开接收中断
  UART1_CR2=0x2c;
}

/***************************************************************************
* 函数名          : UART1_SendChar
* 功能            : 使用UART1发送1个字节
* 输入参数        : 参数1：unsigned char c 要发送的字节
* 输出            : 无
* 日期&作者       : 2018/4/2 由 兰州 创建
***************************************************************************/
void UART1_SendChar(unsigned char c)
{
  //等待数据发送结束
  while((UART1_SR & 0x80)==0x00);
  UART1_DR=c;
}

/***************************************************************************
* 函数名          : UART1_SendCharA
* 功能            : 使用UART1发送 length个字节
* 输入参数        : 参数1：unsigned char* date 要发送的字节数组的首字节地址
                    参数2：要发送的字节数
* 输出            : 无
* 日期&作者       : 2018/4/2 由 兰州 创建
***************************************************************************/
void UART1_SendCharA(unsigned char* data , unsigned char length)
{
  unsigned char datalen;
  for(datalen = 0 ; datalen < length ; datalen++)
    UART1_SendChar(data[datalen]);
}

/***************************************************************************
* 函数名          : UART1_SendString
* 功能            : 使用UART1发送字符串
* 输入参数        : 参数1：unsigned char* str 要发送的字符串，需以'\0'结尾
* 输出            : 无
* 日期&作者       : 2018/4/6 由 兰州 创建
***************************************************************************/
void UART1_SendString(unsigned char* str)
{
  unsigned char i = 0;
  while(str[i] != '\0')
    UART1_SendChar(str[i++]);
}
