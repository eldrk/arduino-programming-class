int ledPin = 13;
int detectPin = 7;
int sensor_state = LOW;
int input = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(detectPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  input = digitalRead(detectPin);
  if(input == HIGH){
    digitalWrite(ledPin,HIGH);
    Serial.println("Motion detected!");
    }else{
      digitalWrite(ledPin,LOW);
      Serial.println("Motion end!");
    }
    delay(500);
}
