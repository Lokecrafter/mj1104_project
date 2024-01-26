#include<Arduino.h>
#include<Motor.h>


Motor::Motor(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;
}

void Motor::begin(){
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}

void Motor::driveVelocity(float velocity){
    float clampedVelocity = abs(max(-1.0, min(velocity, 1.0))); //Clamp velocity to between -1 and 1 and take absolute value
    //bool pwmSpeed = clampedVelocity != 0;
    int pwmSpeed = round(clampedVelocity * 255);
    
    //Turn forward
    if (velocity >= 0){
        analogWrite(pinA, pwmSpeed);
        analogWrite(pinB, 0);
    }
    //Turn backward
    else{
        analogWrite(pinA, 0);
        analogWrite(pinB, pwmSpeed);
    }
}

void Motor::stop(){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
}
