#include "Arduino.h"
#include "Sputnik.h"

Sputnik::Sputnik(int directionPin, int motorPin, int turnPin, int turnPowerPin){
	Sputnik(directionPin,motorPin,turnPin,turnPowerPin,false);
}

Sputnik::Sputnik(int _directionPin, int _motorPin, int _turnPin, int _turnPowerPin,boolean _verbose){
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


void Sputnik::forward(){
	if(verbose){
		Serial.println("Vooruit");
	}
	digitalWrite(motorPin, HIGH); // turns the motor On
	digitalWrite(directionPin, HIGH); // turns the motor On
}

void Sputnik::backward(){
	if(verbose){
		Serial.println("Achteruit");
	}
	digitalWrite(motorPin, HIGH); // turns the motor On
	digitalWrite(directionPin, LOW); // turns the motor On
}

void Sputnik::turn(int turnTime, int dir){
	if(verbose){
		Serial.println("Turn " + dir);
	}
	digitalWrite(turnPin,255 * dir); // if dir=0, LOW, if 1, HIGH
	digitalWrite(turnPowerPin,HIGH);

	delay(turnTime);
	digitalWrite(turnPowerPin,LOW);
}

void Sputnik::stopMoving(){
	stopMoving(1000);
}

void Sputnik::stopMoving(int stopTime){

	if(verbose){
		Serial.println("Stop");
	}
	digitalWrite(motorPin, LOW); // turns the motor On
	delay(stopTime);
}

