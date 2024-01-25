#ifndef MOTOR_H
#define MOTOR_H

#include<Encoder.h>

class Motor{
    private:
        int pinA;
        int pinB;
    public:
        Motor(int pinA, int pinB);
        void begin();
        void driveVelocity(float velocity);
        void stop();
};
#endif
