#ifndef _CLOCK_H_
#define _CLOCK_H_
#include "define.h"
#include "lcd.h"
#include "front.h"
#include "dataTransform.h"
uchar now[14];
//写入指令
void write_ds(uchar add,uchar date)
{
    DS_AS=1;
    DS_DS=1;
    DS_RW=1;
    P0=add;
    DS_AS=0;
    DS_RW=0;
    P0=date;
    DS_RW=1;
    DS_AS=1;
}

//读取数据
uchar read_ds(uchar add)
{
    uchar ds_date;
    DS_AS=1;
    DS_DS=1;
    DS_RW=1;
    P0=add;
    DS_AS=0;
    DS_DS=0;
    P0=0XFF;
    ds_date=P0;
    DS_DS=1;
    DS_AS=1;
    return ds_date;
}

//初始化12887内部时钟
void Init12887()
{
    write_ds(0X0a,0x2f);
    write_ds(0x0b,0x06);
    write_ds(0x0c,0);
}

void SetTime(uchar t[])
{

//设置时钟时间
    if(t[0]=='0') write_ds(CENTURY,t[1]-'0');
    else write_ds(CENTURY,(((t[0]-'0'))*10)+t[1]-'0');

    if(t[2]=='0') write_ds(YEARS,(t[3]-'0'));
    else write_ds(YEARS,(((t[2]-'0'))*10)+t[3]-'0');

    if(t[4]=='0') write_ds(MONTHS,(t[5]-'0'));
    else write_ds(MONTHS,(((t[4]-'0'))*10)+t[5]-'0');

    if(t[6]=='0') write_ds(DAYS,(t[7]-'0'));
    else write_ds(DAYS,(((t[6]-'0'))*10)+t[7]-'0');

    if(t[8]=='0') write_ds(HOURS,(t[9]-'0'));
    else write_ds(HOURS,(((t[8]-'0'))*10)+t[9]-'0');

    if(t[10]=='0') write_ds(MINUTES,(t[11]-'0'));
    else write_ds(MINUTES,(((t[10]-'0'))*10)+t[11]-'0');

    if(t[12]=='0') write_ds(SECONDS,(t[13]-'0'));
    else write_ds(SECONDS,(((t[12]-'0'))*10)+t[13]-'0');

}

//读取时间到now数组空间中
void ReadTime()
{
    uchar temp;
    temp=read_ds(CENTURY);
    now[0]=(temp%100)/10+0x30;
    now[1]=temp%10+0x30;

    temp=read_ds(YEARS);
    now[2]=(temp%100)/10+0x30;
    now[3]=temp%10+0x30;

    temp=read_ds(MONTHS);
    now[4]=(temp%100)/10+0x30;
    now[5]=temp%10+0x30;

    temp=read_ds(DAYS);
    now[6]=(temp%100)/10+0x30;
    now[7]=temp%10+0x30;

    temp=read_ds(HOURS);
    now[8]=(temp%100)/10+0x30;
    now[9]=temp%10+0x30;


    temp=read_ds(MINUTES);
    now[10]=(temp%100)/10+0x30;
    now[11]=temp%10+0x30;

    temp=read_ds(SECONDS);
    now[12]=(temp%100)/10+0x30;
    now[13]=temp%10+0x30;
}
//显示时间
void display_time()
{
    ReadTime();
    display_word(7,1,time);
    display_word(7,16,jian);
    display_numorsym(7,32,colon);
    display_numorsym(7,40,tonumaddress(now[8]));
    display_numorsym(7,48,tonumaddress(now[9]));
    display_numorsym(7,56,colon);
    display_numorsym(7,64,tonumaddress(now[10]));
    display_numorsym(7,72,tonumaddress(now[11]));
    display_numorsym(7,80,colon);
    display_numorsym(7,88,tonumaddress(now[12]));
    display_numorsym(7,96,tonumaddress(now[13]));

//	uchar j,temp=column;
//	display_numorsym(page,column,shi);
//	column+=16;
//	display_numorsym(page,column,jian);
//	column+=16;
//	for(j=0;j<4;j++) //年
//	{
//	display_numorsym(page,column,&NumberFont[now[j]*16]);
//	column+=8;
//	}
//
//	display_numorsym(page,column,bar);
//	column+=8;
//	for(;j<6;j++) //月
//	{
//	display_numorsym(page,column,&NumberFont[now[j]*16]);
//	column+=8;
//	}
//	display_numorsym(page,column,bar);
//	column+=8;
//	for(;j<8;j++) //日
//	{
//	display_numorsym(page,column,&NumberFont[now[j]*16]);
//	column+=8;
//	}
//		display_numorsym(page,column,bar);
//	column+=8;
//	page+=2;
//	column=temp+32;
//
//	for(;j<10;j++) //时
//	{
//	display_numorsym(page,column,&NumberFont[now[j]*16]);
//	column+=8;
//	}
//	display_numorsym(page,column,bar);
//	column+=8;
//	for(;j<12;j++) //分
//	{
//	display_numorsym(page,column,&NumberFont[now[j]*16]);
//	column+=8;
//	}
//	display_numorsym(page,column,bar);
//	column+=8;
//	for(;j<14;j++) //秒
//	{
//	display_numorsym(page,column,&NumberFont[now[j]*16]);
//	column+=8;
//
}


#endif