int pin1 = 5;
int pin2 = 6;
int pin_speed = 3;


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
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);

  analogWrite(pin_speed,50);
  delay(3000);

  analogWrite(pin_speed,100);
  delay(3000);

  analogWrite(pin_speed,150);
  delay(3000);

  analogWrite(pin_speed,200);
  delay(3000);

  analogWrite(pin_speed,255);
  delay(3000);
}
