#ifndef _WIFI_H_
#define _WIFI_H

#include "define.h"
#include "serial.h"
void WifiInit()	  //��ʼ��wifi
{
    //WIfI����
//	UartSendString("WIFI config....,please open wifi\r\n");
//	UartSendString("AT\r\n");
//	delayxms(1000);
//    UartSendString("AT+CIOBAUD=115200\r\n");
//    delayxms(1000);
    UartSendString("AT+CWMODE=3\r\n"); //AP+STģʽ
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+RST\r\n");	 //��λ
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+CIPMUX=1\r\n"); //�����ӷ�ʽ
    delayxms(1000);
   delayxms(1000);
//    UartSendString("AT+CWSAP=\"UESTC\",\"12345678\",11,4\r\n"); //�������ƺ�����
//    delayxms(1000);

    UartSendString("AT+CIPSERVER=1,8080\r\n");	//����TCP���������˿�8080
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+CIPSTO=2880\r\n");	//���÷�������ʱʱ��
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+CIPSTART=1,'TCP'\r\n");
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+CIPSTATUS\r\n");
    delayxms(1000);
		 delayxms(1000);
}
#endif
