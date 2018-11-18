#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include "serial.h"
#include "run.h"
#include "define.h"
#include "ultrasonic.h"
#include "beep.h"

#define UartRevMax 32	 //接收缓冲区最大长度
uchar UartRevCount = 0;//接收数据个数计数器
uchar UartRevBuff[UartRevMax];
bit Revflag=0;
bit WifiRevflag=0;
uint UartRevCounter;	 //记录收到一条消息多长（多少字节）
bit Timing3s=0;
uint Timer1Cnt=0;
uint Timer2Cnt=0;
uint RespondTime=0;	//超声波单程回传时间
int UltraFlag=0;	  //1上升沿（开始） 2下降沿（结束） 0无
int distance;//=0;		//测得的距离
bit succeedMeasure=0;		 //测量成功标志位
/*************UART_1 中断服务程序****************/
void Uart1() interrupt 4
{
    if (RI)
    {

        RI = 0;
        UartRevBuff[UartRevCount] = SBUF;
        UartRevCount++;
        UartSendChar(SBUF);
        if(UartRevCount==UartRevMax||UartRevBuff[UartRevCount-1]=='\n'||UartRevBuff[UartRevCount-1]=='|')	 //避免溢出
        {
            UartRevCounter=UartRevCount;
            UartRevCount = 0;
            Revflag=1;
            if((UartRevBuff[0]=='+')&&(UartRevBuff[1]=='P')&&(UartRevBuff[3]=='D')) {		 //检测是否是wifi收到数据 以+PID开头
//
//            	UartSendString(UartRevBuff);
                WifiRevflag=1;
            }
//		 else if((UartRevBuff[0]='r')&&(UartRevBuff[1]='e')&&(UartRevBuff[4]='y'))
//			Revflag=0x02;
//			else if ((UartRevBuff[0]='+')&&(UartRevBuff[10]='I')&&(UartRevBuff[11]='P'))
        }
//	delayxms(UartRevBuff[UartRevCount]-'0');
    }
    if (TI)
    {
        TI = 0; //清除 TI 位
    }
}

void Timer0(void) interrupt 1			//时钟中断
{

    Timer1Cnt++;
    if(Timer1Cnt==3000)
    {
        Timer1Cnt=0;
        Timing3s=1;
    }
}
/******用来测量超声波时间*****/
void INT1_()  interrupt 2   // 外部中断1  用来测量超声波时间
{
		//BeepXms(10);			//测试中断
    if(UltraFlag==0)	   //是上升沿
        UltraFlag=1;
    else if(UltraFlag==1)	//是下降沿
        UltraFlag=2;
    else UltraFlag=0;
}

void Timer2_intr() interrupt 12	//100us触发一次
{
		BeepXms(100);			//测试中断
    if(UltraFlag==1)	//开始计数
    {
        Timer1Cnt++;
        
//		Timing3s=1;
    }
    if(UltraFlag==2) {	 //如果变成2说明结束了，记录下时间
        succeedMeasure=1;
        RespondTime=Timer1Cnt*50/1000;	//ms
        distance=RespondTime*34;	 //cm
        Timer1Cnt=0;
    }
}

#endif