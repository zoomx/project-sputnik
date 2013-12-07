#include "Arduino.h"
#include "ultrasound.h"

Ultrasound::Ultrasound(int triggerpin, int echopin){
	pinMode(triggerpin, OUTPUT);
	pinMode(echopin, INPUT);
	_trigpin = triggerpin;
	_echopin = echopin;
  	Serial.println("Ultrasound initialized");
}


int Ultrasound::measure(){
	digitalWrite(_trigpin, LOW); 
	delayMicroseconds(2); 
	  
	digitalWrite(_trigpin, HIGH);
	delayMicroseconds(10); 
	   
	digitalWrite(_trigpin, LOW);
	int duration = pulseIn(_echopin, HIGH,10000);
	duration -= 5;
	   
	int distance = duration/76;
	Serial.println(distance);
	delay(50);
	if(distance == 0){
		distance = -1;
	}
	return distance;
}
