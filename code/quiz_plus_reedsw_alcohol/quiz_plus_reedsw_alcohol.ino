#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
Servo servo;
int sensor = 3;
int pin_alcohol = A0;
int pin_btn = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);
  lcd.begin();
  pinMode(pin_btn,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int reedSW = digitalRead(sensor);
  int alcohol = analogRead(pin_alcohol);
  int btn = digitalRead(pin_btn)
  if(reedSW == LOW){
    servo.write(20);
    if(alcohol <=500){
      servo.write(90);
      }else if(alcohol){
          
      }
    
    }
}
