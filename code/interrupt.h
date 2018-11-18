#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include "serial.h"
#include "run.h"
#include "define.h"
#include "ultrasonic.h"
#include "beep.h"

#define UartRevMax 32	 //���ջ�������󳤶�
uchar UartRevCount = 0;//�������ݸ���������
uchar UartRevBuff[UartRevMax];
bit Revflag=0;
bit WifiRevflag=0;
uint UartRevCounter;	 //��¼�յ�һ����Ϣ�೤�������ֽڣ�
bit Timing3s=0;
uint Timer1Cnt=0;
uint Timer2Cnt=0;
uint RespondTime=0;	//���������̻ش�ʱ��
int UltraFlag=0;	  //1�����أ���ʼ�� 2�½��أ������� 0��
int distance;//=0;		//��õľ���
bit succeedMeasure=0;		 //�����ɹ���־λ
/*************UART_1 �жϷ������****************/
void Uart1() interrupt 4
{
    if (RI)
    {

        RI = 0;
        UartRevBuff[UartRevCount] = SBUF;
        UartRevCount++;
        UartSendChar(SBUF);
        if(UartRevCount==UartRevMax||UartRevBuff[UartRevCount-1]=='\n'||UartRevBuff[UartRevCount-1]=='|')	 //�������
        {
            UartRevCounter=UartRevCount;
            UartRevCount = 0;
            Revflag=1;
            if((UartRevBuff[0]=='+')&&(UartRevBuff[1]=='P')&&(UartRevBuff[3]=='D')) {		 //����Ƿ���wifi�յ����� ��+PID��ͷ
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
        TI = 0; //��� TI λ
    }
}

void Timer0(void) interrupt 1			//ʱ���ж�
{

    Timer1Cnt++;
    if(Timer1Cnt==3000)
    {
        Timer1Cnt=0;
        Timing3s=1;
    }
}
/******��������������ʱ��*****/
void INT1_()  interrupt 2   // �ⲿ�ж�1  ��������������ʱ��
{
		//BeepXms(10);			//�����ж�
    if(UltraFlag==0)	   //��������
        UltraFlag=1;
    else if(UltraFlag==1)	//���½���
        UltraFlag=2;
    else UltraFlag=0;
}

void Timer2_intr() interrupt 12	//100us����һ��
{
		BeepXms(100);			//�����ж�
    if(UltraFlag==1)	//��ʼ����
    {
        Timer1Cnt++;
        
//		Timing3s=1;
    }
    if(UltraFlag==2) {	 //������2˵�������ˣ���¼��ʱ��
        succeedMeasure=1;
        RespondTime=Timer1Cnt*50/1000;	//ms
        distance=RespondTime*34;	 //cm
        Timer1Cnt=0;
    }
}

#endif