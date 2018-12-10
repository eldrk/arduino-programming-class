#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 char val = bluetooth.read();
 if(bluetooth.available()){
  Serial.write(bluetooth.read());
  }
  if(val == 'a'){
    digitalWrite(7,HIGH);
    }

  if(val == 'b'){
    digitalWrite(8,HIGH);
    }
   else if(val == 'c'){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    }
}
