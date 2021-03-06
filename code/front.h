#ifndef _FRONT_H
#define _FRONT_H

#include "define.h"

/*------------字库-------------*/

uchar code wen[]= { //-- 文字: 温 --
//-- 宋体 12; 此字体下对应的点阵为：宽 x 高=16x16 --
    0x10,0x60,0x02,0x8C,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00,
    0x04,0x04,0x7E,0x01,0x40,0x7E,0x42,0x42,0x7E,0x42,0x7E,0x42,0x42,0x7E,0x40,0x00,
};

uchar code du[]= { //-- 文字: 度 --
//-- 宋体 12; 此字体下对应的点阵为：宽 x 高=16x16 --
    0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0x25,0x26,0x24,0xFC,0x24,0x24,0x24,0x04,0x00,
    0x40,0x30,0x8F,0x80,0x84,0x4C,0x55,0x25,0x25,0x25,0x55,0x4C,0x80,0x80,0x80,0x00,
};
uchar code shi[]= {
    /*--  文字:  湿  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x60,0x02,0x8C,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0xFE,0x00,0x00,0x00,
    0x04,0x04,0x7E,0x01,0x44,0x48,0x50,0x7F,0x40,0x40,0x7F,0x50,0x48,0x44,0x40,0x00,
};
uchar code time[]= {
    /*--  文字:  时  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xFC,0x84,0x84,0x84,0xFC,0x00,0x10,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x00,
    0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,
};
uchar code colon[]= {
    /*--  文字:  :  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
    0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,
};
uchar code jian[]= {
    /*--  文字:  间  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xF8,0x01,0x06,0x00,0xF0,0x12,0x12,0x12,0xF2,0x02,0x02,0x02,0xFE,0x00,0x00,
    0x00,0xFF,0x00,0x00,0x00,0x1F,0x11,0x11,0x11,0x1F,0x00,0x40,0x80,0x7F,0x00,0x00,
};

uchar code degree[]= {
    /*--  文字:  ℃  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x06,0x09,0x09,0xE6,0xF8,0x0C,0x04,0x02,0x02,0x02,0x02,0x02,0x04,0x1E,0x00,0x00,
    0x00,0x00,0x00,0x07,0x1F,0x30,0x20,0x40,0x40,0x40,0x40,0x40,0x20,0x10,0x00,0x00
};
uchar code pecent[]= {
    /*--  文字:  %  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
    0xF0,0x08,0xF0,0x80,0x60,0x18,0x00,0x00,0x00,0x31,0x0C,0x03,0x1E,0x21,0x1E,0x00
};
uchar code ONE[]= {
    /*--  文字:  1  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
    0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,
};
/****************************************8*16的点阵************************************/
uchar code NumberFont[]= {
    0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,//0
    0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,//1
    0x00,0x70,0x08,0x08,0x08,0x08,0xF0,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,//2
    0x00,0x30,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x18,0x20,0x21,0x21,0x22,0x1C,0x00,//3
    0x00,0x00,0x80,0x40,0x30,0xF8,0x00,0x00,0x00,0x06,0x05,0x24,0x24,0x3F,0x24,0x24,//4
    0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00,//5
    0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00,//6
    0x00,0x18,0x08,0x08,0x88,0x68,0x18,0x00,0x00,0x00,0x00,0x3E,0x01,0x00,0x00,0x00,//7
    0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,//8
    0x00,0xF0,0x08,0x08,0x08,0x10,0xE0,0x00,0x00,0x01,0x12,0x22,0x22,0x11,0x0F,0x00//9
};

uchar code dot[]= {
    /*--  文字:  .  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00
};
//uchar code bar[]={
///*--  文字:  -  --*/
///*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
//};

uchar code startImage_1[]=		//4个字
{
    /*--  文字:  智  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x94,0x53,0x32,0x1E,0x32,0x52,0x10,0x00,0x7E,0x42,0x42,0x42,0x7E,0x00,0x00,
    0x00,0x00,0x00,0xFF,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0xFF,0x00,0x00,0x00,0x00,

    /*--  文字:  能  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x08,0xCC,0x4A,0x49,0x48,0x4A,0xCC,0x18,0x00,0x7F,0x88,0x88,0x84,0x82,0xE0,0x00,
    0x00,0xFF,0x12,0x12,0x52,0x92,0x7F,0x00,0x00,0x7E,0x88,0x88,0x84,0x82,0xE0,0x00,

    /*--  文字:  小  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x20,0x40,0x80,0x00,0x00,
    0x08,0x04,0x03,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x01,0x0E,0x00,

    /*--  文字:  车  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x08,0x88,0x48,0x28,0x18,0x0F,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
    0x08,0x08,0x09,0x09,0x09,0x09,0x09,0xFF,0x09,0x09,0x09,0x09,0x09,0x08,0x08,0x00,

};
uchar code startImage_2[]=		//5个字
{
    /*--  文字:  启  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x00,0xFC,0x44,0x44,0x44,0x45,0x46,0x44,0x44,0x44,0x44,0x7C,0x00,0x00,
    0x40,0x20,0x18,0x07,0x00,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0xFC,0x00,0x00,

    /*--  文字:     --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  动  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x40,0x44,0xC4,0x44,0x44,0x44,0x40,0x10,0x10,0xFF,0x10,0x10,0x10,0xF0,0x00,0x00,
    0x10,0x3C,0x13,0x10,0x14,0xB8,0x40,0x30,0x0E,0x01,0x40,0x80,0x40,0x3F,0x00,0x00,

    /*--  文字:     --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  中  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00,
    0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00,



};


uchar code dis[]= {
    /*--  文字:  距  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x3E,0x22,0xE2,0x22,0x3E,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,0xE2,0x02,0x00,
    0x20,0x3F,0x20,0x1F,0x11,0x11,0x00,0x7F,0x44,0x44,0x44,0x44,0x44,0x47,0x40,0x00,

    /*--  文字:  离  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x04,0x04,0x04,0xF4,0x84,0xD4,0xA5,0xA6,0xA4,0xD4,0x84,0xF4,0x04,0x04,0x04,0x00,
    0x00,0xFE,0x02,0x02,0x12,0x3A,0x16,0x13,0x12,0x1A,0x32,0x42,0x82,0x7E,0x00,0x00,
};
uchar code C_word[]= {
    /*--  文字:  c  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
    0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,
};
uchar code M_word[]= {
    /*--  文字:  m  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=8x16   --*/
    0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,
};

uchar code HINT1_1[]= {

    /*--  文字:  请  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x40,0x42,0xCC,0x00,0x00,0x44,0x54,0x54,0x54,0x7F,0x54,0x54,0x54,0x44,0x40,0x00,
    0x00,0x00,0x7F,0x20,0x10,0x00,0xFF,0x15,0x15,0x15,0x55,0x95,0x7F,0x00,0x00,0x00,

    /*--  文字:  确  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x04,0x84,0xE4,0x5C,0x44,0xC4,0x20,0x10,0xE8,0x27,0x24,0xE4,0x34,0x2C,0xE0,0x00,
    0x02,0x01,0x7F,0x10,0x10,0x3F,0x80,0x60,0x1F,0x09,0x09,0x3F,0x49,0x89,0x7F,0x00,

    /*--  文字:  保  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x80,0x60,0xF8,0x07,0x00,0x3E,0x22,0x22,0xE2,0x22,0x22,0x3E,0x00,0x00,0x00,
    0x01,0x00,0x00,0xFF,0x20,0x11,0x09,0x05,0x03,0xFF,0x03,0x05,0x09,0x11,0x20,0x00,

    /*--  文字:  开  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x80,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x80,0x00,
    0x00,0x80,0x40,0x30,0x0F,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  关  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x10,0x11,0x16,0x10,0x10,0xF0,0x10,0x10,0x14,0x13,0x10,0x00,0x00,0x00,
    0x81,0x81,0x41,0x41,0x21,0x11,0x0D,0x03,0x0D,0x11,0x21,0x41,0x41,0x81,0x81,0x00,

    /*--  文字:  拨  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x10,0x10,0xFF,0x90,0x40,0x1C,0x10,0xF0,0x9F,0x90,0x90,0x92,0x94,0x10,0x00,
    0x02,0x42,0x81,0x7F,0x40,0x20,0x98,0x87,0x40,0x2F,0x10,0x28,0x44,0x83,0x80,0x00,

    /*--  文字:  到  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x42,0x62,0x52,0x4A,0xC6,0x42,0x52,0x62,0xC2,0x00,0xF8,0x00,0x00,0xFF,0x00,0x00,
    0x40,0xC4,0x44,0x44,0x7F,0x24,0x24,0x24,0x20,0x00,0x0F,0x40,0x80,0x7F,0x00,0x00,
    /*--  文字:  了  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x02,0x02,0x02,0x02,0x02,0x02,0xE2,0x22,0x12,0x0A,0x06,0x02,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
uchar code HINT1_2[]=
{
    /*--  文字:  W  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x08,0xF8,0x00,0xF8,0x00,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x03,0x3E,0x01,0x3E,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  I  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  F  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  I  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /*--  文字:  侧  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x80,0x60,0xF8,0x07,0x00,0xFE,0x02,0xF2,0x02,0xFE,0x00,0xF8,0x00,0xFF,0x00,0x00,
    0x00,0x00,0xFF,0x00,0x80,0x47,0x30,0x0F,0x10,0x27,0x00,0x47,0x80,0x7F,0x00,0x00,

};
//uchar code XIAO[]=
//{
///*------------------------------------------------------------------------------
//;  若数据乱码，请检查字模格式设置，注意选择正确的取模方向和字节位顺序。
//;  源文件 / 文字 : 智能小车
//;  宽×高（像素）: 128×21
//;  字模格式/大小 : 单色点阵液晶字模，纵向取模，字节倒序/384字节
//;  数据转换日期  : 2018/4/23 星期一 下午 4:12:55
//------------------------------------------------------------------------------*/
///*--  文字:  小  --*/
///*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
//0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x20,0x40,0x80,0x00,0x00,
//0x08,0x04,0x03,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x01,0x0E,0x00,
//};
//uchar code CHE[]={
//	/*--  文字:  车  --*/
///*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
//0x00,0x08,0x88,0x48,0x28,0x18,0x0F,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
//0x08,0x08,0x09,0x09,0x09,0x09,0x09,0xFF,0x09,0x09,0x09,0x09,0x09,0x08,0x08,0x00,

//
//};

uchar code HINT2[]= {
    /*--  文字:  再  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x02,0x02,0xF2,0x92,0x92,0x92,0x92,0xFE,0x92,0x92,0x92,0x92,0xF2,0x02,0x02,0x00,
    0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x07,0x04,0x04,0x44,0x84,0x7F,0x04,0x04,0x00,
    /*--  文字:  按  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x10,0x10,0xFF,0x90,0x20,0x98,0x88,0x88,0xE9,0x8E,0x88,0x88,0xA8,0x98,0x00,
    0x02,0x42,0x81,0x7F,0x00,0x00,0x80,0x84,0x4B,0x28,0x10,0x28,0x47,0x80,0x00,0x00,

    /*--  文字:  下  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x02,0x02,0x42,0x82,0x02,0x02,0x02,0x02,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,

    /*--  文字:  按  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x10,0x10,0xFF,0x90,0x20,0x98,0x88,0x88,0xE9,0x8E,0x88,0x88,0xA8,0x98,0x00,
    0x02,0x42,0x81,0x7F,0x00,0x00,0x80,0x84,0x4B,0x28,0x10,0x28,0x47,0x80,0x00,0x00,

    /*--  文字:  键  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x40,0x30,0xEF,0x24,0x24,0x80,0xE4,0x9C,0x10,0x54,0x54,0xFF,0x54,0x7C,0x10,0x00,
    0x01,0x01,0x7F,0x21,0x51,0x26,0x18,0x27,0x44,0x45,0x45,0x5F,0x45,0x45,0x44,0x00,

    /*--  文字:     --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};



#endif