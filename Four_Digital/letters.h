#ifndef letters_h
#define letters_h

#include <Arduino.h>

struct d_numbers{
    int d0[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW};
    int d1[8] = {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW, LOW};
    int d2[8] = {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW};
    int d3[8] = {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW};
    int d4[8] = {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW};
    int d5[8] = {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW};
    int d6[8] = {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};
    int d7[8] = {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW};
    int d8[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW};
    int d9[8] = {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW};
};

class Display{
  public:
    Display(int digpins[4], int segpins[8]);
    void digit(int dig);
    void displaynum(int seg[8]);
    d_numbers dnum;
  private:
    int _digpins[4];
    int _segpins[8];
    
};

#endif
