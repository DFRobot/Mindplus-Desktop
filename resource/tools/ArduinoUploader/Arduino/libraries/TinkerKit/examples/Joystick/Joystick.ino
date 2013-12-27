/*
 Joystick

 Reads two analog input pins; a T000030 Joystick Module Analog Sensor connected to I0 and I1,
 uses the result to set the brightness of two T010111 LED Module connected on O0 and O1.
 Also prints the results to the serial monitor.

 created  7 dec 2010
 by Davide Gomba 
 modified on Dec 2011
 by Federico Vanzati

 This example code is in the public domain.

 */

// include the TinkerKit library
#include <TinkerKit.h>

TKJoystick joystick(I0, I1);  // creating the object 'joystick' that belongs to the 'TKJoystick' class 
                       	      // and giving the values to the desired input pins

TKLed xLed(O0), yLed(O1);     // creating the objects 'xLed' & 'yLed' that both belongs to the 'TKLed' class 
                              // and giving the values to the desired output pins

int xAxisValue = 0;           // value read from the Joystick's x-axis 
int yAxisValue = 0;           // value read from the Joystick's y-axis

void setup() 
{
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop()
{
  // read the both joystick axis values:
  xAxisValue = joystick.getXAxis();  
  yAxisValue = joystick.getYAxis(); 

  // set the leds brightness
  xLed.brightness(xAxisValue);
  yLed.brightness(yAxisValue);

  // print the results to the serial monitor:
  Serial.print("Joystick X = " );                       
  Serial.print(xAxisValue);   
  Serial.print("\t Joystick Y = " );                       
  Serial.print(yAxisValue);     


  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);    
}

