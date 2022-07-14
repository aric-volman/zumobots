#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4LCD lcd;

unsigned long startTime;
void setup() {
  // put your setup code here, to run once:
  motors.setSpeeds(0, 0);
  lcd.clear();
  startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:

  //Activity 1: Change the speeds to make the robot drive straight for 2 seconds
  //Measure the distance travelled to determine a speed, so that distances can be converted into time
  goForward(2, 200, 200);
 
  //Activity 2: Uncomment the turnRobotRight(0.5) command and adjust the time value to make the zumobot turn right for 90 degrees
  turnRobotRight(0.5, 200, -200);

  goForward(2, 200, 200);

  //Add on goForward(), turnLeft(), and turnRight() commands here to get the zumobot to navigate the maze

  //print out final time and wait for 5 seconds before looping again
  motors.setSpeeds(0, 0);
  lcd.gotoXY(0, 0);
  lcd.print((millis() - startTime)/1000.0);
  lcd.print(" ");
  delay(5000);
}

//method to make the robot drive forward (delayTime is in seconds)
void goForward(double delayTime, double leftPower, double rightPower) {
  motors.setSpeeds(leftPower, rightPower);
  delay(delayTime*1000.0);
}

//method to make the robot turn left/counterclockwise (delayTime is in seconds)
void turnRobotLeft(double delayTime, double leftPower, double rightPower) {
  motors.setSpeeds(leftPower, rightPower);
  delay(delayTime*1000.0);
}

//method to make the robot turn right/clockwise (delayTime is in seconds)
void turnRobotRight(double delayTime, double leftPower, double rightPower) {
  motors.setSpeeds(leftPower, rightPower);
  delay(delayTime*1000.0);
}

//method to make the robot stop (delayTime is in seconds)
void stopRobot(double delayTime) {
  motors.setSpeeds(0, 0);
  delay(delayTime*1000.0);
}
