#ifndef _SERIAL_H_
#define _SERIAL_H_

#include "delay.h"
#include "define.h"

/*************UART_1 初始化****************/
void UartInit(void)		//115200bps@11.0592MHz
{
    PCON &= 0x3F;
    SCON = 0x50;		//8位数据,可变波特率
    AUXR |= 0x40;
    AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器

    TMOD &= 0x0F;		//清除定时器1模式位
    TMOD |= 0x20;		//设定定时器1为8位自动重装方式
    ET1 = 0;		//禁止定时器1中断
    TR1 = 1;		//启动定时器1
    REN = 1; 		//允许接收
    TL1 = (256 - (FOSC/32/BAUD)); //设置波特率重装值
    TH1 = (256 - (FOSC/32/BAUD));
    ES=1;	   //允许UART中断
    EA=1;	   //允许UART中断


}

void UartSendChar(uchar uartData)
{
    SBUF = uartData;
    while(!TI); //是否发送完成
    TI = 0; //软件清零
}

void UartSendString(uchar *string)
{
    while(*string!='\0')
    {
        SBUF = *string; //把数据A送给SBUF缓存器中
        while(TI != 1);//判断发送标志位TI，如果发送完成，硬件会置TI标志位1
        TI = 0;  //TI清为0，以备下一次发送
        string++;
    }
}


#endif

