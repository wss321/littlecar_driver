#ifndef __DHT11_H
#define __DHT11_H

#include "lcd.h"
#include "front.h"
#include "define.h"
#include "serial.h"
#include "dataTransform.h"
uint Temperature[3]= {1,1,1};	//前两位为整数部分，后一位为小数部分
uint Humidity[2]= {1,1};		//传回的湿度数据只有整数部分
uchar Data_Receive[5];

void display_Humidity(uchar page, column,uint Humidity[])//定制的数据显示函数
{   uchar j;
    for(j=0; j<2; j++) {
        display_numorsym(page,column,&NumberFont[Humidity[j]*16]);
        column+=8;
    }
    display_numorsym(page,column,pecent);

}

void display_Temp(uchar page, column,uint Temperature[])//定制的数据显示函数
{
    uchar j;
    for(j=0; j<2; j++)
    {
        display_numorsym(page,column,&NumberFont[Temperature[j]*16]);
        column+=8;
    }
    display_numorsym(page,column,dot);
    column+=8;
    display_numorsym(page,column,&NumberFont[Temperature[j]*16]);
    column+=8;
    display_word(page,column,degree);
}

void dht11_display()//OLED显示驱动函数
{
    display_word(1,1,wen);
    display_word(1,17,du);
    display_numorsym(1,33,colon);
    display_Temp(1,41,Temperature);//在指定位置显示温度
    display_word(3,1,shi);
    display_word(3,17,du);
    display_numorsym(3,33,colon);
    display_Humidity(3,41,Humidity);//在指定位置显示湿度
}

void DHT_Collect()//温度采集函数
{
    uchar i,j;//for循环变量
    uchar t;//超时判断
    uchar dat8=0;//一次读取的8位数据，需要读5次
    uint CheckValue=0;//校验和

    DHT=0;//主机发起始信号
    delay20ms();//主机拉低总线至少18ms
    DHT=1;//主机拉高总线20~40us
    delay30us();

    t=80;//设置超时等待时间
    while(DHT&&t--);//等待DHT11拉低总线
    if(t==0)//超时
    {
        DHT=1;
    }
    t=250;//设置超时等待时间
    while(!DHT&&t--);//等待DHT11拉高总线
    if(t==0)//超时
    {
        DHT=1;
    }
    t=250;//设置超时等待时间
    while(DHT&&t--);//等待DHT11拉低总线
    if(t==0)//超时
    {
        DHT=1;
    }

    for(j=0; j<5; j++) //5次读取
    {
        for(i=0; i<8; i++) //1次8个位
        {
            //等待50us开始时隙
            t=150;//设置超时等待时间
            while(!DHT&&t--);//等待DHT11拉高总线
            if(t==0)//超时
            {
                DHT=1;
            }
            t=0;//记录时间清零
            while(DHT&&++t);//等待并记录高电平持续时间
            dat8<<=1;
            if(t>30)//高电平持续时间较长(70us)
                dat8+=1;//传输值为1
        }
        Data_Receive[j]=dat8;
    }

    delay30us();//等待DHT11拉低50us
    delay30us();
    DHT=1;

    for(i=0; i<4; i++)
    {
        CheckValue+=Data_Receive[i];//计算校验值
    }
    if((uchar)CheckValue==Data_Receive[4])//比对
    {
        Temperature[0]=Data_Receive[2]/10;
        Temperature[1]=Data_Receive[2]%10;
        Temperature[2]=Data_Receive[3]%10;
        Humidity[0]=Data_Receive[0]/10;
        Humidity[1]=Data_Receive[0]%10;
    }
}
void SendTemAndHum()
{   //向串口发送温湿度数据
    int i;
    for(i=0; i<3; i++)
        UartSendChar(int2char(Temperature[i]));   //发送温湿度到wifi(3+2字节 )	 温度3湿度2
    for(i=0; i<2; i++)
        UartSendChar(int2char(Humidity[i]));

}


void dht_main()
{
    DHT_Collect();//DHT11数据采集
    dht11_display();
//		delay1s();
//		delay1s();//注意：长时间的延时必须要有，不然会读出0
}
#endif
