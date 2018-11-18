#ifndef _WIFI_H_
#define _WIFI_H

#include "define.h"
#include "serial.h"
void WifiInit()	  //初始化wifi
{
    //WIfI配置
//	UartSendString("WIFI config....,please open wifi\r\n");
//	UartSendString("AT\r\n");
//	delayxms(1000);
//    UartSendString("AT+CIOBAUD=115200\r\n");
//    delayxms(1000);
    UartSendString("AT+CWMODE=3\r\n"); //AP+ST模式
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+RST\r\n");	 //复位
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+CIPMUX=1\r\n"); //多连接方式
    delayxms(1000);
   delayxms(1000);
//    UartSendString("AT+CWSAP=\"UESTC\",\"12345678\",11,4\r\n"); //设置名称和密码
//    delayxms(1000);

    UartSendString("AT+CIPSERVER=1,8080\r\n");	//建立TCP服务器，端口8080
    delayxms(1000);
   delayxms(1000);
    UartSendString("AT+CIPSTO=2880\r\n");	//设置服务器超时时间
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
