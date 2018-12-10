int sound_pin = A0;
int led1 = 12;
int led2 = 8;
int led3 = 7;


int count = 0;
int led_pin = led3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);


  if(sound_value >= 800){
    count++;
    }

  if(count>=0 && count<10){       
    led_pin = led3;
    }else if(count >= 10 && count <20){
      led_pin = led2;
    }else if(count >=20 && count <30){
      led_pin = led1;
    }else{
      
      }
  int light_value = map(sound_value,0,1023,0,255);
  digitalWrite(led_pin,light_value);
  Serial.println("sound Value: ");
  Serial.println(sound_value);

  Serial.println("light Value: ");
  Serial.println(light_value);
  Serial.println("count : ");
  Serial.println(count);

  delay(100);
  
}
