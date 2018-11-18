#ifndef _DELAY_H_
#define _DELAY_H_
#include "intrins.h"
#include "define.h"

void delay1ms()		//@11.0592MHz  //ясЁы1ms
{
    uchar i, j;

    _nop_();
    _nop_();
    _nop_();
    i = 11;
    j = 190;
    do
    {
        while (--j);
    } while (--i);
}

void delayxms(int x)
{
    for(; x>0; x--)
        delay1ms();
}


//void delay1s()		//@11.0592MHz
//{
//	uchar i, j, k;

//	_nop_();
//	_nop_();
//	i = 43;
//	j = 6;
//	k = 203;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}
void delay20us()		//@11.0592MHz
{
    unsigned char i;

    _nop_();
    _nop_();
    _nop_();
    i = 52;
    while (--i);
}
void delay30us()		//@11.0592MHz
{
    uchar i;

    _nop_();
    _nop_();
    i = 80;
    while (--i);
}
void delay20ms()		//@11.0592MHz
{
    uchar i, j, k;

    _nop_();
    _nop_();
    i = 1;
    j = 216;
    k = 35;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

#endif