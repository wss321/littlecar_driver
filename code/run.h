#ifndef _RUN_H_
#define _RUN_H_

#include "STC15F.h"
#include "define.h"
#include "delay.h"


void forward();
void back();
void left();
void right();
void stop();

void A_forward();
void B_forward();
void C_forward();
void D_forward();
void A_back();
void B_back();
void C_back();
void D_back();

void A_forward()
{
    MOTA_P=1;
    MOTA_N=0;
}
void A_back()
{
    MOTA_P=0;
    MOTA_N=1;
}
void B_forward()
{
    MOTB_P=0;
    MOTB_N=1;
}

void B_back()
{
    MOTB_P=1;
    MOTB_N=0;
}
void C_forward()
{
    MOTC_P=1;
    MOTC_N=0;
}
void C_back()
{
    MOTC_P=0;
    MOTC_N=1;
}

void D_back()
{
    MOTD_P=1;
    MOTD_N=0;
}
void D_forward()
{
    MOTD_P=0;
    MOTD_N=1;
}

void forward()
{
    P2=0X00;
    delayxms(20);
    A_forward();
    delayxms(20);
    B_forward();
    delayxms(20);
    C_forward();
    delayxms(20);
    D_forward();
    delayxms(500);
}

void back()
{
    P2=0X00;
    delayxms(20);
    A_back();
    delayxms(20);
    B_back();
    delayxms(20);
    C_back();
    delayxms(20);
    D_back();
    delayxms(500);
}

void right()
{   P2=0X00;
    delayxms(20);
    A_forward();
    delayxms(20);
    B_back();
    delayxms(20);
    C_forward();
    delayxms(20);
    D_back();
    delayxms(500);
}
void left()
{   P2=0X00;
    delayxms(20);
    A_back();
    delayxms(20);
    B_forward();
    delayxms(20);
    C_back();
    delayxms(20);
    D_forward();
    delayxms(500);
}
void stop()
{
    P2=0x00;
    delayxms(500);
}
#endif