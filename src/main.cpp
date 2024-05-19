#include <Arduino.h>
#include <Motor.h>


Motor motorRight(6,5);
Motor motorLeft(10,11);
int sensorLeft = 3;
int sensorRight = 4;

int chargeTimeSeconds = 20;

bool isDrivingRight = false;
bool driveWithMemory = false;
float speed = 1;

void setup() {
	pinMode(sensorLeft, INPUT);
	pinMode(sensorRight, INPUT);

	delay(chargeTimeSeconds * 1000);
}

void loop() {
	if(!digitalRead(sensorLeft)){ //Turn left
		isDrivingRight = false;
		driveWithMemory = false;
		motorRight.driveVelocity(speed);
		motorLeft.driveVelocity(-speed/3);
	}
	else if(!digitalRead(sensorRight)){ //Turn right
		isDrivingRight = true;
		driveWithMemory = false;
		motorLeft.driveVelocity(speed);
		motorRight.driveVelocity(-speed/3);
	}
	else{ //Continue turning based on memory
		driveWithMemory = true;
	}

	//Continue turning based on memory
	if(driveWithMemory){
		if(isDrivingRight){
			motorLeft.driveVelocity(speed);
			motorRight.stop();
		}
		else{
			motorRight.driveVelocity(speed);
			motorLeft.stop();
		}
	}
}
