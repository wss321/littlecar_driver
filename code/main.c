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
						智能小车
	串口或WIFI都可以控制小车的运动
	通过WIFI控制需要将开关拨到WIFI一侧，连通WIFI
	WIFI控制
					W|  S|  A|  D|  P| /前后左右停
	串口控制
					WW|  SS|  AA|  DD|  PP| /前后左右停
	设置时间：ST:14位时间格式|  如ST:201807211200|



*/


//H00000T000000	温湿度时间格式
void Timer0Init() {	  //定时器0初始化	 1ms

    AUXR |= 0x80; //定时器0 1T模式
// AUXR &= 0x7f; //定时器0 12T模式
    TMOD &= 0xF0; //设置定时器 模式0(16位自动重装载)
    TL0 = 0xCD;		//设置定时初值
    TH0 = 0xD4;		//设置定时初值
    TR0 = 1; //定时器0 始计时
    ET0 = 1; //使能定时器0中断
    EA = 1;
}



void main()
{

    int counter,m;
    uint im;
    stop();	   //停止运动
	    UartInit();	   //初始化UART，用定时器1发生波特率115200
    Init12887();  //
    initial_lcd();	//初始化LCD
    clear_screen();
    display_hint();
    display_numorsym(5,81,ONE); //显示提示
    while(1) {		//按键1阻塞
        keyscan();
        if (Key1flag)
        {
            Key1flag=~Key1flag;	//清除按键标志位
            break;
        }
    }

    SetTime("20180720140535");	//设置当前时间初始化
    Timer0Init();//配置定时器0		用于定时更新上传温湿度
    clear_screen();
    display_start(); //开机动画
    delayxms(2000);
    WifiInit();		 //初始化wifi
    clear_screen();
		
    ultraInit();		//声波模块初始化配置 使用定时器2
		UartSendString(" [OK]Initial completed.\r\n");
    while(1) {

        keyscan();
        if (Key1flag)
            Key1flag=~Key1flag;		//清除按键标志

        if(Timing3s)		 //过了3s
        {

            Timing3s=0;		   //清除标志位
						run_ultra();
            dht_main();	   //lcd显示温湿度
            if(succeedMeasure) {		 //发送数据
							succeedMeasure=0;	//清除标志位
								display_distance();	//显示距离
                UartSendString("[OK]succeed Measure");
            }
            //向通过wifi连接的手机或电脑发送数据
            //UartSendString("AT+CIPSEND=0,13\r\n"); //向id=0发送13字节
            delayxms(100);
            UartSendChar('H');
            SendTemAndHum();		 //发送温湿度到wifi(3+2字节 )	 温度3湿度2
            UartSendChar('T');

            for(m=0; m<6; m++)
                UartSendChar(now[m+8]);			//发送6位时间
//            UartSendChar('D');
//            UartSendChar(int2char(distance/1000%10));		//发送距离4位
//            UartSendChar(int2char(distance/100%10));
//            UartSendChar(int2char(distance/10%10));
//            UartSendChar(int2char(distance%10));
							UartSendString("\r\n");
						
        }
        
        display_time();	   //lcd显示时间

        if(Revflag) {
            Revflag = 0;

            UartSendString("recived msg:");	//收到数据
            for(im=0; im<UartRevCounter; im++) {
                UartSendChar(UartRevBuff[im]);

            }
            /*对串口收到的数据处理，控制小车W\A\S\D\P  ST:20180102041516|设置时间
            对应前、左、后、右、停
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
//				else if((UartRevBuff[0]=='S')&&(UartRevBuff[1]=='T'))	 //设置时间	  ST:(14BYTE) (SetTime)世纪年月日时分
//				{
//					 SetTime(&UartRevBuff[3])
//				}
            /*对WIFI收到的数据处理，控制小车W\A\S\D\P
            	对应前、左、后、右、停
            */
            if(WifiRevflag) {					 //收到wifi数据
                WifiRevflag=0;
                counter=0;
                UartSendString("recived WIFI msg:");
                for(im=0; im<UartRevCounter; im++)
                    UartSendChar(UartRevBuff[im]);
                while(UartRevBuff[counter]!=':')
                    counter++;
                UartSendString(UartRevBuff);	  //wifi收到数据发送给串口
                //收到数据控制小车 W0 A0 S0 D0 P0  设置时间ST：2018010204151618
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