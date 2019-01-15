#include "pitches.h"
#include <Servo.h>
#define MELODY_PIN 4
Servo servo;
int melody[] = {
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_C5,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  0,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_AS4,
  NOTE_A4,
  NOTE_A4,
  NOTE_A4,
  NOTE_C5,
  NOTE_C5,
  NOTE_AS4,
  NOTE_G4,
  NOTE_F4,
  0, 
};
int noteDurations[] = {
  2,2,4,2,2,4,2,2,3,1,6,2,
  2,2,3,1,2,2,2,2,2,2,2,2,6,2,
};

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
digitalWrite(8,LOW);
}

void loop() {
// put your main code here, to run repeatedly:

digitalWrite(9,HIGH);
analogWrite(10,200);
Serial.println("HIGH");
delay(3000);

 for(int thisNote = 0; thisNote < (sizeof(melody) / sizeof(int)); thisNote++)
      {
        int noteDuration = 125 * noteDurations[thisNote];
        tone(MELODY_PIN, melody[thisNote], noteDuration);
    
        int pauseBetweenNotes = noteDuration * 1.20;
        delay(pauseBetweenNotes);
        noTone(MELODY_PIN);
      }
        digitalWrite(9,LOW);
        Serial.println("LOW");
        delay(3000);

}
