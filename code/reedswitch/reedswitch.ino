
int sensor = 3;
int led = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reedSW = digitalRead(sensor);

  if(reedSW == LOW){
    digitalWrite(led,HIGH);
    }else{
    digitalWrite(led,LOW);
    }

    Serial.print("reed : ");
    Serial.println(reedSW);
    delay(1000);
}
