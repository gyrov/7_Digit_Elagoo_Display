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
  {}

};

static void writechar(int segpins[8], int digit[8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segpins[i], digit[i]);
  }
}

static void selectchar(String num, int segpins[8]) {
  if (num == 0) {
    writechar(segpins, dc.d_0);
  }
  else if (num == 1) {
    writechar(segpins, dc.d_1);
  }
  else if (num == 2) {
    writechar(segpins, dc.d_2);
  }
  else if (num == 3) {
    writechar(segpins, dc.d_3);
  }
  else if (num == 4) {
    writechar(segpins, dc.d_4);
  }
  else if (num == 5) {
    writechar(segpins, dc.d_5);
  }
  else if (num == 6) {
    writechar(segpins, dc.d_6);
  }
  else if (num == 7) {
    writechar(segpins, dc.d_7);
  }
  else if (num == 8) {
    writechar(segpins, dc.d_8);
  }
  else if (num == 9) {
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

void disp::disp_num(char input) {
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