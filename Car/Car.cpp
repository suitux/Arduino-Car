/*
  Car.cpp - Car library
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <arduino.h>
#include <Car.h>
#include <Buzzer.h>
#include <Motor.h>


/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/**
 * Car()
 * Constructor
 * @param int frontMotor  The pin that controls front direction of the motor
 * @param int backMotor   The pin that controls back direction of the motor
 * Inits the motor's pin of the car
 * The car inits stoped
 * The car inits with debug mode stopped
 */
Car::Car(Motor &motor) {
  Car::motor = &motor;             //Setting the motor for the car...
  Car::debugMode = false;         //Setting debug mode to false...
}

/**
 * Car()
 * Constructor
 * @param int frontMotor  The pin that controls front direction of the motor
 * @param int backMotor   The pin that controls back direction of the motor
 * @param Buzzer claxon   The claxon for the car
 * Inits the motor's pin of the car
 * The car inits stoped
 * The car inits with debug mode stopped
 */
Car::Car(Motor &motor, Buzzer &claxon) {
  Car::motor = &motor;             //Setting the motor for the car...
  Car::debugMode = false;         //Setting debug mode to false...
  Car::claxon = &claxon;         //Setting the claxon for the car...

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
 * setDebugMode
 * @param debug If yes or not
 * Sets the car in debug mode to print in serial console information
 * If the debug mode its already setted, informs to the user
 */
void Car::setDebugMode(bool debug) {
  if(Car::debugMode) {    //If debug mode its already setted ON: 
    Serial.println("Debug mode is already been setted ON");
  } else {                //If not:
    if(debug) {               //If debug: 
      Car::debugMode = true;  //Turn debug mode ON
      Serial.begin(9600);     //Init Serial
        //Prints the car information: 
      Serial.println("Using Car library.");
      Serial.println("Created by: Xavier Rincon Rico");       
      Serial.println("Version: 0.1");
    } else {
      Car::debugMode = false; //Turn debug mode OFF
      Serial.end();           //Ends serial
    }
  }
}

/**
 * checkFront
 * @return bool If the car its going in front returns true, else returns false
 */
bool Car::checkFront() 
{
  if(debugMode) Serial.println("Checking front...");
  return motor->checkFront();
};

/**
 * checkBack
 * @return bool If the car its going in back returns true, else returns false
 */
bool Car::checkBack() 
{
  if(debugMode) Serial.println("Checking back...");
  return motor->checkBack();
};

/**
 * itsMoving
 * @return True: If the car its on movement. False if the car its stopped
 */
bool Car::itsMoving() {
  if(debugMode) Serial.println("Checking if car moves:");
  return motor->itsMoving();
}

/*  __  _______ _    __________  __________   ________   __  _________________  ______  ____  _____
   /  |/  / __ \ |  / / ____/  |/  / ____/ | / /_  __/  /  |/  / ____/_  __/ / / / __ \/ __ \/ ___/
  / /|_/ / / / / | / / __/ / /|_/ / __/ /  |/ / / /    / /|_/ / __/   / / / /_/ / / / / / / /\__ \ 
 / /  / / /_/ /| |/ / /___/ /  / / /___/ /|  / / /    / /  / / /___  / / / __  / /_/ / /_/ /___/ / 
/_/  /_/\____/ |___/_____/_/  /_/_____/_/ |_/ /_/    /_/  /_/_____/ /_/ /_/ /_/\____/_____//____/                                                                                              
 */

/**
 * goFront()
 * Car go front with max velocity
 */
void Car::goFront() {
  if(debugMode) Serial.println("Going front...");
  motor->goFront();
}

/**
 * goBack()
 * Car go back with max velocity
 */
void Car::goBack() {
  if(debugMode) Serial.println("Going back...");
  motor->goBack();
}

/**
 * setFrontVelocity
 * @param velocity Velocity (0-255)
 * Car go front with especified velocity
 */
void Car::setFrontVelocity(int velocity) {
  if(debugMode) {
    Serial.print("Going front with value: ");
    Serial.println(velocity);
  }
  motor->setFrontVelocity(velocity);
}

/**
 * setBackVelocity
 * @param velocity Velocity (0-255)
 * Car go back with especified velocity
 */
void Car::setBackVelocity(int velocity) {
  if(debugMode) {
    Serial.print("Going back with value: ");
    Serial.println(velocity);
  }
  motor->setBackVelocity(velocity);
}

/**
 * stop()
 * Stops the car lowing the motors
 */
void Car::stop() {
  if(debugMode) Serial.println("Stopping car...");
  motor->stop();
}

/*    ________  ___   ___   ____  __   __  _________________  ______  ____  _____
     / ____/ / / / | / / | / /\ \/ /  /  |/  / ____/_  __/ / / / __ \/ __ \/ ___/
    / /_  / / / /  |/ /  |/ /  \  /  / /|_/ / __/   / / / /_/ / / / / / / /\__ \ 
   / __/ / /_/ / /|  / /|  /   / /  / /  / / /___  / / / __  / /_/ / /_/ /___/ / 
  /_/    \____/_/ |_/_/ |_/   /_/  /_/  /_/_____/ /_/ /_/ /_/\____/_____//____/                                                                         
 */

/**
 * startClaxon
 * Starts the claxon of the car
 */
void Car::startClaxon() {
  if(debugMode) Serial.println("Starting claxon...");
  claxon->startBuzzer();
}

/**
 * stopClaxon
 * Stops the claxon of the car
 */
void Car::stopClaxon() {
  if(debugMode) Serial.println("Stopping claxon...");
  claxon->stopBuzzer();
}

/**
 * funnyClaxon
 * Prints a melody with the claxon
 */
void Car::funnyClaxon() {
  if(debugMode) Serial.println("Starting a melody with claxon...");
  claxon->funnyBuzzer();
}

/**
 * changeClaxonTone
 * @param tone Tone to change
 * Changes the claxon's tone. The tones are from 0 to 254
 */
void Car::changeClaxonTone(int tone) {
  if(debugMode) {
    Serial.print("Setting claxon tone to: ");
    Serial.print(tone);
  }
  claxon->setBuzzerValue(tone);
}