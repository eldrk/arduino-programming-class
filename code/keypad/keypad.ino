#include<Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
  };

  byte rowPins[ROWS] = {9,8,7,6};
  byte colPins[COLS] = {5,4,3,2};

  Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
  int led_pin = 13;
  boolean blink = false;
  String myPass="1234";
  String buffer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  keypad.addEventListener(MyListener);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if(key != NO_KEY){
    Serial.println(key);
    
    }
}

void MyListener(KeypadEvent key){
    switch(keypad.getState()){
      case PRESSED:
      if(key =='#'){
        if(buffer.compareTo(key) == myPass){
          if(key == 'A'){
            digitalWrite(led_pin,true);
            Serial.println("OPEN");
            }
          }
        }else{
          buffer += key; 
          }
          Serial.print("INPUT : ");
          Serial.println(buffer);
        break;
        
      case RELEASED:
      if(key =='*'){
        Serial.println("RELEASED");
        buffer = "";
        }
        break;
      case HOLD:
      if(key =='*'){
        Serial.println("HOLDING");
        }
        break;
        
      }
  }
