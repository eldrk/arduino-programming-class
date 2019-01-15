#include <Servo.h>

Servo myservo;
int detect = 7;
int input = LOW;
int count;
int red_pin = 13;
int green_pin = 12;
int blue_pin = 11;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(8);
  pinMode(detect,INPUT);
  pinMode(red_pin,OUTPUT);
  pinMode(green_pin,OUTPUT);
  pinMode(blue_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   input = digitalRead(detect);
   if(input == HIGH){
    Serial.println("Motion detected!");
    count++;
//    setColor(LOW,HIGH,255);
//    delay(1000);
//    setColor(HIGH,LOW,255);
//    delay(1000);
//    setColor(HIGH,HIGH,0);
//    delay(1000);
//    setColor(LOW,LOW,0);  
     myservo.write(90);
     Serial.print("count : ");
     Serial.println(count);
    }else{
     Serial.println("Motion end!");
      myservo.write(0);
    }
    delay(500);

}

void setColor(int red, int green, int blue){
    digitalWrite(red_pin,red);
    digitalWrite(green_pin,green);
    analogWrite(blue_pin,blue);
  }
