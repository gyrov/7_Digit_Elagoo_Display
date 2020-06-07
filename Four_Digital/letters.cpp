#include <Arduino.h>
#include "letters.h"

Display::Display(int digpins[4], int segpins[8]){
    _digpins = digpins;
    _segpins = segpins;

    for(int i=0; i<4,i++){
        pinMode(digpins[i], OUTPUT)
    }
    
    for(int i=0; i<8,i++){
        pinMode(segpins[i], OUTPUT)
    }
}

Display::digit(int dig){
    for(int c=0; c<4; c++){
        if(_digpins[c] == dig)
        {
            digitalWrite(dig, LOW);
        }
        else
        {
            digitalWrite(dig, HIGH);
        }
    }    
}

Display::displaynum(int seg[8]){
    for(int i=0, i<8, i++){
        digitalWrite(_segpins[i],seg[i])
    }
}