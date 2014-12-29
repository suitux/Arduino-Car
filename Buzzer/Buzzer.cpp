/*
  Buzzer.cpp - Buzzer library
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <Buzzer.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

Buzzer::Buzzer(int buzzer) {
  Buzzer::buzzer = buzzer;                   //Setting the pin of the buzzer...
  Buzzer::buzzerValue = BUZZERDEFAULTVALUE;  //Setting the default value of the buzzer...
}

/******************************************************************************
 * User API
 ******************************************************************************/
/**
 * setbuzzerValue
 * @param value Value to set (0-255)
 * Set a new buzzer sound value. 
 * The default its set to 16
 */
void Buzzer::setBuzzerValue(int value) {
  int max = 254;    //Max buzzer value
  int min = 0;      //Min buzzer value
  if(value > max) {
    value = max;
  } else if(value < min) {
    value = min;
  } 
  Buzzer::buzzerValue = value;         //Sets the default value of the buzzer
}

/**
 * startbuzzer
 * Starts the buzzer
 */
void Buzzer::startBuzzer() {
  analogWrite(buzzer, Buzzer::buzzerValue);  //Starts the buzzer
}

/**
 * stopbuzzer
 * Stops the buzzer
 */
void Buzzer::stopBuzzer() {
  analogWrite(buzzer, 0);                 //Stops the buzzer
}

/**
 * funnybuzzer
 * Starts the buzzer printing a melody
 */
void Buzzer::funnyBuzzer() {
  int longer = 250;
  int shorter = 125;
  int space = 200;
  int shortest = 100;
  
  analogWrite(buzzer, 16);
  delay(longer);
  analogWrite(buzzer, 0);
  delay(longer);
  analogWrite(buzzer, 16);
  delay(longer);
  analogWrite(buzzer, 0);
  delay(longer);
  analogWrite(buzzer, 16);    //Pi pi pipipi
  delay(shorter);
  analogWrite(buzzer, 0);
  delay(shorter);
  analogWrite(buzzer, 16);
  delay(shorter);
  analogWrite(buzzer, 0);
  delay(shorter);
  analogWrite(buzzer, 16);
  delay(shorter);
  analogWrite(buzzer, 0);
  delay(shorter);
  
  delay(space);
  
  analogWrite(buzzer, 16);
  delay(shortest);
  analogWrite(buzzer, 0);
  delay(shortest);
  analogWrite(buzzer, 16);
  delay(shortest);
  analogWrite(buzzer, 0);     //pipipipi
  delay(shortest);
  analogWrite(buzzer, 16);
  delay(shortest);
  analogWrite(buzzer, 0);
  delay(shortest);
  analogWrite(buzzer, 16);
  delay(shortest);
  analogWrite(buzzer, 0);
  
  delay(longer);
  
  analogWrite(buzzer, 16);
  delay(shorter);
  analogWrite(buzzer, 0);
  delay(shorter);             //PiPi
  analogWrite(buzzer, 16);
  delay(shorter);
  analogWrite(buzzer, 0);
  delay(shorter);
}