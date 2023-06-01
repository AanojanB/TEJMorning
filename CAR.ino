#include <Servo.h>
#define SensorPin A0
#define ServoPin 3
#define PulsePin 4

Servo Servo1;
int pos = 0;
int SensorVal = 0;
float PulseLength = 0.0;
const float Period = 0.02;
float DutyCycle = 0.0;

void setup() {
  
  Servo1.attach(ServoPin);
  pinMode(PulsePin, INPUT);
  Serial.begin(9600);


}

void loop() {
  
  //0 = forward
  //1000 = backward
  //525 = stay still
  
  SensorVal = 0;
  pos = map(SensorVal, 0, 1023, 0, 180);
  Servo1.write(pos);

  PulseLength = pulseIn(PulsePin, HIGH);
  DutyCycle = -((PulseLength / pow(10,6)) / Period) * 100;

Serial.println(analogRead(SensorPin));

}
