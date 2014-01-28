#include <AutonomousStrategy.h>

AutonomousStrategy::AutonomousStrategy(Sputnik _sputnik): ControllerStrategy( _sputnik){
	AutonomousStrategy(_sputnik, 14, 7,8);
}

AutonomousStrategy::AutonomousStrategy(Sputnik _sputnik, int _ledPin, int _echoPin, int _trigPin): ControllerStrategy( _sputnik){

	ledPin = _ledPin;
	echoPin = _echoPin;
	trigPin = _trigPin;

	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

  	pinMode(ledPin, OUTPUT); 
	Serial.println(  "AutonomousStrategy");
}

void AutonomousStrategy::run(){
	Serial.println(  "run AutonomousStrategy");

	switch (dir) {
		case 1:
			sputnik.forward();
			break;
		case 2:
			sputnik.backward();
			break;
			default:
			sputnik.stopMoving();
			break;
		}
		int dist = readSonar();
		if(dist < threshold && dist != -1 ){
			digitalWrite(ledPin, HIGH);
			if(dir != 2){
				sputnik.stopMoving();
			}
			dir = 2;
		}else{
			digitalWrite(ledPin, LOW);
			if(dir != 1){
				sputnik.stopMoving();
			}
			dir = 1;
		}
}


int AutonomousStrategy::readSonar(){

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 

  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH,10000);
  duration -= 5;

  int distance = duration/76;
  //Serial.println(distance);
  delay(50);
  if(distance ==0){
    distance = -1;
  }
  return distance;
}


