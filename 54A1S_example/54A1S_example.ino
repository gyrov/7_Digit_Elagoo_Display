#include <SR04.h>
#include "letters.h"

#define TRIG_PIN 35
#define ECHO_PIN 33
int segpins[8] = {29,27,23,25,26,28,22,24};
int digpins[4] = {5,2,3,4};
disp dsp(segpins,digpins);
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;


void setup() {
  Serial.begin(9600);
  for(int g;g<4;g++){
    digitalWrite(dsp._digpins[g], HIGH);
  }
}

void loop() {
  a=sr04.Distance();
  dsp.disp_num(a);
}
