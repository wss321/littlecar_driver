#ifndef _DATATRANSFORM_H_
#define _DATATRANSFORM_H_
#include "front.h"

uchar int2char(int i)		//һ������ת�ַ�
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
//uchar* itoa(int n)			//����ת�ַ���
//{
//    uchar str[5];
//    int i,sign;

//    if((sign=n)<0)    //��¼����
//        n=-n;         //ʹn��Ϊ����
//    i=0;
//    do {
//        str[i++]=n%10+'0';    //ȡ��һ������
//    } while((n/=10)>0);      //ѭ�����

//    if(sign<0)
//        str[i++]='-';
//    str[i]='\0';
//    return str;
//}
uchar* tonumaddress(uchar charnum)		//�ַ�ת��������������ģ�ĵ�ַ
{
    return &NumberFont[char2int(charnum)*16];
}

#endif