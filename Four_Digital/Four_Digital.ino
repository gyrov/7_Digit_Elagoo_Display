int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
// EACH DIGIT
int dig1=1;  
int dig2=2;
int dig3=3;
int dig4=4;

String letters[] = {"A","D","E","I"};
int pin[] = {4,1,2,3};
unsigned char codes[] = {0x77, 0x5E, 0x30, 0x79};

unsigned char A = 0x77;
unsigned char D = 0x5E;
unsigned char I = 0x30;
unsigned char E = 0x79;


void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(dig1,OUTPUT);
  pinMode(dig2,OUTPUT);
  pinMode(dig3,OUTPUT);
  pinMode(dig4,OUTPUT);
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  
}
void Display(unsigned char num, int pin)
{
  // dec,g,f,e,d,c,b,a
  digitalWrite(pin, LOW);
  digitalWrite(latch,HIGH);
  //shiftOut(data,clock,MSBFIRST,table[num]);
  shiftOut(data,clock,MSBFIRST,num);
  digitalWrite(latch,LOW);
  digitalWrite(pin, HIGH);

}

unsigned char find_code(String letter_in){
  for (int i = 0; i < sizeof(letters)/sizeof(letters[0]); i++){
    if (letter_in == letters[i]){
      return codes[i]; 
    }  
  }
}

void static_word(String word_in){
  for (int i=0; i<4; i++){
      Display(find_code(word_in[i]), pin[i]);
    }
}


void loop() {
  // 1-4 2-1 3-2 4-3
  // SHIFTS EVERYTHING BY 1 PIN CYCLICALLY WHEN MORE THAN ONE ACTIVE DISPLAY ???????????
  //Display(D,4);
  //Display(A,1);
  //Display(E,2);
  //Display(E,3);
  static_word("ADIE");
}
