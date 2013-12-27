#include "TinkerKit.h"


/*
 * Buttons Class and Methods
 */  

TKButton::TKButton(uint8_t pin)
{
	_pin = pin;
	pinMode(_pin, INPUT);
	_toggleState = LOW;
	_oldState = LOW;
}

boolean TKButton::toggle()
{
	boolean currentState = TKButton::get();
	
	if( (currentState == HIGH) && (_oldState == LOW) )	
		_toggleState = !_toggleState;
	_oldState = currentState;
	
	return _toggleState;
}

boolean TKButton::pressed()
{
	boolean currentState = TKButton::get();
	
	if(currentState == HIGH && _oldState == LOW)
	{
		_oldState = currentState;
		delay(50);
		return true;
	}		
	else
		return false;
}

boolean TKButton::released()
{
	boolean currentState = TKButton::get();
	
	if(currentState == LOW && _oldState == HIGH)
	{
		_oldState = currentState;
		delay(50);
		return true;		
	}
	else
		return false;
}

boolean TKButton::held()
{	
	if(released() == LOW && _oldState == HIGH)
		return true;		
	else
		return false;
}
	
	
/*
 * Tilt Sensor Class and Methods
 */  
  
TKTiltSensor::TKTiltSensor(uint8_t pin) { _pin = pin; pinMode(_pin, INPUT); } 


/*
 * Touch Sensor Class and Methods
 */  
  
 TKTouchSensor::TKTouchSensor(uint8_t pin) : TKButton(pin) {} 
  
  
/*
 * Leds Class and Methods
 */  

TKLed::TKLed(uint8_t pin)
{ 
	_pin = pin;
	_state = LOW;
	pinMode(_pin, OUTPUT);
}


/*
 * Potentiometer Class and Methods
 */
  
TKPotentiometer::TKPotentiometer(uint8_t pin) { _pin = pin; }

 
/*
 * LightSensor Class and Methods
 */

TKLightSensor::TKLightSensor(uint8_t pin) { _pin = pin; }


/*
 * Thermistor Class and Methods
 */
  
TKThermistor::TKThermistor(uint8_t pin) { _pin = pin; }

float TKThermistor::getCelsius()
{
	float Rthermistor = Rb * (ADCres / TKThermistor::get() - 1);
	float _temperatureC = Beta / (log( Rthermistor * Ginf )) ;
		
	return _temperatureC - Kelvin;
}

float TKThermistor::getFahrenheit()
{
	float _temperatureF = (TKThermistor::getCelsius() * 9.0)/ 5.0 + 32.0; ;
	
	return _temperatureF;
}


/*
 * MosFet Class and Methods
 */
  
TKMosFet::TKMosFet(uint8_t pin)
{ 
	_pin = pin; 
	_state = LOW;
	pinMode(_pin, OUTPUT);
}


/*
 * Relay Class and Methods
 */
  
TKRelay::TKRelay(uint8_t pin) { _pin = pin; pinMode(_pin, OUTPUT);}


/*
 * Hall Sensor Class and Methods
 */

TKHallSensor::TKHallSensor(uint8_t pin) { _pin = pin;}

boolean TKHallSensor::polarity()
{ 
	int value = TKHallSensor::get();
	if( value >= _zeroValue  )
		return NORTH;
	else
		return SOUTH;
}

 /*
  * Joystick Class and Methods
  */
  
TKJoystick::TKJoystick(uint8_t pinX, uint8_t pinY)
{
	_pinX = pinX; _pinY = pinY;
}


 /*
  * Gyro Sensor Class and Methods
  */

TKGyro::TKGyro(uint8_t pinX, uint8_t pinY, boolean model) 
{
 	_pinX = pinX; _pinY = pinY;
 	_sensitivityInCount = 14633;  // 4.88mV / (0.167mV/dps * 2)
 	
 	if(model == TK_X4)
 		_sensitivityInCount /= 4;
	
  // default values 
  _xZeroVoltage = 503;	// 2.46V expressed in ADC counts
  _yZeroVoltage = 503;
}

void TKGyro::calibrate()
{  
	_xZeroVoltage = 0;	
	_yZeroVoltage = 0;

	for (uint8_t i=0; i<50; i++)
   {
   	_yZeroVoltage += analogRead(_pinY);
   	_xZeroVoltage += analogRead(_pinX);
   	delay(20);
   }
   _yZeroVoltage /= 50;	 
   _xZeroVoltage /= 50;	
}

long TKGyro::getXAxisRate()
{	
 	return ((long)(analogRead(_pinX) - _xZeroVoltage) * _sensitivityInCount) / 1000;
}
 
long TKGyro::getYAxisRate()
{
	return ((long)(analogRead(_pinY) - _yZeroVoltage) * _sensitivityInCount) / 1000;
}
 
 
 /*
  * Accelerometer Class and Methods
  */
  
TKAccelerometer::TKAccelerometer(uint8_t pinX, uint8_t pinY) { _pinX = pinX; _pinY = pinY; }

int TKAccelerometer::inclination()
{
	int xVal = analogRead(_pinX) - _zeroOffset;
	int yVal = analogRead(_pinY) - _zeroOffset;
	
	if(xVal <= 96 && yVal <= 96)
	{
		int inclination = atan2(xVal, yVal)*180/M_PI;
		return (int) inclination;
	} else {
		return NULL;
	}
}
