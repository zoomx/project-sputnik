/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com/
 on 10 Nov 2012.
 */


#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 400; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */ 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
  
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10); 
   
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   duration -= 5;
   
   //Calculate the distance (in cm) based on the speed of sound.
   distance = duration/76;
   //distance = duration*0.0343/2;
   //duration=us
   //speedofsound=33300 cm/s =  33,3 cm/ms=0.33 cm/us
   
   //distance= duration/2
   
//   if (distance >= maximumRange || distance <= minimumRange){
//     /* Send a negative number to computer and Turn LED ON 
//     to indicate "out of range" */
//     Serial.println("-1");
//     digitalWrite(LEDPin, HIGH); 
//   }
//   else {
//     /* Send the distance to the computer using Serial protocol, and
//     turn LED OFF to indicate successful reading. */
    Serial.println(distance);
     digitalWrite(LEDPin, LOW); 
//   }
   
   //Delay 50ms before next reading.
   delay(50);
}
