#ifndef _BEEP_H_
#define _BEEP_H_
#include "STC15F.h"
#include "define.h"
#include "delay.h"

void BeepXms(int x) //��������x��
{
    BEEP=0;
    delayxms(x);
    BEEP=1;
}
//void BeepFrequency(int sec,int fq)		 //��sec�룬Ƶ��Ϊfq
//{
//  while(1) {
//  BeepXs(sec);
//  delayxms(1000/fq);
//  }
//}
#endif