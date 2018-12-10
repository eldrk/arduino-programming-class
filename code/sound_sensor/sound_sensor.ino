int sound_pin = A0;
int led_pin = 11;
int btn_pin = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  pinMode(btn_pin,INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value,0,1023,0,255);

  Serial.println("sound Value: ");
  Serial.println(sound_value);

  Serial.println("light Value: ");
  Serial.println(light_value);

  analogWrite(led_pin,light_value);
  delay(1000);
}
