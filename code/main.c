#include "define.h"
#include "run.h"
#include "lcd.h"
#include "beep.h"
#include "serial.h"
#include "dht11.h"
#include "clock.h"
#include "key.h"
#include "ultrasonic.h"
#include "interrupt.h"
#include "front.h"
#include "wifi.h"
#include "dataTransform.h"

/*
						����С��
	���ڻ�WIFI�����Կ���С�����˶�
	ͨ��WIFI������Ҫ�����ز���WIFIһ�࣬��ͨWIFI
	WIFI����
					W|  S|  A|  D|  P| /ǰ������ͣ
	���ڿ���
					WW|  SS|  AA|  DD|  PP| /ǰ������ͣ
	����ʱ�䣺ST:14λʱ���ʽ|  ��ST:201807211200|



*/


//H00000T000000	��ʪ��ʱ���ʽ
void Timer0Init() {	  //��ʱ��0��ʼ��	 1ms

    AUXR |= 0x80; //��ʱ��0 1Tģʽ
// AUXR &= 0x7f; //��ʱ��0 12Tģʽ
    TMOD &= 0xF0; //���ö�ʱ�� ģʽ0(16λ�Զ���װ��)
    TL0 = 0xCD;		//���ö�ʱ��ֵ
    TH0 = 0xD4;		//���ö�ʱ��ֵ
    TR0 = 1; //��ʱ��0 ʼ��ʱ
    ET0 = 1; //ʹ�ܶ�ʱ��0�ж�
    EA = 1;
}



void main()
{

    int counter,m;
    uint im;
    stop();	   //ֹͣ�˶�
	    UartInit();	   //��ʼ��UART���ö�ʱ��1����������115200
    Init12887();  //
    initial_lcd();	//��ʼ��LCD
    clear_screen();
    display_hint();
    display_numorsym(5,81,ONE); //��ʾ��ʾ
    while(1) {		//����1����
        keyscan();
        if (Key1flag)
        {
            Key1flag=~Key1flag;	//���������־λ
            break;
        }
    }

    SetTime("20180720140535");	//���õ�ǰʱ���ʼ��
    Timer0Init();//���ö�ʱ��0		���ڶ�ʱ�����ϴ���ʪ��
    clear_screen();
    display_start(); //��������
    delayxms(2000);
    WifiInit();		 //��ʼ��wifi
    clear_screen();
		
    ultraInit();		//����ģ���ʼ������ ʹ�ö�ʱ��2
		UartSendString(" [OK]Initial completed.\r\n");
    while(1) {

        keyscan();
        if (Key1flag)
            Key1flag=~Key1flag;		//���������־

        if(Timing3s)		 //����3s
        {

            Timing3s=0;		   //�����־λ
						run_ultra();
            dht_main();	   //lcd��ʾ��ʪ��
            if(succeedMeasure) {		 //��������
							succeedMeasure=0;	//�����־λ
								display_distance();	//��ʾ����
                UartSendString("[OK]succeed Measure");
            }
            //��ͨ��wifi���ӵ��ֻ�����Է�������
            //UartSendString("AT+CIPSEND=0,13\r\n"); //��id=0����13�ֽ�
            delayxms(100);
            UartSendChar('H');
            SendTemAndHum();		 //������ʪ�ȵ�wifi(3+2�ֽ� )	 �¶�3ʪ��2
            UartSendChar('T');

            for(m=0; m<6; m++)
                UartSendChar(now[m+8]);			//����6λʱ��
//            UartSendChar('D');
//            UartSendChar(int2char(distance/1000%10));		//���;���4λ
//            UartSendChar(int2char(distance/100%10));
//            UartSendChar(int2char(distance/10%10));
//            UartSendChar(int2char(distance%10));
							UartSendString("\r\n");
						
        }
        
        display_time();	   //lcd��ʾʱ��

        if(Revflag) {
            Revflag = 0;

            UartSendString("recived msg:");	//�յ�����
            for(im=0; im<UartRevCounter; im++) {
                UartSendChar(UartRevBuff[im]);

            }
            /*�Դ����յ������ݴ�������С��W\A\S\D\P  ST:20180102041516|����ʱ��
            ��Ӧǰ���󡢺��ҡ�ͣ
            */
            if((UartRevBuff[0]=='W')&&(UartRevBuff[1]=='W'))
                forward();
            else if((UartRevBuff[0]=='S')&&(UartRevBuff[1]=='S'))
                back();
            else if((UartRevBuff[0]=='D')&&(UartRevBuff[1]=='D'))
                left();
            else if((UartRevBuff[0]=='A')&&(UartRevBuff[1]=='A')&&(UartRevBuff[2]=='|'))
                right();
            else if((UartRevBuff[0]=='P')&&(UartRevBuff[1]='P'))
                stop();
            else if((UartRevBuff[0]=='S')&&(UartRevBuff[1]='T')&&(UartRevBuff[2]=':'))
            {
                UartRevBuff[17]='\0';
                SetTime(&UartRevBuff[3]);
            }
//				else if((UartRevBuff[0]=='S')&&(UartRevBuff[1]=='T'))	 //����ʱ��	  ST:(14BYTE) (SetTime)����������ʱ��
//				{
//					 SetTime(&UartRevBuff[3])
//				}
            /*��WIFI�յ������ݴ�������С��W\A\S\D\P
            	��Ӧǰ���󡢺��ҡ�ͣ
            */
            if(WifiRevflag) {					 //�յ�wifi����
                WifiRevflag=0;
                counter=0;
                UartSendString("recived WIFI msg:");
                for(im=0; im<UartRevCounter; im++)
                    UartSendChar(UartRevBuff[im]);
                while(UartRevBuff[counter]!=':')
                    counter++;
                UartSendString(UartRevBuff);	  //wifi�յ����ݷ��͸�����
                //�յ����ݿ���С�� W0 A0 S0 D0 P0  ����ʱ��ST��2018010204151618
                if((UartRevBuff[counter]=='W')&&(UartRevBuff[1+counter]=='|'))	//
                    forward();
                else if((UartRevBuff[counter]=='S')&&(UartRevBuff[1+counter]=='|'))//&&(UartRevBuff[1+counter]=='S'))	 //
                    back();
                else if((UartRevBuff[counter]=='D')&&(UartRevBuff[1+counter]=='|'))//&&(UartRevBuff[1+counter]=='A'))	 //
                    left();
                else if((UartRevBuff[counter]=='A')&&(UartRevBuff[1+counter]=='|'))//&&(UartRevBuff[1+counter]=='D'))	//
                    right();
                else if((UartRevBuff[counter]=='P')&&(UartRevBuff[1+counter]=='|'))//s&&(UartRevBuff[1+counter]=='P'))	//
                    stop();
                else if((UartRevBuff[counter]=='S')&&(UartRevBuff[counter+1]='T')&&(UartRevBuff[counter+2]=':'))
                    SetTime(&UartRevBuff[3+counter]);

            }

        }



    }

}