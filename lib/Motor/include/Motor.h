#ifndef MOTOR_H
#define MOTOR_H

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
