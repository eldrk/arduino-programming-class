#include <Servo.h>

Servo myservo;
int sensor = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reedSW = digitalRead(sensor);

  if(reedSW == LOW){
    myservo.write(20);
   }else{
    myservo.write(90);
   }
}
