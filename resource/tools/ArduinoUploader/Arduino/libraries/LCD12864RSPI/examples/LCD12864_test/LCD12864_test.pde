/*

 // # Update the library and sketch to compatible with IDE V1.0 and earlier
 
 // # Description:
 // # The sketch for using LCD12864 in serial mode
 
 // # Arduino Connection:
 // # PIN1 = GND
 // # PIN2 = 5V
 // # RS(CS) = 8; 
 // # RW(SID)= 9; 
 // # EN(CLK) = 3;
 // # PIN15 PSB = GND;
*/

#include "LCD12864RSPI.h"
#include "DFrobot_bmp.h"
#include "DFrobot_char.h"

#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )

unsigned char wangzhi[]=" www.DFRobot.cn ";//

unsigned char en_char1[]="ST7920 LCD12864 ";// 

unsigned char en_char2[]="Test, Copyright ";// 

unsigned char en_char3[]="by DFRobot ---> ";// 

void setup()
{
  LCDA.Initialise(); // INIT SCREEN
  delay(100);
  LCDA.DrawFullScreen(logo);//LOGO
  delay(5000);
}

void loop()
{
LCDA.CLEAR();//Clear screen
delay(100);
LCDA.DisplayString(0,0,en_char1,16);//
delay(10);
LCDA.DisplayString(1,0,en_char2,16);//
delay(10);
LCDA.DisplayString(2,0,en_char3,16);//
delay(10);
LCDA.DisplayString(3,0,wangzhi,16);//
delay(5000);
LCDA.CLEAR();//Clear screen
delay(100);
LCDA.DisplayString(0,0,show1,16);//
delay(10);
LCDA.DisplayString(1,0,show2,16);//
delay(10);
LCDA.DisplayString(2,0,show3,16);//
delay(10);
LCDA.DisplayString(3,0,wangzhi,16);//LOGO
delay(5000);
}
