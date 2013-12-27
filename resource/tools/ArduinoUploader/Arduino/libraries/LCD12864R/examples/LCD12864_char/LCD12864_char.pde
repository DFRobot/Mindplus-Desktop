/*
LCD  Arduino
RS = 17; Analog Pin3
RW = 16; Analog Pin2
EN = 18; Analog Pin4
D0  = 8; 
D1  = 9;
D2  = 10; 
D3  = 11; 
D4  = 4;
D5  = 5; 
D6  = 6; 
D7  = 7;
PIN15 PSB = 5V;
*/

#include "LCD12864R.h"
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )

unsigned char show0[]={0xBB,0xFA,0xC6,0xF7,0xC8,0xCB,0xC3,0xCE,0xB9,0xA4,0xB3,0xA7};//机器人梦工厂
unsigned char show1[]="www.dfrobot.com";//
 
void setup()
{
LCDA.Initialise(); // INIT SCREEN
delay(100);
}

void loop()
{
LCDA.CLEAR();//清屏
delay(100);
LCDA.DisplaySig(0,0,0x20);//显示一个空格
delay(100);
LCDA.DisplayString(0,1,show0,AR_SIZE(show0));//LOGO
delay(100);
LCDA.DisplayString(2,0,show1,AR_SIZE(show1));;//LOGO
while(1);
}