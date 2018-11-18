#ifndef _LCD_H_
#define _LCD_H_

#include "STC15F.h"
#include "intrins.h"
#include "delay.h"
#include "front.h"
#include "define.h"
#include "dataTransform.h"


//写指令到 LCD 模块
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
//写数据到 LCD 模块
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
//LCD 模块初始化
void initial_lcd()
{
    lcd_reset=0; //低电平复位
    delayxms(100);
    lcd_reset=1; //复位完毕
    delayxms(100);
    transfer_command_lcd(0xe2); //软复位
    delayxms(5);
    transfer_command_lcd(0x2c); //升压步聚 1
    delayxms(50);
    transfer_command_lcd(0x2e); //升压步聚 2
    delayxms(50);
    transfer_command_lcd(0x2f); //升压步聚 3
    delayxms(5);
    transfer_command_lcd(0x23); //粗调对比度，可设置范围 0x20～0x27
    transfer_command_lcd(0x81); //微调对比度
    transfer_command_lcd(0x28); //微调对比度的值，可设置范围 0x00～0x3f
    transfer_command_lcd(0xa2); //1/9 偏压比（bias）
    transfer_command_lcd(0xc8); //行扫描顺序：从上到下
    transfer_command_lcd(0xa0); //列扫描顺序：从左到右
    transfer_command_lcd(0x40); //起始行：第一行开始
    transfer_command_lcd(0xaf); //开显示
}
void lcd_address(uint page,uint column)
{
    column=column-0x01;
    transfer_command_lcd(0xb0+page-1); //设置(字节行)页地址，每 8 行为一页，全屏共 64 行，被分成 8 页
    transfer_command_lcd(0x10+(column>>4&0x0f)); //设置列地址的高 4 位
    transfer_command_lcd(column&0x0f); //设置列地址的低 4 位
}
//全屏清屏
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

////显示 128x64 点阵图像
//void display_all(uchar *dp)
//{
//    uint i,j;
//    for(j=0; j<8; j++)	   //8个字节行
//    {
//        lcd_address(j+1,1);
//        for (i=0; i<128; i++) //128列
//        {
//            transfer_data_lcd(*dp); //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
//            dp++;
//        }
//    }
//}
//显示 16x16 点阵图像、汉字、生僻字或 16x16 点阵的其他图标
void display_word(uchar page,uchar column,uchar *dp)
{
    uint i,j;
    for(j=0; j<2; j++)		 //每个字占两字节行，16列
    {
        lcd_address(page+j,column);
        for (i=0; i<16; i++)
        {
            transfer_data_lcd(*dp); //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
            dp++;
        }
    }
}
//显示 8x16 点阵图像、ASCII, 或 8x16 点阵的自造字符、其他图标
void display_numorsym(uchar page,uchar column,uchar *dp)
{
    uint i,j;
    for(j=0; j<2; j++)			//两页
    {
        lcd_address(page+j,column);
        for (i=0; i<8; i++)			 //8列
        {
            transfer_data_lcd(*dp); //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
            dp++;
        }
    }
}

//void display_letter(uchar page,uchar column,uchar let)
//{
//    display_numorsym(page,column,&letter[(let-'a')*16]);
//
//}

//void display_lettr_line(uchar page,uchar column,uchar *dp,int Letternum)  // 显示一串16*8
//{
//    	   uint i,j;
//    for(j=0; j<2; j++)		 //每个字占两字节行，16列
//    {
//        lcd_address(page+j,column);
//        for (i=0; i<(Letternum*8); i++)
//        {
//            transfer_data_lcd(*dp); //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
//            dp++;
//        }
//    }

//}
void display_word_line(uchar page,uchar column,uchar *dp,int Wordnum)  // 显示一串16*16
{
    uint i;//,j;
    for(i=0; i<Wordnum; i++)
        display_word(page,column+(i*16)-1,dp+(i*32)-1);
//    for(j=0; j<2; j++)		 //每个字占两字节行，16列
//    {
//        lcd_address(page+j,column);
//        for (i=0; i<(Wordnum*16); i++)
//        {
//            transfer_data_lcd(*dp); //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
//            dp++;
//        }
//    }

}
//
//void display_anyline(uchar page,uchar column,uchar *dp,int columeNum) //columNum为多少列(16*columeNum)
//{
//    uchar i,j;
//    for (j=0; j<2; i++)
//    {
//        lcd_address(page+j,column);
//        for (i=0; i<columeNum; i++)			 //8列
//        {
//            transfer_data_lcd(*dp); //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
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