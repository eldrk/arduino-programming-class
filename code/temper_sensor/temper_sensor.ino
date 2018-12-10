#include <dht11.h>
 
int DHT11PIN = A0;            
 
dht11 DHT11;
  
void setup()
{
  Serial.begin(9600);  //시리얼 통신속도 설정
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
   
  delay(2000);
}
