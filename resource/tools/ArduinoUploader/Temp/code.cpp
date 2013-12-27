
#include "Arduino.h"

boolean KitButton_0_1ON = true;
boolean KitButton_0_1OFF = false;
boolean KitLED_1_1ON = false;
boolean KitLED_1_1OFF = false;
int Null;
int LocalParameter_0 = 3;
int LocalParameter_1 = 0;
int LocalParameter_2 = 5;
int KitButton_0_1ON_SelfLoop = 0;
int KitButton_0_1ON_Pressed = 0;
unsigned long KitButton_0_1ON_time = 0;
void setup(){
Serial.begin(115200); 
}
void loop(){
if (KitButton_0_1ON){ 
  KitButton_0_1ON_SelfLoop = 1; //BB自循环开启
  KitButton_0_1ON = false;
}

if (KitButton_0_1OFF){
  KitButton_0_1ON_SelfLoop = 0; //BB自循环关闭
  KitButton_0_1OFF = false; 
}

if (KitButton_0_1ON_SelfLoop){
  if (LocalParameter_1 == 0 || (millis() - KitButton_0_1ON_time) > LocalParameter_1){
    pinMode(LocalParameter_0,INPUT_PULLUP);
    if (digitalRead(LocalParameter_0) == LOW){
      if (KitButton_0_1ON_Pressed == 0){
        KitLED_1_1ON = true; //Multi Variable To MultiLine 

        KitButton_0_1ON_Pressed = 1;

        KitButton_0_1ON_time = millis();
      }
      int LocalVar_KitButton_0_1ON = 1;
      
    }else{
      if (KitButton_0_1ON_Pressed == 1){
        KitLED_1_1OFF = true; //Multi Variable To MultiLine 

      }

      KitButton_0_1ON_Pressed = 0;

      int LocalVar_KitButton_0_1ON = 0;
      
    }
  }
}
if (KitLED_1_1ON){ 
pinMode(LocalParameter_2,OUTPUT); 
digitalWrite(LocalParameter_2, HIGH);
KitLED_1_1ON = false;

}
if (KitLED_1_1OFF){
pinMode(LocalParameter_2,OUTPUT); 
digitalWrite(LocalParameter_2, LOW);
KitLED_1_1OFF = false;

}
}
