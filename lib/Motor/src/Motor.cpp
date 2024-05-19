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

//Drive motor with PWM. Velocity can be between -1 and 1.
void Motor::driveVelocity(float velocity){
    float clampedSpeed = min(1, abs(velocity)); //Take abolute value of velocity and clamp between 0 and 1.
    int pwmSpeed = round(clampedSpeed * 255);
    
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

//Drive motor full speed. Velocity can be either -1, 0 or 1.
void Motor::driveFullVelocity(float velocity){
    bool speed = velocity != 0; //
    
    //Turn forward
    if (velocity >= 0){
        digitalWrite(pinA, speed);
        digitalWrite(pinB, 0);
    }
    //Turn backward
    else{
        digitalWrite(pinA, 0);
        digitalWrite(pinB, speed);
    }
}

//Stop motor fully
void Motor::stop(){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
}
