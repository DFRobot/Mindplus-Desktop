/*

 // # Update the library and sketch to compatible with IDE V1.0 and earlier
 
 // # Description:
 // # The sketch for using LCD12864 in serial mode(3-wire communication)

 // # Version: 0.2
 
 */

#ifndef LCD12864RSPI_h
#define LCD12864RSPI_h
#include <avr/pgmspace.h>
#include <inttypes.h>


class LCD12864RSPI {
typedef unsigned char uchar;


public:

LCD12864RSPI();

void Initialise(void);
void delayns(void);

void WriteByte(int dat);
void WriteCommand(int CMD);
void WriteData(int CMD);


void CLEAR(void);
void DisplayString(int X,int Y,uchar *ptr,int dat);
void DisplaySig(int M,int N,int sig);
void DrawFullScreen(uchar *p);
void img1(uchar img[]);
void img2(uchar img[]);

int delaytime;
int DEFAULTTIME;


static const int latchPin = 8; 		// Default driver pins 
static const int clockPin = 3;  
static const int dataPin = 9;  

};
extern LCD12864RSPI LCDA;    
#endif
