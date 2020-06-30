#include <Arduino.h>
#include "54A1S.h"


static void writechar(int segpins[8], int digit[8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segpins[i], digit[i]);
  }
}

struct d_numbers dn = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW},
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW},
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW},
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW},
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW},
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW},
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
  {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW},
};

struct d_letters dl = { 
  
};

void selectdigit(int num, int segpins[8]) {
  if (num == 0) {
    writechar(segpins, dn.d0);
  }
  else if (num == 1) {
    writechar(segpins, dn.d1);
  }
  else if (num == 2) {
    writechar(segpins, dn.d2);
  }
  else if (num == 3) {
    writechar(segpins, dn.d3);
  }
  else if (num == 4) {
    writechar(segpins, dn.d4);
  }
  else if (num == 5) {
    writechar(segpins, dn.d5);
  }
  else if (num == 6) {
    writechar(segpins, dn.d6);
  }
  else if (num == 7) {
    writechar(segpins, dn.d7);
  }
  else if (num == 8) {
    writechar(segpins, dn.d8);
  }
  else if (num == 9) {
    writechar(segpins, dn.d9);
  }
  else{
    Serial.println("ERROR");
  }
}

disp::disp(int segpins[8], int digpins[4]) {
  for (int i = 0; i < 4; i++) {
    _digpins[i] = digpins[i];
    pinMode(_digpins[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    _segpins[i] = segpins[i];
    pinMode(_segpins[i], OUTPUT);
  }
}

void disp::setdigit(int dig, int num) {
  for (int c = 0; c < 4; c++) {
    if (c == dig - 1)
    {
      digitalWrite(_digpins[c], LOW);
    }
    else
    {
      digitalWrite(_digpins[c], HIGH);
    }
  }
  selectdigit(num, _segpins);
  delay(5);
}

void disp::disp_num(long num) {
  String number = String(num);
  int L = number.length();

  if (L == 1) {
    number = String("000" + number);
  }
  else if (L == 2) {
    number = String("00" + number);
  }
  else if (L == 3) {
    number = String("0" + number);
  }
  else {}
  for(int c=0;c<20;c++){
    for (unsigned int i = 0; i < 4; i++) {
      String strindx = String(number.charAt(i));
      int strint = strindx.toInt();
      Serial.println(strint);
      digitalWrite(_digpins[i], LOW);
      selectdigit(strint, _segpins);
      delay(1);
      digitalWrite(_digpins[i], HIGH);
    }
  }
}