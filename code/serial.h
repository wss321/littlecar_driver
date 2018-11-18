#ifndef _SERIAL_H_
#define _SERIAL_H_

#include "delay.h"
#include "define.h"

/*************UART_1 ��ʼ��****************/
void UartInit(void)		//115200bps@11.0592MHz
{
    PCON &= 0x3F;
    SCON = 0x50;		//8λ����,�ɱ䲨����
    AUXR |= 0x40;
    AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����

    TMOD &= 0x0F;		//�����ʱ��1ģʽλ
    TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
    ET1 = 0;		//��ֹ��ʱ��1�ж�
    TR1 = 1;		//������ʱ��1
    REN = 1; 		//�������
    TL1 = (256 - (FOSC/32/BAUD)); //���ò�������װֵ
    TH1 = (256 - (FOSC/32/BAUD));
    ES=1;	   //����UART�ж�
    EA=1;	   //����UART�ж�


}

void UartSendChar(uchar uartData)
{
    SBUF = uartData;
    while(!TI); //�Ƿ������
    TI = 0; //�������
}

void UartSendString(uchar *string)
{
    while(*string!='\0')
    {
        SBUF = *string; //������A�͸�SBUF��������
        while(TI != 1);//�жϷ��ͱ�־λTI�����������ɣ�Ӳ������TI��־λ1
        TI = 0;  //TI��Ϊ0���Ա���һ�η���
        string++;
    }
}


#endif

