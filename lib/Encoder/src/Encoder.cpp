#include<Arduino.h>
#include<Encoder.h>


Encoder::Encoder(int pinA, int pinB, int countsPerRevolution){
    this->pinA = pinA;
    this->pinB = pinB;
    this->countsPerRev = countsPerRevolution;
}

void Encoder::begin(){
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);

    this->counter = 0;
    this->lastB = digitalRead(pinB);
}

float Encoder::getRevolutions(){
    return (float)counter / countsPerRev;
}

void Encoder::update(){
    int bState = digitalRead(pinB);
        if(lastB != bState){
            if (digitalRead(pinB) != digitalRead(pinA)) counter += 1;
            else counter -= 1;
            lastB = bState;
        }
}