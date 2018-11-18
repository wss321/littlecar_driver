#ifndef _DEFINE_H_
#define _DEFINE_H_
#include "STC15F.h"
#define uchar unsigned char
#define uint unsigned int

#define FOSC 11059200	//系统时钟频率
#define BAUD 115200 //串口波特率


sbit lcd_sclk=P1^0; //接口定义:lcd_sclk 就是 LCD 的 SCLK
sbit lcd_sid=P1^1;//接口定义:lcd_sid 就是 LCD 的 SDA
sbit lcd_rs=P1^2; //接口定义:lcd_rs 就是 LCD 的 RS,也叫“CD”
sbit lcd_reset=P1^3; //接口定义:lcd_reset 就是 LCD 的 RESET
sbit lcd_cs1=P1^4; //接口定义:lcd_cs1 就是 LCD 的 CS1



//定义12877内部时钟引脚
sbit DS_RW	=	P4^2;
sbit DS_DS	=	P4^4;
sbit DS_AS	=	P4^5;
/*--------12C887的时基寄存器的定义--*/
#define SECONDS         0x0000
#define SECOND_ALARM    0x0001
#define MINUTES         0x0002
#define MINUTES_ALARM   0x0003
#define HOURS           0x0004
#define HOURS_ALARM     0x0005
#define WEEKS           0x0006
#define DAYS            0x0007
#define MONTHS          0x0008
#define YEARS           0x0009
#define	CENTURY         0x0032
#define SYEARS			0X0010
#define SMONTHS			0X0011
#define SDAYS			0X0012
#define SHOURS			0X0013
#define SMINUTES		0X0014
#define SSECONDS		0X0015
/**------UART串口通信------*/
sbit uartTxD=P3^1;	  //串口引脚
sbit uartRxD=P3^0;

/*---------------WIFI模块---------*/
//使用UART通信
//用拨码开关选择USB/WIFI

/*-----------DHT11温湿度模块------*/
sbit DHT=P4^0;

/*--------按键--------*/
#define key2 P16
#define key1 P17

/*-----蜂鸣器----*/
#define BEEP P36

/*-----电动机---------*/
#define MOT P2
#define MOTA_P P20
#define MOTA_N P21
#define MOTB_P P22
#define MOTB_N P23
#define MOTC_P P24
#define MOTC_N P25
#define MOTD_P P26
#define MOTD_N P27

/*超声波模块*/
#define Trig P15  //产生脉冲引脚
#define Echo P33  //回波引脚

#endif

