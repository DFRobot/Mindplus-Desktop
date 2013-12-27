

#ifndef Metro_h
#define Metro_h

#include <inttypes.h>

class Metro
{

public:
  Metro(unsigned long interval_millis);
  Metro(unsigned long interval_millis, uint8_t autoreset);
  void interval(unsigned long interval_millis);
  char check();
  int checkTime();
  void reset();
	
private:
  uint8_t autoreset;
  unsigned long  previous_millis, interval_millis;

};

#endif


