//Thanks for ����ԭ��.
//ref http://blog.sina.com.cn/s/blog_520dcfa10102vgaw.html

#ifndef  __DELAY_H_
#define  __DELAY_H_

void delay_init(unsigned char clk); //��ʱ������ʼ��
void delay_us(unsigned short nus);  //us����ʱ����,���65536us.
void delay_ms(unsigned long nms);  //ms����ʱ����
#endif
