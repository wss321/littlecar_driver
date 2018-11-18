#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#include "define.h"
#include "delay.h"
#include "lcd.h"
#include "interrupt.h"
#include "front.h"

//-----------------------------------------------
void Intr1_Init()			//�ⲿ�ж�1��ʼ��
{
    IT1 = 0; //����INT1���ж����� (1:�½��� 0:�����غ��½���)
    EX1 = 1; //ʹ��INT1�ж�
    EA = 1;
}

void Triger() {
    Trig=0;
		delay1ms();
    Trig=1;
    delay20us();// ����20us���壬����������
    Trig=0;		

}
void Timer2Init(void)		//��ʱ��2��ʼ��100΢��@11.0592MHz
{
    AUXR |= 0x04;		//��ʱ��ʱ��1Tģʽ
    T2L = 0xAE;		//���ö�ʱ��ֵ
    T2H = 0xFB;		//���ö�ʱ��ֵ
    AUXR |= 0x10;		//��ʱ��2��ʼ��ʱ
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
void run_ultra()		//������������ʼ����
{

    Triger();
//    display_distance();
}


#endif

