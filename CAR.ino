#include <Servo.h>
#define SensorPin A0
#define ServoPinLeft 3
#define ServoPinRight 8



Servo Servo1;
Servo Servo2;
int pos = 0;
int pos2 = 0;
int SensorValLeft = 0;
int SensorValRight = 0;
float PulseLength = 0.0;
const float Period = 0.02;
float DutyCycle = 0.0;

int lineSensor = 7;

int buzzer = A1;

int leftLight = 4;
int rightLight = 5;

float backwardsTimer = 0;

int trigPin = 13;    // TRIG pin
int echoPin = 12;    // ECHO pin


void setup() {
  
  Servo1.attach(ServoPinLeft);
  Servo2.attach(ServoPinRight);

  pinMode(buzzer, OUTPUT);
  
  pinMode(rightLight, OUTPUT);
  
  pinMode(leftLight, OUTPUT);
  
  Serial.begin(9600);

    // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);

  pinMode(lineSensor, OUTPUT);


}

void loop() {
  


  Serial.println(digitalRead(lineSensor));

  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  float duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  float distance_cm = 0.017 * duration_us;

  /* print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");*/

  delay(500);
  if(backwardsTimer > 0){
    
      digitalWrite(leftLight, HIGH);
    digitalWrite(rightLight, HIGH);
      tone(buzzer, 10000, 500);
  //0 = backward
  //1000 = forward
  //525 = stay still
  
  SensorValLeft = 0;

  //0 = forward
  //1000 = backward
  //525 = stay still

  SensorValRight = 1000;

    backwardsTimer -= 1;
    delay(100);
  
  }
 else if(distance_cm < 20 && distance_cm >= 10){
  
  //0 = backward
  //1000 = forward
  //525 = stay still
  
  delay(5);

  if(distance_cm < 20 && distance_cm >= 10){

  SensorValLeft = 0;

  //0 = forward
  //1000 = backward
  //525 = stay still

  SensorValRight = 0;

  tone(buzzer, 10000, 500);

  digitalWrite(leftLight, HIGH);
    digitalWrite(rightLight, LOW);
  }

  }
  else if(distance_cm < 10){
    delay(5);
    if(distance_cm < 10){    
    backwardsTimer = 3;}

  }
  else{
  digitalWrite(leftLight, HIGH);
    digitalWrite(rightLight, HIGH);
  //0 = backward
  //1000 = forward
  //525 = stay still
  
  SensorValLeft = 1000;

  //0 = forward.
  
  //1000 = backward
  //525 = stay still

  SensorValRight = 0;
    noTone(buzzer);
    
  }

  pos = map(SensorValLeft, 0, 1023, 0, 180);
  Servo1.write(pos);
  pos2 = map(SensorValRight, 0, 1023, 0, 180);
  Servo2.write(pos2);


  DutyCycle = -((PulseLength / pow(10,6)) / Period) * 100;



}
