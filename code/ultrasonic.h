#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#include "define.h"
#include "delay.h"
#include "lcd.h"
#include "interrupt.h"
#include "front.h"

//-----------------------------------------------
void Intr1_Init()			//外部中断1初始化
{
    IT1 = 0; //设置INT1的中断类型 (1:下降沿 0:上升沿和下降沿)
    EX1 = 1; //使能INT1中断
    EA = 1;
}

void Triger() {
    Trig=0;
		delay1ms();
    Trig=1;
    delay20us();// 产生20us脉冲，启动超声波
    Trig=0;		

}
void Timer2Init(void)		//定时器2初始化100微秒@11.0592MHz
{
    AUXR |= 0x04;		//定时器时钟1T模式
    T2L = 0xAE;		//设置定时初值
    T2H = 0xFB;		//设置定时初值
    AUXR |= 0x10;		//定时器2开始计时
	IE2|=0x04;
}
void ultraInit()
{
	Intr1_Init();
	Timer2Init();
}
void display_distance()
{
    display_word_line(5,1,dis,2);
    display_numorsym(5,33,colon);
    display_numorsym(5,41,&NumberFont[(distance/1000%10)*16]);
    display_numorsym(5,49,&NumberFont[(distance/100%10)*16]);
    display_numorsym(5,57,&NumberFont[(distance/10%10)*16]);
    display_numorsym(5,65,&NumberFont[(distance%10)*16]);
    display_numorsym(5,73,C_word);
    display_numorsym(5,81,M_word);


}
void run_ultra()		//启动超声波开始测量
{

    Triger();
//    display_distance();
}


#endif

