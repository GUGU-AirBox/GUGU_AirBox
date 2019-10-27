//Thanks for 正点原子.
//ref http://blog.sina.com.cn/s/blog_520dcfa10102vgaw.html

#ifndef  __DELAY_H_
#define  __DELAY_H_

void delay_init(unsigned char clk); //延时函数初始化
void delay_us(unsigned short nus);  //us级延时函数,最大65536us.
void delay_ms(unsigned long nms);  //ms级延时函数
#endif
