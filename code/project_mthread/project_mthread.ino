#include "mthread.h"
int piezo = 3;
int del = 1;
const int ENA = 10;
const int IN1 = 9;
const int IN2 = 8;
const int ENB = 5;
const int IN4 = 6;
const int IN3 = 7;
int brightness = 0;
int fadeAmount = 5;

void forward(int i, int j) {
  // Set both motors ON
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  while (1)   {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);  
    i--;
    if (i < 1) break;
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break;
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);  
    i--;
    if (i < 1) break;
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;
  }
  // set both motors OFF
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}  // end forward()

class BlessingThread : public Thread
{
  public:
      BlessingThread(int id);
  protected:
      bool loop();
  private:
      int id;
};

BlessingThread::BlessingThread(int id)
{
    this->id = id;
}

bool BlessingThread::loop()
{
  if(kill_flag) return false;

  if(id == 1)
  {
    forward(2048,2);
    delay(del * 3);
  }
  else if(id == 2)
  {
    analogWrite(piezo, 64);
    delay(del);
    analogWrite(piezo, 128);
    delay(del);
    analogWrite(piezo, 256);
    delay(del);
  }
  
  return true;
}

void setup()
{
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
  
  main_thread_list->add_thread(new BlessingThread(1));
  main_thread_list->add_thread(new BlessingThread(2));
}

void loop(){
  
}

void reverse(int i, int j) {
  // set both motors ON
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  while (1)   {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break; 
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);  
    i--;
    if (i < 1) break;
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);  
    i--;
    if (i < 1) break;
  }
  // set both motors OFF
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}  // end reverse()
