#define C 262
#define D 294
#define E 330
#define F 349
#define G 394
#define A 440
#define B 494
#define H 523

int piezo_Pin = 8;
int tempo = 200;
int notes[25] = {G,G,A,A,G,G,E,G,G,E,E,D,G,G,A,A,G,G,E,G,E,D,E,C};

void setup() {
  // put your setup code here, to run once:
  pinMode(piezo_Pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<12; i++){
    Serial.println(analogRead(A0));
    tone(piezo_Pin, notes[i],analogRead(A0));
    delay(analogRead(A0));
    }
    delay(100);

    for(int i=12; i<25; i++){
      Serial.println(analogRead(A0));
      tone(piezo_Pin,notes[i],analogRead(A0));
      delay(analogRead(A0));
      }
}
