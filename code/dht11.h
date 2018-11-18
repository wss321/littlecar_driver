#ifndef __DHT11_H
#define __DHT11_H

#include "lcd.h"
#include "front.h"
#include "define.h"
#include "serial.h"
#include "dataTransform.h"
uint Temperature[3]= {1,1,1};	//ǰ��λΪ�������֣���һλΪС������
uint Humidity[2]= {1,1};		//���ص�ʪ������ֻ����������
uchar Data_Receive[5];

void display_Humidity(uchar page, column,uint Humidity[])//���Ƶ�������ʾ����
{   uchar j;
    for(j=0; j<2; j++) {
        display_numorsym(page,column,&NumberFont[Humidity[j]*16]);
        column+=8;
    }
    display_numorsym(page,column,pecent);

}

void display_Temp(uchar page, column,uint Temperature[])//���Ƶ�������ʾ����
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

void dht11_display()//OLED��ʾ��������
{
    display_word(1,1,wen);
    display_word(1,17,du);
    display_numorsym(1,33,colon);
    display_Temp(1,41,Temperature);//��ָ��λ����ʾ�¶�
    display_word(3,1,shi);
    display_word(3,17,du);
    display_numorsym(3,33,colon);
    display_Humidity(3,41,Humidity);//��ָ��λ����ʾʪ��
}

void DHT_Collect()//�¶Ȳɼ�����
{
    uchar i,j;//forѭ������
    uchar t;//��ʱ�ж�
    uchar dat8=0;//һ�ζ�ȡ��8λ���ݣ���Ҫ��5��
    uint CheckValue=0;//У���

    DHT=0;//��������ʼ�ź�
    delay20ms();//����������������18ms
    DHT=1;//������������20~40us
    delay30us();

    t=80;//���ó�ʱ�ȴ�ʱ��
    while(DHT&&t--);//�ȴ�DHT11��������
    if(t==0)//��ʱ
    {
        DHT=1;
    }
    t=250;//���ó�ʱ�ȴ�ʱ��
    while(!DHT&&t--);//�ȴ�DHT11��������
    if(t==0)//��ʱ
    {
        DHT=1;
    }
    t=250;//���ó�ʱ�ȴ�ʱ��
    while(DHT&&t--);//�ȴ�DHT11��������
    if(t==0)//��ʱ
    {
        DHT=1;
    }

    for(j=0; j<5; j++) //5�ζ�ȡ
    {
        for(i=0; i<8; i++) //1��8��λ
        {
            //�ȴ�50us��ʼʱ϶
            t=150;//���ó�ʱ�ȴ�ʱ��
            while(!DHT&&t--);//�ȴ�DHT11��������
            if(t==0)//��ʱ
            {
                DHT=1;
            }
            t=0;//��¼ʱ������
            while(DHT&&++t);//�ȴ�����¼�ߵ�ƽ����ʱ��
            dat8<<=1;
            if(t>30)//�ߵ�ƽ����ʱ��ϳ�(70us)
                dat8+=1;//����ֵΪ1
        }
        Data_Receive[j]=dat8;
    }

    delay30us();//�ȴ�DHT11����50us
    delay30us();
    DHT=1;

    for(i=0; i<4; i++)
    {
        CheckValue+=Data_Receive[i];//����У��ֵ
    }
    if((uchar)CheckValue==Data_Receive[4])//�ȶ�
    {
        Temperature[0]=Data_Receive[2]/10;
        Temperature[1]=Data_Receive[2]%10;
        Temperature[2]=Data_Receive[3]%10;
        Humidity[0]=Data_Receive[0]/10;
        Humidity[1]=Data_Receive[0]%10;
    }
}
void SendTemAndHum()
{   //�򴮿ڷ�����ʪ������
    int i;
    for(i=0; i<3; i++)
        UartSendChar(int2char(Temperature[i]));   //������ʪ�ȵ�wifi(3+2�ֽ� )	 �¶�3ʪ��2
    for(i=0; i<2; i++)
        UartSendChar(int2char(Humidity[i]));

}


void dht_main()
{
    DHT_Collect();//DHT11���ݲɼ�
    dht11_display();
//		delay1s();
//		delay1s();//ע�⣺��ʱ�����ʱ����Ҫ�У���Ȼ�����0
}
#endif
