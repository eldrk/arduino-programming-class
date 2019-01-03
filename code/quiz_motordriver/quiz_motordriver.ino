int pin1 = 5;
int pin2 = 6;
int pin_speed = 3;
int btn1 = 7;
int btn2 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin_speed,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(btn1)==HIGH){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    Serial.print("btn1 : ");
    Serial.println(digitalRead(btn1));
    analogWrite(pin_speed,50);
  
    }else if(digitalRead(btn2)==HIGH){
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      analogWrite(pin_speed,255);
      Serial.print("btn2 : ");
      Serial.println(digitalRead(btn1));
      
   }else{
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    
    }
}
