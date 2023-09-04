int Rled=13;int Yled=11;int Gled=9;
void setup() {
  pinMode(Rled,OUTPUT);
  //pinMode(12,OUTPUT);
  pinMode(Yled,OUTPUT);
  //pinMode(10,OUTPUT);
  pinMode(Gled,OUTPUT);
}

void loop() {
  digitalWrite(Rled,HIGH);digitalWrite(Yled,LOW);digitalWrite(Gled,LOW);delay(1000);
  digitalWrite(Rled,LOW);digitalWrite(Yled,HIGH);digitalWrite(Gled,LOW);delay(1000);
  digitalWrite(Rled,LOW);digitalWrite(Yled,LOW);digitalWrite(Gled,HIGH);delay(1000);
  //digitalWrite(Rled,LOW);digitalWrite(Yled,LOW);digitalWrite(Gled,LOW);delay(2000);
  digitalWrite(Rled,HIGH);digitalWrite(Yled,HIGH);digitalWrite(Gled,LOW);delay(2000);
  digitalWrite(Rled,LOW);digitalWrite(Yled,HIGH);digitalWrite(Gled,HIGH);delay(2000);
  digitalWrite(Rled,HIGH);digitalWrite(Yled,LOW);digitalWrite(Gled,HIGH);delay(2000);
  //digitalWrite(Rled,LOW);digitalWrite(Yled,LOW);digitalWrite(Gled,LOW);delay(3000);
  digitalWrite(Rled,HIGH);digitalWrite(Yled,HIGH);digitalWrite(Gled,HIGH);delay(3000);
  digitalWrite(Rled,LOW);digitalWrite(Yled,LOW);digitalWrite(Gled,LOW);delay(4000);
}
