#include <Arduino.h>
#include <Motor.h>


Motor motorRight(6,5);
Motor motorLeft(10,11);

int sensorLeft = 3;
int sensorRight = 4;

float speed = 1;
float forwardSpeed = 0.9;
int chargeTimeSeconds = 20;

void setup() {
	pinMode(sensorLeft, INPUT);
	pinMode(sensorRight, INPUT);

	delay(chargeTimeSeconds * 1000);
}

void loop() {
	if (!digitalRead(sensorLeft) && !digitalRead(sensorRight)){ //Drive forward
		motorLeft.driveVelocity(forwardSpeed);
		motorRight.driveVelocity(forwardSpeed);
	}
	else if(!digitalRead(sensorRight)){ //Turn right
		motorLeft.driveVelocity(speed);
		motorRight.driveVelocity(0);
	}
	else if(!digitalRead(sensorLeft)){ //Turn left
		motorRight.driveVelocity(speed);
		motorLeft.driveVelocity(0);
	}
	else{ //Drive forward
		motorLeft.driveVelocity(forwardSpeed);
		motorRight.driveVelocity(forwardSpeed);
	}
}