int Do=262,Re=294,Mi=330,Fa=349,So=392,La=440,Si=494;
int Buz=12;
int C=1; int D=2; int E=3; int F=7; int G=8; int A=9; int B=10;
int dt=100;
void setup() {
  pinMode(B,INPUT);
  pinMode(A,INPUT);
  pinMode(G,INPUT);
  pinMode(F,INPUT);
  pinMode(E,INPUT);
  pinMode(D,INPUT);
  pinMode(C,INPUT);
  pinMode(Buz,OUTPUT);
}

void loop() {
  if (digitalRead(C)==HIGH){ tone(Buz,Do,dt);}
  if (digitalRead(D)==HIGH){ tone(Buz,Re,dt);}
  if (digitalRead(E)==HIGH){ tone(Buz,Mi,dt);}
  if (digitalRead(F)==HIGH){ tone(Buz,Fa,dt);}
  if (digitalRead(G)==HIGH){ tone(Buz,So,dt);}
  if (digitalRead(A)==HIGH){ tone(Buz,La,dt);}
  if (digitalRead(B)==HIGH){ tone(Buz,Si,dt);}
  delay(dt);
}
