/***************************************************************************
* 文件名          : UART.h
* 概括            : UART的初始化及基本操作封装
* 版本号          : v0.1
* 作者            : 兰州
* 日期            : 2018/4/1
* 更改日志        :
* 日期         版本                  更改内容
* 2018/4/1    v0.1                   添加文件
***************************************************************************/

#ifndef _UART_H_
#define _UART_H_

//#include <stdio.h>
#include <iostm8s103f3.h>

//波特率
#define BAUD_RATE 115200

void UART1_Init();                       //UART1初始化
void UART1_SendChar(unsigned char c);   //发送单个字节                                
void UART1_SendCharA(unsigned char* data , unsigned char length); //发送字节数组
void UART1_SendString(unsigned char* str);//发送字符串 需字符串以'/0'结尾

#endif