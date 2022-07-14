#include <Zumo32U4.h>

// Reflectance Sensor Settings
#define NUM_SENSORS 5
unsigned int sensor_values[NUM_SENSORS];
// This might need to be tuned for different lighting conditions, surfaces, etc.
// Low = good
#define QTR_THRESHOLD  300 // microseconds
const int SENSOR_LEFT_OUTER = 0;
const int SENSOR_RIGHT_OUTER = 4;
Zumo32U4LineSensors sensors;

// Motor Settings
Zumo32U4Motors motors;

const int FULL_SPEED = 200;

unsigned int sensorValues[NUM_SENSORS];
void setup() {
 Serial.begin(115200);
 Serial.print("Motors on \n");
 sensors.initFiveSensors();
 motors.setSpeeds(FULL_SPEED, FULL_SPEED);
}
void spinRight(int randNumber)
{
  motors.setSpeeds(FULL_SPEED, -FULL_SPEED);
  delay(randNumber);
}
void spinLeft(int randNumber)
{
  motors.setSpeeds(-FULL_SPEED, FULL_SPEED);
  delay(randNumber);
}
void goForward()
{
   motors.setSpeeds(FULL_SPEED, FULL_SPEED);
   delay(0.01);
}
int getSensorReading(int sensor) {
 updateSensorValues();
 return sensorValues[sensor];
}
void updateSensorValues() {
 sensors.read(sensorValues);
}
void loop() {
 
 int randNumber = random(500, 1000);
 updateSensorValues();
 int leftSensor = sensorValues[SENSOR_LEFT_OUTER];
 int rightSensor = sensorValues[SENSOR_RIGHT_OUTER];

 int leftSensorValue = getSensorReading(SENSOR_LEFT_OUTER);
 int rightSensorValue = getSensorReading(SENSOR_RIGHT_OUTER);


 // Add moving logic with light sensor values
 Serial.println(leftSensorValue);
 Serial.println(rightSensorValue);
 if (leftSensorValue <= QTR_THRESHOLD) {
    spinRight(randNumber);
 } else if (rightSensorValue <= QTR_THRESHOLD) {
    spinLeft(randNumber);
 } else {
  goForward();
 }
}
