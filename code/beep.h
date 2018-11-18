#ifndef _BEEP_H_
#define _BEEP_H_
#include "STC15F.h"
#include "define.h"
#include "delay.h"

void BeepXms(int x) //·äÃùÆ÷ÏìxÃë
{
    BEEP=0;
    delayxms(x);
    BEEP=1;
}
//void BeepFrequency(int sec,int fq)		 //ÏìsecÃë£¬ÆµÂÊÎªfq
//{
//  while(1) {
//  BeepXs(sec);
//  delayxms(1000/fq);
//  }
//}
#endif