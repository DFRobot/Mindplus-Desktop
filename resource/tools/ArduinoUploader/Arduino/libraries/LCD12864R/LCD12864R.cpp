/*
LCD12864R
www.DFRobot.com
*/


#include "LCD12864R.h"
//#include "LCDSprite.h"


extern "C" 
{
#include <wiring.h> 
#include <inttypes.h>
#include <stdio.h>  //not needed yet
#include <string.h> //needed for strlen()
#include <avr/pgmspace.h>
}

LCD12864R::LCD12864R() 
{
this->DEFAULTTIME = 300; // 80 ms default time
this->delaytime = DEFAULTTIME;
} 


void LCD12864R::setPins(uint8_t tRS, uint8_t tRW, uint8_t tD7, uint8_t tD6, uint8_t tD5, uint8_t tD4, uint8_t tD3, uint8_t tD2, uint8_t tD1, uint8_t tD0) 
{
  digitalWrite(EN,1);  
  delayns();
  digitalWrite(RS, tRS);   
  digitalWrite(RW, tRW);   
  digitalWrite(D7, tD7);   
  digitalWrite(D6, tD6);   
  digitalWrite(D5, tD5);   
  digitalWrite(D4, tD4);   
  digitalWrite(D3, tD3);   
  digitalWrite(D2, tD2);   
  digitalWrite(D1, tD1);   
  digitalWrite(D0, tD0);   
  delayns();
  digitalWrite(EN, 0);   
  delayns();

}


//*********************延时函数************************//
void LCD12864R::delayns(void)
{   
delayMicroseconds(delaytime);
 }



void LCD12864R::VectorConverter(int vector) 
{
int result = vector;
for (int i = 7; i >= 0; i--) 
{
this->temp[i] = result % 2;
result = result/2;
}

}


void LCD12864R::WriteCommand(int CMD)
{ 
   delayns();
   delayns();
   VectorConverter(CMD); // lets get the binary from the dec
   setPins(0,0,this->temp[0],this->temp[1],this->temp[2],this->temp[3],this->temp[4],this->temp[5],this->temp[6],this->temp[7]); //WriteCommand

}



void LCD12864R::WriteData(int CMD)
{  
   delayns();
   delayns();
   VectorConverter(CMD); // lets get the binary from the dec
   setPins(1,0,this->temp[0],this->temp[1],this->temp[2],this->temp[3],this->temp[4],this->temp[5],this->temp[6],this->temp[7]); //WriteData
}


void LCD12864R::Initialise(void) 
{

   pinMode(RS, OUTPUT);     
   pinMode(RW, OUTPUT);    
   pinMode(EN, OUTPUT);     
   pinMode(D0, OUTPUT);      
   pinMode(D1, OUTPUT);    
   pinMode(D2, OUTPUT);   
   pinMode(D3, OUTPUT);      
   pinMode(D4, OUTPUT);      
   pinMode(D5, OUTPUT);      
   pinMode(D6, OUTPUT);      
   pinMode(D7, OUTPUT);
   delayns();

   WriteCommand(0x30);        //功能设定控制字
   WriteCommand(0x0c);        //显示开关控制字
   WriteCommand(0x01);        //清除屏幕控制字
   WriteCommand(0x06);        //进入设定点控制字
}



void LCD12864R::CLEAR(void)
{  
    WriteCommand(0x30);//
    WriteCommand(0x01);//清除显示
}



void LCD12864R::DisplayString(int X,int Y,uchar *ptr,int dat)
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



void LCD12864R::DisplaySig(int M,int N,int sig)
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




void LCD12864R::DrawFullScreen(uchar *p)
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


LCD12864R LCDA = LCD12864R();