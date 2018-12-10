#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  
  lcd.begin();
  lcd.backlight();
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}

void loop() {
  
   digitalWrite(2,HIGH);
   delayMicroseconds(10);
   digitalWrite(2,LOW);
   long duration = pulseIn(3,HIGH);
   long distance = duration/58.2;
   int light = analogRead(A0);
   Serial.println(distance);
   delay(1000);

   if(digitalRead(4)==1){
    lcd.clear();
    lcd.home();
    lcd.print("distance value : ");
    lcd.setCursor(0,1);
    lcd.print(distance);

    }else if(digitalRead(7)==1){

      lcd.clear();
      lcd.home();
      lcd.print("light value : ");
      lcd.setCursor(0,1);
      lcd.print(light);
     }else{
      lcd.clear();
      }
}
