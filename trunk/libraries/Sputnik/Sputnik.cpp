#include "Arduino.h"
#include "Sputnik.h"


Sputnik::Sputnik(){
}

Sputnik::Sputnik(int directionPin, int motorPin, int turnPin, int turnPowerPin){
	Sputnik(directionPin,motorPin,turnPin,turnPowerPin,false);
}

Sputnik::Sputnik(int _directionPin, int _motorPin, int _turnPin, int _turnPowerPin,boolean _verbose){
Serial.println ("Constructor");
	directionPin = directionPin;
	motorPin = motorPin;
	turnPin = turnPin;
	turnPowerPin = turnPowerPin;
	verbose = _verbose;

	pinMode(directionPin, OUTPUT); 
    	pinMode(motorPin, OUTPUT); 
    
    
    	pinMode(turnPin, OUTPUT); 
    	pinMode(turnPowerPin, OUTPUT);
 
}
 
void Sputnik::setup(){
	AFMS.begin();
	turnMotor->setSpeed(255);
}

void Sputnik::forward(){
	forward(150);
}

void Sputnik::forward(int speed){
	if(verbose){
		Serial.println("Vooruit");
	}
	mainMotor->setSpeed(speed);
 	mainMotor->run(FORWARD);
	
}

void Sputnik::backward(){
	backward(150);
}

void Sputnik::backward(int speed){
	if(verbose){
		Serial.println("Achteruit");
	}
	mainMotor->setSpeed(speed);
  	mainMotor->run(BACKWARD);

}

void Sputnik::turn(int dir){
	if(verbose){
		Serial.print("Turn ");
		Serial.println (dir);
	}
	if(dir){
		turnMotor->run(FORWARD);
	}
	else{
		turnMotor->run(BACKWARD);
	}
}

void Sputnik::neutral(){
	turnMotor->run(RELEASE);
}

void Sputnik::stopMoving(){
	stopMoving(1000);
}

void Sputnik::stopMoving(int stopTime){

	if(verbose){
		Serial.println("Stop");
	}
	mainMotor->run(RELEASE);
	delay(stopTime);
}

