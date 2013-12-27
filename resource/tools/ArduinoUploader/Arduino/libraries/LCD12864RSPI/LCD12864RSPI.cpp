/*

 // # Update the library and sketch to compatible with IDE V1.0 and earlier
 
 // # Description:
 // # The sketch for using LCD12864 in serial mode(3-wire communication)

 // # Version: 0.2
 
 */

#include "LCD12864RSPI.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
extern "C" 
{
#include <wiring.h> 
#include <inttypes.h>
#include <stdio.h>  //not needed yet
#include <string.h> //needed for strlen()
#include <avr/pgmspace.h>
}
#endif


LCD12864RSPI::LCD12864RSPI() 
{
this->DEFAULTTIME = 80; // 80 ms default time
this->delaytime = DEFAULTTIME;
} 

//*********************延时函数************************//
void LCD12864RSPI::delayns(void)
{   
delayMicroseconds(delaytime);
 }


void LCD12864RSPI::WriteByte(int dat)
{
    digitalWrite(latchPin, HIGH);
    delayns();
    shiftOut(dataPin, clockPin, MSBFIRST, dat);
    digitalWrite(latchPin, LOW);
}


void LCD12864RSPI::WriteCommand(int CMD)
{
   int H_data,L_data;
   H_data = CMD;
   H_data &= 0xf0;           //屏蔽低4位的数据
   L_data = CMD;             //xxxx0000格式
   L_data &= 0x0f;           //屏蔽高4位的数据
   L_data <<= 4;             //xxxx0000格式
   WriteByte(0xf8);          //RS=0，写入的是指令；
   WriteByte(H_data);
   WriteByte(L_data);
}


void LCD12864RSPI::WriteData(int CMD)
{
   int H_data,L_data;
   H_data = CMD;
   H_data &= 0xf0;           //屏蔽低4位的数据
   L_data = CMD;             //xxxx0000格式
   L_data &= 0x0f;           //屏蔽高4位的数据
   L_data <<= 4;             //xxxx0000格式
   WriteByte(0xfa);          //RS=1，写入的是数据
   WriteByte(H_data);
   WriteByte(L_data);
}



void LCD12864RSPI::Initialise()
{
    pinMode(latchPin, OUTPUT);     
    pinMode(clockPin, OUTPUT);    
    pinMode(dataPin, OUTPUT);
    digitalWrite(latchPin, LOW);
    delayns();

    WriteCommand(0x30);        //功能设定控制字
    WriteCommand(0x0c);        //显示开关控制字
    WriteCommand(0x01);        //清除屏幕控制字
    WriteCommand(0x06);        //进入设定点控制字
}


void LCD12864RSPI::CLEAR(void)
{  
    WriteCommand(0x30);//
    WriteCommand(0x01);//清除显示
}


void LCD12864RSPI::DisplayString(int X,int Y,uchar *ptr,int dat)
{
  int i;

  switch(X)
   {
     case 0:  Y|=0x80;break;

     case 1:  Y|=0x90;break;

     case 2:  Y|=0x88;break;

     case 3:  Y|=0x98;break;

     default: break;
   }

  WriteCommand(Y); // 定位显示起始地址

  for(i=0;i<dat;i++)
    { 
      WriteData(ptr[i]);//显示汉字时注意码值，连续两个码表示一个汉字
    }
}

void LCD12864RSPI::DisplaySig(int M,int N,int sig)
{
  switch(M)
   {
     case 0:  N|=0x80;break;

     case 1:  N|=0x90;break;

     case 2:  N|=0x88;break;

     case 3:  N|=0x98;break;

     default: break;
   }
  WriteCommand(N); // 定位显示起始地址
  WriteData(sig); //输出单个字符
 }




void LCD12864RSPI::DrawFullScreen(uchar *p)
{
      int ygroup,x,y,i;
      int temp;
      int tmp;
             
      for(ygroup=0;ygroup<64;ygroup++)           //写入液晶上半图象部分
        {                           //写入坐标
           if(ygroup<32)
            {
             x=0x80;
             y=ygroup+0x80;
            }
           else 
            {
              x=0x88;
              y=ygroup-32+0x80;    
            }         
           WriteCommand(0x34);        //写入扩充指令命令
           WriteCommand(y);           //写入y轴坐标
           WriteCommand(x);           //写入x轴坐标
           WriteCommand(0x30);        //写入基本指令命令
           tmp=ygroup*16;
           for(i=0;i<16;i++)
		 {
		    temp=p[tmp++];
		    WriteData(temp);
               }
          }
        WriteCommand(0x34);        //写入扩充指令命令
        WriteCommand(0x36);        //显示图象
}



void LCD12864RSPI::img1(uchar img[])
{
    unsigned int i;
    unsigned char page,column;  

    for(page=0xB0;page<0xB4;page++)  
    {  
        WriteCommand(page);  //set page address   
        WriteCommand(0x10);  //set Column address MSB   
        WriteCommand(0x04);  //set column address LSB 
        
        i = (0xB3-page)*128;
        
        for(column=0;column<128;column++)  
        {  
            WriteData(~img[i+column]);  
        } 
    } 
        WriteCommand(0x34);        //写入扩充指令命令
        WriteCommand(0x36);        //显示图象 
}

void LCD12864RSPI::img2(uchar img[])
{
    unsigned int i;
    unsigned char page,column;  

    for(page=0xB4;page<0xB8;page++)  
    {  
        WriteCommand(page);  //set page address   
        WriteCommand(0x10);  //set Column address MSB   
        WriteCommand(0x04);  //set column address LSB 
        
        i = (0xB7-page)*128;
        
        for(column=0;column<128;column++)  
        {  
            WriteData(~img[i+column]);  
        } 
    }  
        WriteCommand(0x34);        //写入扩充指令命令
        WriteCommand(0x36);        //显示图象
}



LCD12864RSPI LCDA = LCD12864RSPI();