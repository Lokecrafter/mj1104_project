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
	Serial.begin(9600);

	pinMode(sensorLeft, INPUT);
	pinMode(sensorRight, INPUT);

	delay(chargeTimeSeconds * 1000);
}

void loop() {
	if (!digitalRead(sensorLeft) && !digitalRead(sensorRight)){
		motorLeft.driveVelocity(forwardSpeed);
		motorRight.driveVelocity(forwardSpeed);
	}
	else if(!digitalRead(sensorRight)){
		motorLeft.driveVelocity(speed);
		motorRight.driveVelocity(0);
	}
	else if(!digitalRead(sensorLeft)){
		motorRight.driveVelocity(speed);
		motorLeft.driveVelocity(0);
	}
	else{
		motorLeft.driveVelocity(forwardSpeed);
		motorRight.driveVelocity(forwardSpeed);
	}
	



	Serial.print("Sensor Left: ");
	Serial.print(digitalRead(sensorLeft));
	Serial.print("   Sensor right: ");
	Serial.print(digitalRead(sensorRight));
}




/*
Teorier

Kanske kan funka att köra långsamt men håller i ungefär 3-5 sekunder efter datorn har laddat upp kondensatorerna.


*/