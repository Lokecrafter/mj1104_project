#include <Arduino.h>
#include <Motor.h>


Motor motorA(5,6);
Motor motorB(10,11);

void setup() {
	Serial.begin(9600);
	motorA.driveVelocity(-1);

	pinMode(A0, INPUT);
}

void loop() {
	Serial.println(digitalRead(A0));
	/*
	motorA.driveVelocity(1);
	//motorB.driveVelocity(-0.75);
	Serial.println("Full speed");
	delay(1000);
	motorA.stop();
	motorB.stop();
	delay(1000);
	motorA.driveVelocity(-0.75);
	//motorB.driveVelocity(0.75);
	delay(1000);
	motorA.stop();
	motorB.stop();
	delay(1000);
	*/
}
