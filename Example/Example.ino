/*
  Car.ino - Car 
  Copyright (c) 2014 by Xavier Rincon Rico.  All Rights Reserved.
*/

#include "Car.h"
#include "Buzzer.h"
#include "Motor.h"



int front = 5;   //Motor's pin
int back  = 6;   //Motor's pin (The same motor)
int buzzer  = 3;   //Claxon's pin

Motor motor = Motor(front, back);
Buzzer claxon = Buzzer(buzzer);

Car car = Car(motor, claxon);

void setup() {  
	car.goFront();		//Going front for 2 seconds:
	delay(2000);	
	car.stop();			//Stoping...
	
	car.startClaxon();	//Starting claxon for 0.5 seconds: 
	delay(500);
	car.stopClaxon();	//Stoping the claxon...
	
}

void loop() {

}