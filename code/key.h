#ifndef _KEY_H_
#define _KEY_H_
#include "run.h"
#include "beep.h"
#include "delay.h"
bit Key1flag=0;		//������־λ�����ֶ�����
bit Key2flag=0;
void keyscan()	  //����ɨ��
{

    if(key1==0)
    {
        delayxms(10);
        if(key1==0)
        {
            BeepXms(100);
            Key1flag=1;			//�������±�־λ
            while(!key1);
        }
    }

    if(key2==0)		//�����λ
    {
        delayxms(10);
        if(key2==0) {
            Key2flag=1;
            BeepXms(100);
            while(!key2);
            delayxms(1);
            IAP_CONTR = 0x20; //�����λ,ϵ?���´��û�������?ʼ���г���	//H00000T000000
            // IAP_CONTR = 0x60; 	//�����λ,ϵ?���´�ISP������?ʼ���г���

        }
    }


}
#endif
