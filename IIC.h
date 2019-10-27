/***************************************************************************
* 文件名          : IIC.h
* 概括            : 硬件IIC的初始化及初步封装
* 版本号          : v1.0
* 作者            : 兰州
* 日期            : 2018/4/12
* 更改日志        :
* 日期         版本      作者                更改内容
* 2018/4/11    v1.0      兰州              硬件IIC的初始化和初步封装
***************************************************************************/

#ifndef _IIC_H_
#define _IIC_H_

#include <iostm8s103f3.h>

void IIC_Init();
void IIC_Read(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num);
void IIC_Write(unsigned char subaddr , unsigned char Byte_addr , unsigned char *buffer , unsigned short num); 


#endif