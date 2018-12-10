#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sound_pin = A0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);

  
  Serial.println("sound_value : ");
  Serial.println(sound_value);
  
  if(sound_value>0 && sound_value<=1023){
    lcd.print("o(>a<)o");
    delay(1000);
    lcd.home();
    for(int i=1;i<=1023;i++){
      lcd.scrollDisplayRight();
      delay(1000);
      }
    
    
    }

}
