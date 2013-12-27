/*
 Accelerometer

 Reads two analog input pins; a T000020 Accelerometer Module with the x-axis connected to I0 pin
 the y-axis connected to the I1 pin, uses the result to set the brightness of two T010111 LED Module 
 connected on O0 and O1. Also prints the results to the serial monitor.

 created on Dec 2011
 by Federico Vanzati

 This example code is in the public domain.

 */

// include the TinkerKit library
#include <TinkerKit.h>

TKAccelerometer accelerometer(I0, I1);  // creating the object 'accelerometer' that belongs to the 'TKAccelerometer' class 
                       	      		// and giving the values to the desired input pins

TKLed xLed(O0), yLed(O1);     		// creating the objects 'xLed' & 'yLed' that both belongs to the 'TKLed' class 
                              		// and giving the values to the desired output pins

int xAxisValue = 0;           // value read from the accelerometer's x-axis 
int yAxisValue = 0;           // value read from the accelerometer's y-axis

void setup() 
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  // read the both joystick axis values:
  xAxisValue = accelerometer.getXAxis();  
  yAxisValue = accelerometer.getYAxis(); 

  // set the leds brightness
  xLed.brightness(xAxisValue);
  yLed.brightness(yAxisValue);

  // print the results to the serial monitor:
  Serial.print("Accelerometer X = " );                       
  Serial.print(xAxisValue);   
  Serial.print("\t Accelerometer Y = " );                       
  Serial.print(yAxisValue);     


  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);    
}

