/***************************************************************************
* 文件名          : SHT20.h
* 概括            : SHT20温湿度传感器封装
* 版本号          : v0.1
* 作者            : 兰州
* 日期            : 2019/10/27
* 更改日志        :
* 日期         版本      作者                更改内容
* 2019/10/27    v0.1     兰州                对SHT20温湿度传感器相关功能进行封装
***************************************************************************/

#ifndef _SHT20_H_
#define _SHT20_H_

#include "IIC.h"

// 寄存器地址定义
#define SHT20_WRITE_ADDR        0x80    //写地址
#define SHT20_READ_ADDR         0x81    //读地址
#define SHT20_MEASURE_RH_HM     0XE5    //主机模式读取湿度
#define SHT20_MEASURE_T_HM      0XE3    //主机模式读取温度
#define SHT20_MEASURE_RH_NHM    0XF5    //非主机模式读湿度
#define SHT20_MEASURE_T_NHM     0XF3    //非主机模式读温度
#define SHT20_READ_REG          0XE7
#define SHT20_WRITE_REG         0XE6
#define SHT20_SOFT_RESET        0XFE    //软重启

#define CRC8_POLYNOMIAL         0x131   //CRC8的多项式
void SHT20_Init();
void SHT20_ReadHuniAndTemprature(unsigned short* _outT, unsigned short* _outRH);

#endif