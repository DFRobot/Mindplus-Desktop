#include <TinkerKit.h>

TKButton btn(I0);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(btn.pressed())
    Serial.println("The button is pressed"); 
  if(btn.held())
    Serial.println("The button is held"); 
  if(btn.released())
    Serial.println("The button is released"); 
}




