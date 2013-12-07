#include <Sputnik.h>

int echoPin =7; // Echo Pin
int trigPin =8; // Trigger Pin

int ledPort = 14;     // Led for sonar treshold. 

int onTime = 1000;  //the number of milliseconds for the motor to turn on for
int offTime = 1000; //the number of milliseconds for the motor to turn off for

int threshold = 100;  //In centimeters, the distance from objects where the car stops

Sputnik sputnik  (9,10,21,20,true);
void setup(){
  
  Serial.begin (9600);

  pinMode(ledPort, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {
  dummyRun();

  /*
  switch (dir) {
   case 1:
   forward();
   break;
   case 2:
   backward();
   break;
   default:
   stopMoving();
   break;
   }
   int dist = readSonar();
   if(dist < threshold && dist != -1 ){
   digitalWrite(ledPort, HIGH);
   if(dir != 2){
   stopMoving();
   }
   dir = 2;
   }else{
   digitalWrite(ledPort, LOW);
   if(dir != 1){
   stopMoving();
   }
   dir = 1;
   }*/
}

void dummyRun(){
  delay(1000);
  Serial.println("Begin dummyrun");
  sputnik.forward();
  delay(1000);
  sputnik.stopMoving();
  delay(1000);
  sputnik.backward();
  delay(1000);
  sputnik.stopMoving();
  sputnik.forward();
  sputnik.turn(1000, 0);
  sputnik.stopMoving();
  sputnik.backward();
  delay(1000);
  sputnik.stopMoving();
  sputnik.forward();
  sputnik.turn(1000, 1);
  sputnik.stopMoving();

  Serial.println("End dummyrun");

  Serial.println("*************************************");
}


int readSonar(){

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


