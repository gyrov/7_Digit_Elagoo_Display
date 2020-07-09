#include <Arduino.h>
#include "54A1S.h"

struct d_chars dc = {
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

static void writechar(int segpins[8], int digit[8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segpins[i], digit[i]);
  }
}

static void selectchar(char ichar, int segpins[8]) {
  if (ichar == 48) {
    writechar(segpins, dc.d_0);
  }
  else if (ichar == 49) {
    writechar(segpins, dc.d_1);
  }
  else if (ichar == 50) {
    writechar(segpins, dc.d_2);
  }
  else if (ichar == 51) {
    writechar(segpins, dc.d_3);
  }
  else if (ichar == 52) {
    writechar(segpins, dc.d_4);
  }
  else if (ichar == 53) {
    writechar(segpins, dc.d_5);
  }
  else if (ichar == 54) {
    writechar(segpins, dc.d_6);
  }
  else if (ichar == 55) {
    writechar(segpins, dc.d_7);
  }
  else if (ichar == 56) {
    writechar(segpins, dc.d_8);
  }
  else if (ichar == 57) {
    writechar(segpins, dc.d_9);
  }
  else{
    Serial.println("Invalid Character");
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

void disp::setdigit(int dig, char num) {
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
  selectchar(num, _segpins);
  delay(5);
}

void disp::disp_num(char[] input) {
  int L = sizeof(input)/sizeof(input[0]);
  char number[4] = "0000";
  for(int j=4-L; j<4; j++){
    number[j] = input[j];
  }
  for(int c=0;c<20;c++){
    for (unsigned int i = 0; i < 4; i++) {
      digitalWrite(_digpins[i], LOW);
      selectchar(number, _segpins);
      digitalWrite(_digpins[i], HIGH);
    }
  }
}
