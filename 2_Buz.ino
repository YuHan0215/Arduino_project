//int Do=262,Re=294,Mi=330,Fa=349,So=392,La=440,Si=494;
int Do=523,Mi=659,So=784;
int Buz=5,Rled=12,Bled=9,Gled=8;
int dt=150;
void setup() {
  pinMode(Buz,OUTPUT);
  pinMode(Rled,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(Bled,OUTPUT);
  pinMode(Gled,OUTPUT);
}

void loop() {
  //tone(pin,frequency,duration);
  //noTone(pin); 關閉聲音
  digitalWrite(Rled,HIGH); tone(Buz,Mi,dt-20); digitalWrite(Rled,LOW); delay(dt);
  digitalWrite(Rled,HIGH); tone(Buz,Mi,dt-20); digitalWrite(Rled,LOW); delay(dt);
  digitalWrite(Rled,HIGH); tone(Buz,Mi,dt-20); digitalWrite(Rled,LOW); delay(dt);
  delay(dt);
  digitalWrite(Bled,HIGH); tone(Buz,Do,dt); digitalWrite(Bled,LOW); delay(dt);
  digitalWrite(Rled,HIGH); tone(Buz,Mi,dt); digitalWrite(Rled,LOW); delay(dt);
  delay(dt);
  digitalWrite(Gled,HIGH); tone(Buz,So,dt); digitalWrite(Gled,LOW); delay(dt*20);

  
}
