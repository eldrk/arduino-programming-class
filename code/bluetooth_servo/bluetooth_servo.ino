#include<SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial bluetooth(2,3);
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  char val = bluetooth.read();
  if(bluetooth.available()){
    Serial.write(bluetooth.read());
    }

   if(val == 'L'){
    Serial.println('L');
    for(int i=0;i<100;i++){
      myservo.write(i);
      delay(15);
      }
    }else if(val == 'R'){
      Serial.println('R');
      for(int i=100;i>0; i--){
        myservo.write(i);
        delay(15);
        }
      }
}
