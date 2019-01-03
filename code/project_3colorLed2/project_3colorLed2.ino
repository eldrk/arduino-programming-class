int red_pin1 = 9;
int green_pin1 = 10;
int blue_pin1 = 11;
int red_pin2 = 6;
int green_pin2 = 5;
int blue_pin2 = 3;
int red_pin3 = 12;
int green_pin3 = 8;
int blue_pin3 = 13;
int red_pin4 = 7;
int green_pin4 = 4;
int blue_pin4 = 2;

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
  pinMode(red_pin4,OUTPUT);
  pinMode(green_pin4,OUTPUT);
  pinMode(blue_pin4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    
  while(true){
    setColor1(0,0,0);
    setColor2(255,255,255);
    setColor3(HIGH,HIGH,HIGH);
    setColor4(HIGH,HIGH,HIGH);
    delay(500);

    setColor1(255,255,255);
    setColor2(0,0,0);
    setColor3(HIGH,HIGH,HIGH);
    setColor4(HIGH,HIGH,HIGH);
    delay(500);

    setColor1(255,255,255);
    setColor2(255,255,255);
    setColor3(LOW,LOW,LOW);
    setColor4(HIGH,HIGH,HIGH);
    delay(500);

    setColor1(255,255,255);
    setColor2(255,255,255);
    setColor3(HIGH,HIGH,HIGH);
    setColor4(LOW,LOW,LOW);
    delay(500);
    setColor4(HIGH,HIGH,HIGH);
    delay(500);
    
    setColor1(0,255,0);
    delay(500);
    setColor2(255,0,0);
    delay(500);
    setColor3(LOW,LOW,HIGH);
    delay(500);
    setColor4(LOW,HIGH,LOW);
    delay(500);
    setColor1(255,0,0);
    delay(500);
    setColor2(0,0,255);
    delay(500);
    setColor3(LOW,HIGH,LOW);
    delay(500);
    setColor4(HIGH,LOW,LOW);
    delay(500);
    setColor1(0,0,255);
    delay(500);
    setColor2(0,255,0);
    delay(500);
    setColor3(HIGH,LOW,LOW);
    delay(500);
    setColor4(LOW,LOW,HIGH);
    delay(500);
    
    }
}

void setColor1(int red, int green, int blue){
  analogWrite(red_pin1,red);
  analogWrite(green_pin1,green);
  analogWrite(blue_pin1,blue);
  }
void setColor2(int red, int green, int blue){
  analogWrite(red_pin2,red);
  analogWrite(green_pin2,green);
  analogWrite(blue_pin2,blue);
  }
void setColor3(int red, int green, int blue){
  digitalWrite(red_pin3,red);
  digitalWrite(green_pin3,green);
  digitalWrite(blue_pin3,blue);
  }
void setColor4(int red, int green, int blue){
  digitalWrite(red_pin4,red);
  digitalWrite(green_pin4,green);
  digitalWrite(blue_pin4,blue);
  }
