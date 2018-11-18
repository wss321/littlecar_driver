#ifndef _DEFINE_H_
#define _DEFINE_H_
#include "STC15F.h"
#define uchar unsigned char
#define uint unsigned int

#define FOSC 11059200	//ϵͳʱ��Ƶ��
#define BAUD 115200 //���ڲ�����


sbit lcd_sclk=P1^0; //�ӿڶ���:lcd_sclk ���� LCD �� SCLK
sbit lcd_sid=P1^1;//�ӿڶ���:lcd_sid ���� LCD �� SDA
sbit lcd_rs=P1^2; //�ӿڶ���:lcd_rs ���� LCD �� RS,Ҳ�С�CD��
sbit lcd_reset=P1^3; //�ӿڶ���:lcd_reset ���� LCD �� RESET
sbit lcd_cs1=P1^4; //�ӿڶ���:lcd_cs1 ���� LCD �� CS1



//����12877�ڲ�ʱ������
sbit DS_RW	=	P4^2;
sbit DS_DS	=	P4^4;
sbit DS_AS	=	P4^5;
/*--------12C887��ʱ���Ĵ����Ķ���--*/
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
/**------UART����ͨ��------*/
sbit uartTxD=P3^1;	  //��������
sbit uartRxD=P3^0;

/*---------------WIFIģ��---------*/
//ʹ��UARTͨ��
//�ò��뿪��ѡ��USB/WIFI

/*-----------DHT11��ʪ��ģ��------*/
sbit DHT=P4^0;

/*--------����--------*/
#define key2 P16
#define key1 P17

/*-----������----*/
#define BEEP P36

/*-----�綯��---------*/
#define MOT P2
#define MOTA_P P20
#define MOTA_N P21
#define MOTB_P P22
#define MOTB_N P23
#define MOTC_P P24
#define MOTC_N P25
#define MOTD_P P26
#define MOTD_N P27

/*������ģ��*/
#define Trig P15  //������������
#define Echo P33  //�ز�����

#endif

