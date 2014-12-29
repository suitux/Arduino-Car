/*
  Motor.h - Motor library
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

#ifndef Motor_h
#define Motor_h

#include <arduino.h>

class Motor
{
  private:
    //Attributes 
    int frontMotor;       //Front motor pin
    int backMotor;        //Back motor pin
    bool frontMotorState; //State of the front motor
    bool backMotorState;  //State of the back motor

  public:
    //Constructors
    Motor(int frontMotor, int backMotor);
    
    //Methods
      //Check methods
    bool checkFront(); 
    bool checkBack();
    void stop();
    bool itsMoving();

      //Movement methods
    void goFront(); 
    void goBack();
    void setFrontVelocity(int);
    void setBackVelocity(int);

};

#endif

