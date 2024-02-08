#include <Arduino.h>
#include <Motor.h>


Motor motorRight(6,5);
Motor motorLeft(10,11);

bool isDrivingRight = false;
int sensorLeft = 3;
int sensorRight = 4;

void setup() {
	Serial.begin(9600);
	motorLeft.driveVelocity(-1);

	pinMode(A0, INPUT);
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(sensorLeft, INPUT);
	pinMode(sensorRight, INPUT);
}

void loop() {
	if(isDrivingRight){
		motorLeft.driveVelocity(1);
		motorRight.stop();
	}
	else{
		motorRight.driveVelocity(1);
		motorLeft.stop();
	}

	if(digitalRead(sensorLeft)){
		isDrivingRight = false;
	}
	else if(digitalRead(sensorRight)){
		isDrivingRight = true;
	}
}




/*
Teorier

Kanske kan funka att köra långsamt men håller i ungefär 3-5 sekunder efter datorn har laddat upp kondensatorerna.


*/