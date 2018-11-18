#ifndef _KEY_H_
#define _KEY_H_
#include "run.h"
#include "beep.h"
#include "delay.h"
bit Key1flag=0;		//按键标志位，需手动清零
bit Key2flag=0;
void keyscan()	  //键盘扫描
{

    if(key1==0)
    {
        delayxms(10);
        if(key1==0)
        {
            BeepXms(100);
            Key1flag=1;			//按键按下标志位
            while(!key1);
        }
    }

    if(key2==0)		//软件复位
    {
        delayxms(10);
        if(key2==0) {
            Key2flag=1;
            BeepXms(100);
            while(!key2);
            delayxms(1);
            IAP_CONTR = 0x20; //软件复位,系?重新从用户代码区?始运行程序	//H00000T000000
            // IAP_CONTR = 0x60; 	//软件复位,系?重新从ISP代码区?始运行程序

        }
    }


}
#endif
