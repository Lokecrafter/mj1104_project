#include <Arduino.h>
#include <Motor.h>

//Motors
Motor motorRight(6,5);
Motor motorLeft(10,11);

//Sensor pins
int sensorLeft = 3;
int sensorRight = 4;

//Robot variables
const float velocityForward = 0.7;
const float maxXDrive = 0.7;

//PID constants
const float kp = 1;
const float ki = 0.5;
const float kd = 0;

//Integration constants
const float errorSumMultiplier = 100;
const float errorDecayConstant = 5;
const float maxErrorSum = 1;

//Global variables for time, integral and derivative
float sumError = 0;
unsigned long lastMicros = 0;
float lastError = 0;


void setup() {
	Serial.begin(9600);

	pinMode(sensorLeft, INPUT);
	pinMode(sensorRight, INPUT);

	lastMicros = micros();
}

void driveRobot(float x, float y){
	x = min(max(x, -maxXDrive), maxXDrive); //Clamp x-value

	float leftDrive = y + x;
	float rightDrive = y - x;

	Serial.print("   left: ");
	Serial.print(leftDrive);
	Serial.print("   right: ");
	Serial.println(rightDrive);

	motorLeft.driveVelocity(leftDrive);
	motorRight.driveVelocity(rightDrive);
}

void loop() {

	float deltaTime = (micros() - lastMicros) / (float)1000000;
	lastMicros = micros();

	//Calculate error. Error is 0 if no sensor is seeing the line
	float error = (!digitalRead(sensorRight)) - (!digitalRead(sensorLeft));

	//Calculate "Turn factor" with PID controller
	float deltaError = (error - lastError) / deltaTime;
	float xDrive = kp * error + ki * sumError + kd * deltaError;	//PID controller
	Serial.print("sumError: ");
	Serial.print(sumError);
	Serial.print("   xDrive: ");
	Serial.print(xDrive);

	driveRobot(xDrive, velocityForward);

	//Integrate error and add an errordecay by numeric differential equation
	float firstSumErrorDerivative = sumError * errorDecayConstant; 
	sumError -= firstSumErrorDerivative * deltaTime;


	sumError += error * errorSumMultiplier * deltaTime;
	sumError = min(max(sumError, -maxErrorSum), maxErrorSum); //Clamp error sum

	

	lastError = error;
}