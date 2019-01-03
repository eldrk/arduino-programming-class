int red = 10;
int green = 9;
int pin_alcohol = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int alcohol = analogRead(pin_alcohol);
  int result = map(alcohol,0,1023,0,255);

  if(alcohol <=500){
    analogWrite(green,255);
    analogWrite(red,0);
    }else{
      analogWrite(green,(255-result)/20);
      analogWrite(red,result);
    }

    Serial.println("~~~~~~~~~~~~~~");
    Serial.print("alcohol : ");
  Serial.println(result);
  Serial.print("raw data : ");
  Serial.println(alcohol);
  delay(500);
}
