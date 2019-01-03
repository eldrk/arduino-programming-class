#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
int btn = 8;
int pin_alcohol = A0;

volatile byte state = 0;
int alcohol = analogRead(pin_alcohol);
int result = map(alcohol,0,1023,0,255);
int count;
double sum;
double avg;

void setup() {
  // put your setup code here, to run once:
    lcd.begin();
    lcd.backlight();
    pinMode(btn,INPUT);
    Serial.begin(9600);
    
    attachInterrupt(0,btn1ISR,RISING);    
}

void loop() {
  // put your main code here, to run repeatedly: 

    if(state == 1){
      while(count<10){
        sum += alcohol;
        count++;
       Serial.print("count : ");
       Serial.println(count);
       Serial.print("sum : ");
       Serial.println(sum);
      delay(1000);
      }

      if(count==10){
        avg = sum/10;
        state = 0;
       Serial.print("avg : ");
       Serial.println(avg);
       Serial.print("state : ");
       Serial.println(state);
        }

       lcd.home();
      
     if(avg<500){
        lcd.print("Warning");
      }else if(avg>=500 && avg <800){
        lcd.print("License Stop");
      }else{
        lcd.print("License Canceled");
      }
      lcd.setCursor(0,1);
      lcd.print(result);
  }
}

void btn1ISR(){
      if(state == 0){
        state =1;
        }
      }
