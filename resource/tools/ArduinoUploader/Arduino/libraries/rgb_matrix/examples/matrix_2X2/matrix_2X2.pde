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

#define N_X 2
#define N_Y 2

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
    if((++counter)%10 == 0)
    {
        if(millis() - time >= 100)
        {
            time = millis();
            tick_100ms ++;
            if(tick_100ms%2 == 0)
            {
            }
            if(tick_100ms%5 == 0)
            {
            }
            if(tick_100ms%10 == 0)
            {
                M.move(LEFT,1,0);
            }
            if(tick_100ms%20 == 0)
            {
                M.move(RIGHT,1,1);
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
    int tmp,i;
    M.add_layer();
    M.put_char(0,0,'A',NO_ROT,MULTIPLY,RED,TOP_LAYER);
    M.put_char(5,0,'B',NO_ROT,MULTIPLY,GREEN,TOP_LAYER);
    M.put_char(10,0,'C',NO_ROT,MULTIPLY,BLUE,TOP_LAYER);
    
    M.put_char(0,8,'D',NO_ROT,MULTIPLY,GREEN+RED,1);
    M.put_char(5,8,'E',NO_ROT,MULTIPLY,RED+BLUE,1);
    M.put_char(10,8,'F',NO_ROT,MULTIPLY,BLUE+GREEN,1);
    M.display(hook);
}