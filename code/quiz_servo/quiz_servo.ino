#include <Servo.h>

Servo myservo;
int btn = 8;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(btn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn)==1){
    int val = analogRead(A0);
    Serial.println(val);
    int rad = map(val,0,1023,0,180);
    myservo.write(rad);
    delay(15);
    }
}
