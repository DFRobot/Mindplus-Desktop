// This code will blink output 13 every 250 ms
// abd will blink output 9 every 125 ms


#include <Metro.h> // Include Metro library
#define LED0 13 // Define a LED pin
#define LED1 9 // Define another LED pin

// Create variables to hold the LED states
int state0 = HIGH;
int state1 = HIGH;

// Instantiate a metro object and set the interval to 250 milliseconds (0.25 seconds).
Metro metro0 = Metro(500); 

// Instantiate another metro object and set the interval to 125 milliseconds (0.125 seconds).
Metro metro1 = Metro(125); 

void setup()
{
  pinMode(LED0,OUTPUT);
  digitalWrite(LED0,state0);
  
   pinMode(LED1,OUTPUT);
  digitalWrite(LED1,state1);
  
}

void loop()
{

  if (metro0.check() == 1) { // check if the metro has passed its interval .
    if (state0==HIGH)  { 
      state0=LOW;
    } else {
      state0=HIGH;
    }
    digitalWrite(LED0,state0);
  }
  
   if (metro1.check() == 1) { // check if the metro has passed its interval .
    if (state1==HIGH)  { 
      state1=LOW;
    } else {
      state1=HIGH;
    }
    digitalWrite(LED1,state1);
  }
  
  
}
