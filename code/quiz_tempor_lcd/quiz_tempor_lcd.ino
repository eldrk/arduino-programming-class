#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>

int DHT11PIN = A0;            
dht11 DHT11;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  float T = DHT11.temperature;
  float RH = DHT11.humidity;
  float dcf = 9/5*T-0.55*(1-RH/100)*(9/5*T-26)+32;
  
  Serial.print("Temp: ");
  Serial.print((float)DHT11.temperature);
  Serial.print(" C ");
   
  Serial.print("/ RelF: ");
  Serial.print((float)DHT11.humidity);
  Serial.print(" %");

  Serial.print(" / Discomfort: ");
  Serial.print(dcf);
  Serial.println(" C ");

  lcd.clear();
  lcd.home();
  lcd.print(T);
  lcd.print(" C ");

  lcd.setCursor(0,1);
  lcd.print(RH);
  lcd.print(" %   ");
  lcd.print(dcf);
  lcd.print(" C ");
   
  delay(2000);
}
