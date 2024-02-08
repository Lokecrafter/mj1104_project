#include <Arduino.h>
#include <Motor.h>


Motor motorRight(6,5);
Motor motorLeft(10,11);

void setup() {
	Serial.begin(9600);
	motorLeft.driveVelocity(-1);

	pinMode(A0, INPUT);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	motorLeft.driveVelocity(1);
	//motorRight.driveVelocity(1);
	Serial.println("Full speed");

	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
	motorLeft.stop();
	motorRight.stop();

	digitalWrite(LED_BUILTIN, LOW);
	delay(1000);
	//motorLeft.driveVelocity(-0.75);
	motorRight.driveVelocity(1);
	
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
	motorLeft.stop();
	motorRight.stop();
	
	digitalWrite(LED_BUILTIN, LOW);
	delay(1000);
}




/*
Teorier

Kanske kan funka att köra långsamt men håller i ungefär 3-5 sekunder efter datorn har laddat upp kondensatorerna.


*/