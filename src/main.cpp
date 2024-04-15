#include <Arduino.h>
#include <Motor.h>


Motor motorRight(6,5);
Motor motorLeft(10,11);

bool isDrivingRight = false;
bool driveWithMemory = false;
int sensorLeft = 3;
int sensorRight = 4;

float speed = 1;

int chargeTimeSeconds = 20;

void setup() {
	Serial.begin(9600);

	pinMode(sensorLeft, INPUT);
	pinMode(sensorRight, INPUT);


	delay(chargeTimeSeconds * 1000);
}

void loop() {
	if(!digitalRead(sensorLeft)){
		isDrivingRight = false;
		driveWithMemory = false;
		motorRight.driveVelocity(speed);
		motorLeft.driveVelocity(-speed/3);
	}
	else if(!digitalRead(sensorRight)){
		isDrivingRight = true;
		driveWithMemory = false;
		motorLeft.driveVelocity(speed);
		motorRight.driveVelocity(-speed/3);
	}
	else{
		driveWithMemory = true;
	}

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


	Serial.print("Sensor Left: ");
	Serial.print(digitalRead(sensorLeft));
	Serial.print("   Sensor right: ");
	Serial.print(digitalRead(sensorRight));
	Serial.print("   Driving right: ");
	Serial.println(isDrivingRight);
}




/*
Teorier

Kanske kan funka att köra långsamt men håller i ungefär 3-5 sekunder efter datorn har laddat upp kondensatorerna.


*/