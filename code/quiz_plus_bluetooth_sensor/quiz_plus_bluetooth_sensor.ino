#include <SoftwareSerial.h>
#include <dht11.h>

int DHT11PIN = A0;
dht11 DTH11;
SoftwareSerial bluetooth(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char val = bluetooth.read();
  int chk = DHT11.read(A0);
  
  if(bluetooth.available()){
    Serial.write(bluetooth.read());
      Serial.print("Temp: ");
      Serial.print((float)DHT11.temperature);
      Serial.print(" C ");
       
      Serial.print("/ RelF: ");
      Serial.print((float)DHT11.humidity);
      Serial.print(" %");
     
      Serial.println();
       
      delay(2000);

       Serial.write("Temp: ");
      Serial.write((float)DHT11.temperature);
      Serial.write(" C ");
       
      Serial.write("/ RelF: ");
      Serial.write((float)DHT11.humidity);
      Serial.write(" %");
     
      Serial.println();
       
      delay(2000);
    }
  
  

}
