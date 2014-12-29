/*
  Buzzer.h - Buzzer library
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

#ifndef Buzzer_h
#define Buzzer_h
#define BUZZERDEFAULTVALUE 16

#include <arduino.h>

class Buzzer
{
  private:
    //Attributes 
    int buzzer;			//The pin of the buzzer
    int buzzerValue;    //Buzzer value for the buzzer

  public:
    //Constructors
  	Buzzer(int buzzer);
    //Methods
  	void setBuzzerValue(int);
    void startBuzzer();
    void stopBuzzer();
    void funnyBuzzer();
};

#endif

