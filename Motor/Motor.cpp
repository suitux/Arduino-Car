/*
  Motor.cpp - Motor library
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <arduino.h>
#include <Motor.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/**
 * Motor()
 * Constructor
 * @param int frontMotor  The pin that controls front direction of the motor
 * @param int backMotor   The pin that controls back direction of the motor
 * Inits the motor's pin
 * The motor inits stopped
 */
Motor::Motor(int frontMotor, int backMotor) {
  Motor::frontMotor = frontMotor;   //Setting the front motor...
  Motor::backMotor = backMotor;     //Setting the back motor...
  Motor::frontMotorState = false;   //Setting the state of the front motor...
  Motor::backMotorState = false;    //Setting the state of the back motor...

  pinMode(backMotor, OUTPUT);  //Control pins
  pinMode(frontMotor, OUTPUT);

  digitalWrite(backMotor, LOW);  //Motor shutted down at first init
  digitalWrite(frontMotor, LOW);
}

/******************************************************************************
 * User API
 ******************************************************************************/

/*   ________  ________________ __    __  _________________  ______  ____  _____
    / ____/ / / / ____/ ____/ //_/   /  |/  / ____/_  __/ / / / __ \/ __ \/ ___/
   / /   / /_/ / __/ / /   / ,<     / /|_/ / __/   / / / /_/ / / / / / / /\__ \ 
  / /___/ __  / /___/ /___/ /| |   / /  / / /___  / / / __  / /_/ / /_/ /___/ / 
  \____/_/ /_/_____/\____/_/ |_|  /_/  /_/_____/ /_/ /_/ /_/\____/_____//____/                                                                                
 */


/**
 * checkFront
 * @return bool If the motor its going in front returns true, else returns false
 */
bool Motor::checkFront() 
{
  if(frontMotorState && !backMotorState)   //If the front motor its running: 
    return true;
  else
    return false;
};

/**
 * checkBack
 * @return bool If the motor its going in back returns true, else returns false
 */
bool Motor::checkBack() 
{
  if(!frontMotorState && backMotorState) //If the back motor its running:
    return true; 
  else 
    return false;
};

/**
 * itsMoving
 * @return True: If the motor its on movement. False if the motor its stopped
 */
bool Motor::itsMoving() {
  if(checkFront() || checkBack())     //If front OR back motor are running: 
    return true;
  else
    return false;
}

/*  __  _______ _    __________  __________   ________   __  _________________  ______  ____  _____
   /  |/  / __ \ |  / / ____/  |/  / ____/ | / /_  __/  /  |/  / ____/_  __/ / / / __ \/ __ \/ ___/
  / /|_/ / / / / | / / __/ / /|_/ / __/ /  |/ / / /    / /|_/ / __/   / / / /_/ / / / / / / /\__ \ 
 / /  / / /_/ /| |/ / /___/ /  / / /___/ /|  / / /    / /  / / /___  / / / __  / /_/ / /_/ /___/ / 
/_/  /_/\____/ |___/_____/_/  /_/_____/_/ |_/ /_/    /_/  /_/_____/ /_/ /_/ /_/\____/_____//____/                                                                                              
 */

/**
 * goFront()
 * Motor go front with max velocity
 */
void Motor::goFront() {
  stop();                         //Stops the motor
  digitalWrite(backMotor, LOW);   //Goes to front: 
  digitalWrite(frontMotor, HIGH);
  frontMotorState = true;
  backMotorState = false;
}

/**
 * goBack()
 * Motor go back with max velocity
 */
void Motor::goBack() {
  stop();                         //Stops the motor
  digitalWrite(backMotor, HIGH);  //Goes to back:
  digitalWrite(frontMotor, LOW);
  frontMotorState = false;
  backMotorState = true;
}

/**
 * setFrontVelocity
 * @param velocity Velocity (0-255)
 * Motor go front with especified velocity
 */
void Motor::setFrontVelocity(int velocity) {
  stop();                             //Stops the motor
  analogWrite(frontMotor, velocity);  //Goes front with X velocity
  frontMotorState = true;
  backMotorState = false;
}

/**
 * setBackVelocity
 * @param velocity Velocity (0-255)
 * Motor go back with especified velocity
 */
void Motor::setBackVelocity(int velocity) {
  stop();                             //Stops the motor
  analogWrite(backMotor, velocity);   //Goes back with X velocity
  frontMotorState = false;
  backMotorState = true;
}

/**
 * stop()
 * Stops lowing the motor
 */
void Motor::stop() {
  digitalWrite(backMotor, LOW);  //Motor shutted down: 
  digitalWrite(frontMotor, LOW);
  frontMotorState = false;
  backMotorState = false;
}
