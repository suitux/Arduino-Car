/*
  Car.h - Car library
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

#ifndef Car_h
#define Car_h

#include <arduino.h>
#include <Buzzer.h>
#include <Motor.h>


class Car
{
  private:
    //Attributes 

    Motor   *motor;
    Buzzer  *claxon;

    bool debugMode;       //Debug mode

  public:
    //Constructors
    Car(Motor &motor);
    Car(Motor &motor, Buzzer &claxon);

    //Methods
      //Check methods
    void setDebugMode(bool);
    bool checkFront(); 
    bool checkBack();
    void stop();
    bool itsMoving();

      //Movement methods
    void goFront(); 
    void goBack();
    void setFrontVelocity(int);
    void setBackVelocity(int);
    
      //Miscellanious
    void startClaxon();
    void stopClaxon();
    void funnyClaxon();
    void changeClaxonTone(int);

};

#endif

