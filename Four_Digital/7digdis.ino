int dig1=5;
int dig2=2;
int dig3=3;
int dig4=4;
int sA=29;
int sB=27;
int sC=23;
int sD=25;
int sE=26;
int sF=28;
int sG=22;
int sDEC=24;

void setup() {
  Serial.begin(9600);
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  pinMode(sA, OUTPUT);
  pinMode(sB, OUTPUT);
  pinMode(sC, OUTPUT);
  pinMode(sD, OUTPUT);
  pinMode(sE, OUTPUT);
  pinMode(sF, OUTPUT);
  pinMode(sG, OUTPUT);
  pinMode(sDEC, OUTPUT);
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digit(1);
  b();
  delay(5);
  digit(2);
  r();
  delay(5);
  digit(3);
  u();
  delay(5);
  digit(4);
  h();
  delay(5);
}

void digit(int x){
  if (x==1){
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig3, HIGH);
    digitalWrite(dig4, HIGH);
  }

  else if(x==2){
    digitalWrite(dig1, HIGH);
    digitalWrite(dig2, LOW);
    digitalWrite(dig3, HIGH);
    digitalWrite(dig4, HIGH);
  }
  else if(x==3){
    digitalWrite(dig1, HIGH);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig3, LOW);
    digitalWrite(dig4, HIGH);
  }

  else if(x==4){
    digitalWrite(dig1, HIGH);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig3, HIGH);
    digitalWrite(dig4, LOW);
  }
}
void b(){
  digitalWrite(sF,HIGH);
  digitalWrite(sE,HIGH);
  digitalWrite(sA,LOW);
  digitalWrite(sB,LOW);
  digitalWrite(sC,HIGH);
  digitalWrite(sG,HIGH);
  digitalWrite(sD,HIGH);
  digitalWrite(sDEC,LOW);
}

void r(){
  digitalWrite(sF,LOW);
  digitalWrite(sE,HIGH);
  digitalWrite(sA,LOW);
  digitalWrite(sB,LOW);
  digitalWrite(sC,LOW);
  digitalWrite(sG,HIGH);
  digitalWrite(sD,LOW);
  digitalWrite(sDEC,LOW);
}

void u(){
  digitalWrite(sF,LOW);
  digitalWrite(sE,HIGH);
  digitalWrite(sA,LOW);
  digitalWrite(sB,LOW);
  digitalWrite(sC,HIGH);
  digitalWrite(sG,LOW);
  digitalWrite(sD,HIGH);
  digitalWrite(sDEC,LOW);
}

void h(){
  digitalWrite(sF,HIGH);
  digitalWrite(sE,HIGH);
  digitalWrite(sA,LOW);
  digitalWrite(sB,LOW);
  digitalWrite(sC,HIGH);
  digitalWrite(sG,HIGH);
  digitalWrite(sD,LOW);
  digitalWrite(sDEC,LOW);
}
