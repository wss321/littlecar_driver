#ifndef _LCD_H_
#define _LCD_H_

#include "STC15F.h"
#include "intrins.h"
#include "delay.h"
#include "front.h"
#include "define.h"
#include "dataTransform.h"


//дָ� LCD ģ��
void transfer_command_lcd(int data1)
{
    char i;
    lcd_cs1=0;
    lcd_rs=0;
    for(i=0; i<8; i++)
    {
        lcd_sclk=0;
        if(data1&0x80) lcd_sid=1;
        else lcd_sid=0;
        lcd_sclk=1;
        data1=data1<<=1;
    }
    lcd_cs1=1;
}
//д���ݵ� LCD ģ��
void transfer_data_lcd(uchar data1)
{
    char i;
    lcd_cs1=0;
    lcd_rs=1;
    for(i=0; i<8; i++)
    {
        lcd_sclk=0;
        if(data1&0x80) lcd_sid=1;
        else lcd_sid=0;
        lcd_sclk=1;
        data1=data1<<=1;
    }
    lcd_cs1=1;
}
//LCD ģ���ʼ��
void initial_lcd()
{
    lcd_reset=0; //�͵�ƽ��λ
    delayxms(100);
    lcd_reset=1; //��λ���
    delayxms(100);
    transfer_command_lcd(0xe2); //��λ
    delayxms(5);
    transfer_command_lcd(0x2c); //��ѹ���� 1
    delayxms(50);
    transfer_command_lcd(0x2e); //��ѹ���� 2
    delayxms(50);
    transfer_command_lcd(0x2f); //��ѹ���� 3
    delayxms(5);
    transfer_command_lcd(0x23); //�ֵ��Աȶȣ������÷�Χ 0x20��0x27
    transfer_command_lcd(0x81); //΢���Աȶ�
    transfer_command_lcd(0x28); //΢���Աȶȵ�ֵ�������÷�Χ 0x00��0x3f
    transfer_command_lcd(0xa2); //1/9 ƫѹ�ȣ�bias��
    transfer_command_lcd(0xc8); //��ɨ��˳�򣺴��ϵ���
    transfer_command_lcd(0xa0); //��ɨ��˳�򣺴�����
    transfer_command_lcd(0x40); //��ʼ�У���һ�п�ʼ
    transfer_command_lcd(0xaf); //����ʾ
}
void lcd_address(uint page,uint column)
{
    column=column-0x01;
    transfer_command_lcd(0xb0+page-1); //����(�ֽ���)ҳ��ַ��ÿ 8 ��Ϊһҳ��ȫ���� 64 �У����ֳ� 8 ҳ
    transfer_command_lcd(0x10+(column>>4&0x0f)); //�����е�ַ�ĸ� 4 λ
    transfer_command_lcd(column&0x0f); //�����е�ַ�ĵ� 4 λ
}
//ȫ������
void clear_screen()
{
    unsigned char i,j;
    for(i=0; i<9; i++)
    {
        transfer_command_lcd(0xb0+i);
        transfer_command_lcd(0x10);
        transfer_command_lcd(0x00);
        for(j=0; j<132; j++)
        {
            transfer_data_lcd(0x00);
        }
    }
}

////��ʾ 128x64 ����ͼ��
//void display_all(uchar *dp)
//{
//    uint i,j;
//    for(j=0; j<8; j++)	   //8���ֽ���
//    {
//        lcd_address(j+1,1);
//        for (i=0; i<128; i++) //128��
//        {
//            transfer_data_lcd(*dp); //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
//            dp++;
//        }
//    }
//}
//��ʾ 16x16 ����ͼ�񡢺��֡���Ƨ�ֻ� 16x16 ���������ͼ��
void display_word(uchar page,uchar column,uchar *dp)
{
    uint i,j;
    for(j=0; j<2; j++)		 //ÿ����ռ���ֽ��У�16��
    {
        lcd_address(page+j,column);
        for (i=0; i<16; i++)
        {
            transfer_data_lcd(*dp); //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
            dp++;
        }
    }
}
//��ʾ 8x16 ����ͼ��ASCII, �� 8x16 ����������ַ�������ͼ��
void display_numorsym(uchar page,uchar column,uchar *dp)
{
    uint i,j;
    for(j=0; j<2; j++)			//��ҳ
    {
        lcd_address(page+j,column);
        for (i=0; i<8; i++)			 //8��
        {
            transfer_data_lcd(*dp); //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
            dp++;
        }
    }
}

//void display_letter(uchar page,uchar column,uchar let)
//{
//    display_numorsym(page,column,&letter[(let-'a')*16]);
//
//}

//void display_lettr_line(uchar page,uchar column,uchar *dp,int Letternum)  // ��ʾһ��16*8
//{
//    	   uint i,j;
//    for(j=0; j<2; j++)		 //ÿ����ռ���ֽ��У�16��
//    {
//        lcd_address(page+j,column);
//        for (i=0; i<(Letternum*8); i++)
//        {
//            transfer_data_lcd(*dp); //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
//            dp++;
//        }
//    }

//}
void display_word_line(uchar page,uchar column,uchar *dp,int Wordnum)  // ��ʾһ��16*16
{
    uint i;//,j;
    for(i=0; i<Wordnum; i++)
        display_word(page,column+(i*16)-1,dp+(i*32)-1);
//    for(j=0; j<2; j++)		 //ÿ����ռ���ֽ��У�16��
//    {
//        lcd_address(page+j,column);
//        for (i=0; i<(Wordnum*16); i++)
//        {
//            transfer_data_lcd(*dp); //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
//            dp++;
//        }
//    }

}
//
//void display_anyline(uchar page,uchar column,uchar *dp,int columeNum) //columNumΪ������(16*columeNum)
//{
//    uchar i,j;
//    for (j=0; j<2; i++)
//    {
//        lcd_address(page+j,column);
//        for (i=0; i<columeNum; i++)			 //8��
//        {
//            transfer_data_lcd(*dp); //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
//            dp++;
//        }
//    }

//}



void display_start()
{
    display_word_line(2,32,startImage_1,4);
    display_word_line(4,24,startImage_2,5);
}
void display_hint()
{
    display_word_line(1,1,HINT1_1,7);
    display_word_line(3,1,HINT1_2,5);
    display_word_line(5,1,HINT2,6);

}
#endif