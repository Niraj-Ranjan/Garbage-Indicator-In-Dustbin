#include <Servo.h>. 


// Defines Tirg and Echo pins of the Ultrasonic Sensor

const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance

long duration;
int distance=0;
int thresh [3] = {20,12,4};


void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

 // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  Serial.println(distance);


  if (distance <= thresh[0] && distance >= thresh[1] && distance >= thresh[2]){
    digitalWrite(4, HIGH); 
    Serial.println(1);
  } else if (distance <= thresh[0] && distance <= thresh[1] && distance >= thresh[2]){
    digitalWrite(4, HIGH); 
    digitalWrite(3, HIGH); 
    Serial.println(2);
  } else if (distance <= thresh[0] && distance <= thresh[1] && distance <= thresh[2]){
    digitalWrite(4, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(2, HIGH); 
    Serial.println(3);
  } else {
    digitalWrite(4, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(2, LOW); 
    Serial.println(0);
  }
  
  delay(100);
}


  

