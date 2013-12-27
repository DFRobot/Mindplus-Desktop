/***************************************************************************** 
*                Copyright:  ChengDu Geeker Tech. Co., Ltd. 
* File name:      hello_matrix.pde 
* Description:    test the function of rgb matrix
* Author:       wanghui_CD
* Version:      V1.0
* Date:         2012.06.21 
* History:      none
*****************************************************************************/
#include <rgb_matrix.h>
#include <SPI.h>

unsigned long time=0;
unsigned int tick_100ms = 0;
unsigned char counter=0;

#define N_X 1
#define N_Y 1

/*
//Interface shield ShiftOut connector 
#define DATA_PIN  9
#define CLK_PIN   3
*/
//Hardware SPI
#define DATA_PIN  11
#define CLK_PIN   13

#define LATCH_PIN 8

rgb_matrix M = rgb_matrix(N_X, N_Y, DATA_PIN, CLK_PIN, LATCH_PIN);

unsigned char cmd[50]={0},cmd_num=0;
unsigned char tmp =  'A';
unsigned char st=0;

void setup()
{
       Serial.begin(115200);
       delay(200);
}

/*************************************************************************                    
*  Description:
*                         display callback function
*        Receive AT comand via serial,and then run the right comand.
*        This function can be run in sweep interval.
*        Reduce delay time at function tail if screen blink.
*        Increase delay time at function tail if screen shows a double image.
* Param:   none
* Retval:  none 
**************************************************************************/
void hook(void)
{
    int i = 0;
    unsigned long enter_time,exit_time;
    enter_time = micros();
    if((++counter)%10 == 0)
    {
        if(millis() - time >= 100)
        {
            time = millis();
            tick_100ms ++;
            M.move(UP,1,0);
            if(tick_100ms%2 == 0)
            {
            }
            if(tick_100ms%5 == 0)
            {
                M.clear();
                M.put_char(0,0,tmp+(st++)%26,1,MULTIPLY,RED << (st%3),TOP_LAYER);
            }
            if(tick_100ms%10 == 0)
            {
            }
            if(tick_100ms%20 == 0)
            {
            }
            if(tick_100ms%50 == 0)
            {
            }
        }
    }
    if(Serial.available())
    {
        cmd[cmd_num++] = Serial.read();
        if((cmd_num>=2) && (cmd[cmd_num-1] == 0x0a) && (cmd[cmd_num-2] == 0x0d))
        {
            M.at_cmd(cmd);
            cmd_num = 0;
        }
     }
     exit_time = micros();
     if(enter_time < exit_time)
     {
       if(exit_time - enter_time < 500)
       {
         delayMicroseconds(500 - (exit_time-enter_time));
       }
     }
}

/*************************************************************************************                    
*  Description:
*                         loop function
*        Display function must be called.
*        If you wanna do something after display be called,
*    you should give display function a parameter which is a pointer to a function.
* Param:   none
* Retval:  none 
**************************************************************************************/
void loop()
{
    M.set_cur(0,0);   
    M.display(hook);
}