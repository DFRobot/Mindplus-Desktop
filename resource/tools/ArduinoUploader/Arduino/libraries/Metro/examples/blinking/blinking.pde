/*
 This code will blink an LED attached to pin 13 on and off. 
 It will stay on for 0.25 seconds.
 It will stay off for 1 second.
 */
#include <Metro.h> //Include Metro library
#define LED 13 // Define the led's pin

//Create a variable to hold theled's current state
int state = HIGH;

// Instanciate a metro object and set the interval to 250 milliseconds (0.25 seconds).
Metro ledMetro = Metro(250); 

void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,state);
}

void loop()
{

  if (ledMetro.check() == 1) { // check if the metro has passed its interval .
    if (state==HIGH)  { 
      state=LOW;
      ledMetro.interval(250); // if the pin is HIGH, set the interval to 0.25 seconds.
    } 
    else {
      ledMetro.interval(1000); // if the pin is LOW, set the interval to 1 second.
      state=HIGH;
    }
    digitalWrite(LED,state);
  }
}

