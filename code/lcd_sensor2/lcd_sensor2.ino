#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int trig_pin = 2;
int echo_pin = 3;

void setup() {

  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

}

void loop() {

   digitalWrite(2,HIGH);
   delayMicroseconds(10);
   digitalWrite(2,LOW);
   long duration = pulseIn(3,HIGH);
   long distance = duration/58.2;
   Serial.println(distance);
   lcd.clear();

   lcd.home();
   lcd.print("distance value : ");
   lcd.setCursor(0,1);
   lcd.print(distance);
   delay(1000);

  
   

}

    
    
