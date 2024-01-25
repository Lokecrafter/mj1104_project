#include <Arduino.h>
#include <Motor.h>


Motor motor(5,6);

void setup() {
	Serial.begin(9600);
}

void loop() {
	motor.driveVelocity(0.75);
	delay(1000);
	motor.stop();
	delay(1000);
}
