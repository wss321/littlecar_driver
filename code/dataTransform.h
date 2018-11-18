#ifndef _DATATRANSFORM_H_
#define _DATATRANSFORM_H_
#include "front.h"

uchar int2char(int i)		//一个数字转字符
{
    uchar c;
    c=i+'0';
    return c;

}
int char2int(uchar c)
{
    int i;
    i=c-'0';
    return i;

}
//uchar* itoa(int n)			//数字转字符串
//{
//    uchar str[5];
//    int i,sign;

//    if((sign=n)<0)    //记录符号
//        n=-n;         //使n成为正数
//    i=0;
//    do {
//        str[i++]=n%10+'0';    //取下一个数字
//    } while((n/=10)>0);      //循环相除

//    if(sign<0)
//        str[i++]='-';
//    str[i]='\0';
//    return str;
//}
uchar* tonumaddress(uchar charnum)		//字符转该数字在数字字模的地址
{
    return &NumberFont[char2int(charnum)*16];
}

#endif