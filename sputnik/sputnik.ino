#include <Sputnik.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>



int echoPin =7; // Echo Pin
int trigPin =8; // Trigger Pin
int dir=1;
int ledPort = 14;     // Led for sonar treshold. 

int onTime = 1000;  //the number of milliseconds for the motor to turn on for
int offTime = 1000; //the number of milliseconds for the motor to turn off for

int threshold = 100;  //In centimeters, the distance from objects where the car stops
int numBackwards = 0;
Sputnik sputnik  (9,10,21,20,true);
void setup(){
  
  Serial.begin (9600);
  sputnik.setup();

  pinMode(ledPort, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {
  //dummyRun();

  
  switch (dir) {
   case 1:
       sputnik.forward();
       break;
   case 2:
       sputnik.backward();
       numBackwards ++;
           if(numBackwards > 100){
               dir = 1;
           }
       break;
   default:
       sputnik.stopMoving();
       break;
   }
   int dist = readSonar();
   if(dist < threshold && dist != -1 ){
       digitalWrite(ledPort, HIGH);
       sputnik.stopMoving();
       if(dir == 1){
           dir = 2;
       } else{
           dir = 1;
       }
   }
   
}

void dummyRun(){
  delay(1000);
  Serial.println("Begin dummyrun");
  sputnik.forward(200);
  delay(1000);
  sputnik.stopMoving();
  delay(1000);
  sputnik.backward(200);
  delay(1000);
  sputnik.stopMoving();
  delay(1000);
  sputnik.turn(0);
  sputnik.forward(255);
  delay(1000);
  sputnik.backward();
  delay(1000);
  sputnik.stopMoving();
  sputnik.neutral();
  delay(1000);
  sputnik.turn(1);
  sputnik.backward(255);
  delay(2000);
  sputnik.forward();
  delay(2000);
  sputnik.stopMoving();
  sputnik.neutral();
  delay(1000);
 
  //sputnik.stopMoving();
  //sputnik.backward();
  //delay(1000);
  //sputnik.stopMoving();
  //sputnik.forward();
  //sputnik.turn(1000, 1,100);
  //sputnik.stopMoving();

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
  Serial.println(distance);
  delay(50);
  if(distance ==0){
    distance = -1;
  }
  return distance;
}


