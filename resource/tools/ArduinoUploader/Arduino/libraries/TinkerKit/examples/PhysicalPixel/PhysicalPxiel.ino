#include <TinkerKit.h>

TKLed led(13);

int incomingByte;      // a variable to read incoming serial data

void setup()
{
  Serial.begin(9600);
}


void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      led.set(HIGH);
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      led.set(LOW);
    }
    if (incomingByte == 'S') {
      Serial.println(led.state(), DEC);
    }
  }
}

