int ledred=13;
int ledyel=12;
int ledgre=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred,OUTPUT);
  pinMode(ledyel,OUTPUT);
  pinMode(ledgre,OUTPUT);
  pinMode(7,INPUT);
  pinMode(4,INPUT);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=digitalRead(7);
  if(a==1){
    digitalWrite(ledred,HIGH);
    digitalWrite(ledred,LOW);
    digitalWrite(ledgre,LOW);
    }


  int b=digitalRead(4);
  if(b==1){
    digitalWrite(ledred,LOW);
    digitalWrite(ledyel,HIGH);
    digitalWrite(ledgre,LOW);
    }


  int c=digitalRead(2);
  if(c==1){
    digitalWrite(ledred,LOW);
    digitalWrite(ledyel,LOW);
    digitalWrite(ledgre,HIGH);
    }

  

  
}
