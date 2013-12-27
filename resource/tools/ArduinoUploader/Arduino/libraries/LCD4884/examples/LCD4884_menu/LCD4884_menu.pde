/*
Modified by Lauren
version 0.3

Any suggestions are welcome.
E-mail: Lauran.pan@gmail.com

Editor     : Lauren from DFRobot
Date       : 06.01.2012

* Update the library and sketch to compatible with IDE V1.0 and earlier

*/

#include "LCD4884.h"
#include "DFrobot_bmp.h"
#include "DFrobot_chinese.h"

//keypad debounce parameter
#define DEBOUNCE_MAX 15
#define DEBOUNCE_ON  10
#define DEBOUNCE_OFF 3 

#define NUM_KEYS 5

#define NUM_MENU_ITEM	4

// joystick number
#define LEFT_KEY 0
#define CENTER_KEY 1
#define DOWN_KEY 2
#define RIGHT_KEY 3
#define UP_KEY 4

// menu starting points

#define MENU_X	10		// 0-83
#define MENU_Y	1		// 0-5


int  adc_key_val[5] ={
  50, 200, 400, 600, 800 };

// debounce counters
byte button_count[NUM_KEYS];
// button status - pressed/released
byte button_status[NUM_KEYS];
// button on flags for user program 
byte button_flag[NUM_KEYS];

// menu definition
char menu_items[NUM_MENU_ITEM][12]={
  "TEMPERATURE",
  "CHAR MAP",
  "BITMAP",
  "ABOUT"	
};

void (*menu_funcs[NUM_MENU_ITEM])(void) = {
  temperature,
  charmap,
  bitmap,
  about
};

char current_menu_item;


void setup()
{

  // setup interrupt-driven keypad arrays  
  // reset button arrays
  for(byte i=0; i<NUM_KEYS; i++){
    button_count[i]=0;
    button_status[i]=0;
    button_flag[i]=0;
  }

  // Setup timer2 -- Prescaler/256
  TCCR2A &= ~((1<<WGM21) | (1<<WGM20));
  TCCR2B &= ~(1<<WGM22);
  TCCR2B = (1<<CS22)|(1<<CS21);      

  ASSR |=(0<<AS2);

  // Use normal mode  
  TCCR2A =0;    
  //Timer2 Overflow Interrupt Enable  
  TIMSK2 |= (0<<OCIE2A);
  TCNT2=0x6;  // counting starts from 6;  
  TIMSK2 = (1<<TOIE2);    



  SREG|=1<<SREG_I;

  lcd.LCD_init();
  lcd.LCD_clear();

  //menu initialization
  init_MENU();
  current_menu_item = 0;	

  lcd.backlight(ON);//Turn on the backlight
  //lcd.backlight(OFF); // Turn off the backlight  
}


/* loop */

void loop()
{
  byte i;
  for(i=0; i<NUM_KEYS; i++){
    if(button_flag[i] !=0){

      button_flag[i]=0;  // reset button flag
      switch(i){

      case UP_KEY:
        // current item to normal display
        lcd.LCD_write_string(MENU_X, MENU_Y + current_menu_item, menu_items[current_menu_item], MENU_NORMAL );
        current_menu_item -=1;
        if(current_menu_item <0)  current_menu_item = NUM_MENU_ITEM -1;
        // next item to highlight display
        lcd.LCD_write_string(MENU_X, MENU_Y + current_menu_item, menu_items[current_menu_item], MENU_HIGHLIGHT );
        break;
      case DOWN_KEY:
        // current item to normal display
        lcd.LCD_write_string(MENU_X, MENU_Y + current_menu_item, menu_items[current_menu_item], MENU_NORMAL );
        current_menu_item +=1;
        if(current_menu_item >(NUM_MENU_ITEM-1))  current_menu_item = 0;
        // next item to highlight display
        lcd.LCD_write_string(MENU_X, MENU_Y + current_menu_item, menu_items[current_menu_item], MENU_HIGHLIGHT );
        break;
      case LEFT_KEY:
        init_MENU();
        current_menu_item = 0;
        break;   
      case CENTER_KEY:
        lcd.LCD_clear();
        (*menu_funcs[current_menu_item])();
        lcd.LCD_clear();
        init_MENU();
        current_menu_item = 0;           
        break;	
      }

    }
  }
}

/* menu functions */

void init_MENU(void){

  byte i;

  lcd.LCD_clear();

  lcd.LCD_write_string(MENU_X, MENU_Y, menu_items[0], MENU_HIGHLIGHT );

  for (i=1; i<NUM_MENU_ITEM; i++){
    lcd.LCD_write_string(MENU_X, MENU_Y+i, menu_items[i], MENU_NORMAL);
  }


}

// waiting for center key press
void waitfor_OKkey(){
  byte i;
  byte key = 0xFF;
  while (key!= CENTER_KEY){
    for(i=0; i<NUM_KEYS; i++){
      if(button_flag[i] !=0){
        button_flag[i]=0;  // reset button flag
        if(i== CENTER_KEY) key=CENTER_KEY;
      }
    }
  }

}

void temperature()
{
  lcd.LCD_write_string_big(10, 1, "+12.30", MENU_NORMAL);
  lcd.LCD_write_string(78, 2, "C", MENU_NORMAL);
  lcd.LCD_write_string(38, 5, "OK", MENU_HIGHLIGHT );
  waitfor_OKkey();
}

void charmap(){
  char i,j;
  for(i=0; i<5; i++){
    for(j=0; j<14; j++){
      lcd.LCD_set_XY(j*6,i);
      lcd.LCD_write_char(i*14+j+32, MENU_NORMAL);
    }
  }


  lcd.LCD_write_string(38, 5, "OK", MENU_HIGHLIGHT );
  waitfor_OKkey();   
}

void bitmap(){
  lcd.LCD_draw_bmp_pixel(0,0, DFrobot_bmp, 84,24);
  lcd.LCD_write_chinese(6,3, DFrobot_chinese,12,6,0,0);
  lcd.LCD_write_string(38, 5, "OK", MENU_HIGHLIGHT );
  waitfor_OKkey();
}


void about(){

  lcd.LCD_write_string( 0, 1, "LCD4884 Shield", MENU_NORMAL);
  lcd.LCD_write_string( 0, 3, "www.DFrobot.cn", MENU_NORMAL);
  lcd.LCD_write_string(38, 5, "OK", MENU_HIGHLIGHT );
  waitfor_OKkey();


}



// The followinging are interrupt-driven keypad reading functions
// which includes DEBOUNCE ON/OFF mechanism, and continuous pressing detection


// Convert ADC value to key number
char get_key(unsigned int input)
{
  char k;

  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < adc_key_val[k])
    {

      return k;
    }
  }

  if (k >= NUM_KEYS)
    k = -1;     // No valid key pressed

  return k;
}

void update_adc_key(){
  int adc_key_in;
  char key_in;
  byte i;

  adc_key_in = analogRead(0);
  key_in = get_key(adc_key_in);
  for(i=0; i<NUM_KEYS; i++)
  {
    if(key_in==i)  //one key is pressed 
    { 
      if(button_count[i]<DEBOUNCE_MAX)
      {
        button_count[i]++;
        if(button_count[i]>DEBOUNCE_ON)
        {
          if(button_status[i] == 0)
          {
            button_flag[i] = 1;
            button_status[i] = 1; //button debounced to 'pressed' status
          }

        }
      }

    }
    else // no button pressed
    {
      if (button_count[i] >0)
      {  
        button_flag[i] = 0;	
        button_count[i]--;
        if(button_count[i]<DEBOUNCE_OFF){
          button_status[i]=0;   //button debounced to 'released' status
        }
      }
    }

  }
}

// Timer2 interrupt routine -
// 1/(160000000/256/(256-6)) = 4ms interval

ISR(TIMER2_OVF_vect) {  
  TCNT2  = 6;
  update_adc_key();
}




