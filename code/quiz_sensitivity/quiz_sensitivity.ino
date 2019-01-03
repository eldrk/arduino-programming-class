int red = 4;
int green = 8;
int blue = 9;
int detectPin = 7;
int sensor_state = LOW;
int input = LOW;
int motion;

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(detectPin,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  input=digitalRead(detectPin);
  if(input == HIGH){
    Serial.println("Motion detected!");
    motion++;
    if(motion%3==0){
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      analogWrite(blue,255);
      }else if(motion%3==1){
       digitalWrite(red,HIGH);
       digitalWrite(green,LOW);
       analogWrite(blue,255);
      }else if(motion%3==2){
       digitalWrite(red,HIGH);
      digitalWrite(green,HIGH);
      analogWrite(blue,0); 
      }
  }else{
      digitalWrite(red,HIGH);
      digitalWrite(green,HIGH);
      analogWrite(blue,255);
     Serial.println("Motion end!");
    }
    delay(500);
}
