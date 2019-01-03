
int red_pin1 = 13;
int green_pin1 = 12;
int blue_pin1 = 11;
int red_pin2 = 10;
int green_pin2 = 9;
int blue_pin2 = 6;
int red_pin3 = 3;
int green_pin3 = 5;
int blue_pin3 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_pin1,OUTPUT);
  pinMode(green_pin1,OUTPUT);
  pinMode(blue_pin1,OUTPUT);
  pinMode(red_pin2,OUTPUT);
  pinMode(green_pin2,OUTPUT);
  pinMode(blue_pin2,OUTPUT);
  pinMode(red_pin3,OUTPUT);
  pinMode(green_pin3,OUTPUT);
  pinMode(blue_pin3,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==HIGH){
    Serial.println(digitalRead(5));
    while(true){
        
    setColor1(LOW,HIGH,0);

    delay(1000);

    setColor2(0,0,255);

    delay(1000);

    setColor3(0,0,HIGH);

    delay(1000);
    
    setColor1(LOW,LOW,255);

    delay(1000);

    setColor2(255,0,0);

    delay(1000);

    setColor3(255,0,LOW);

    delay(1000);

    setColor1(HIGH,LOW,0);

    delay(1000);

    setColor2(0,255,0);

    delay(1000);
    
    setColor3(0,255,LOW);

    delay(1000);

    setColor1(LOW,LOW,0);

    delay(1000);

    setColor2(0,0,0);

    delay(1000);

    setColor3(0,0,LOW);
      }
       
    }
}

void setColor1(int red, int green, int blue){
    digitalWrite(red_pin1,red);
    digitalWrite(green_pin1,green);
    analogWrite(blue_pin1,blue);
  }

void setColor2(int red, int green, int blue){
    analogWrite(red_pin2,red);
    analogWrite(green_pin2,green);
    analogWrite(blue_pin2,blue);
  }

void setColor3(int red, int green, int blue){
    analogWrite(red_pin3,red);
    analogWrite(green_pin3,green);
    digitalWrite(blue_pin3,blue);
  }
