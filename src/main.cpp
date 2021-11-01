/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\brad                                             */
/*    Created:      Thu Oct 28 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftMotor            motor         1               
// rightMotor           motor         2               
// armMotor             motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

const float wheelDiameter = 4.25;
const float wheelCircumference = (float)3.14 * wheelDiameter;
const float gearRatio = 5.0;
const float wheelTrack = 11; //13.5;
const float degreesPerInch = (float)360.0 / wheelCircumference;

void driveStraight(float inches) {
  leftMotor.spinFor(forward, gearRatio * inches * degreesPerInch,degrees, false);
  rightMotor.spinFor(forward, gearRatio * inches * degreesPerInch,degrees, true);
}

void turnRight(float targetDegrees) {
  float rotationDegrees = targetDegrees * gearRatio * wheelTrack / wheelDiameter;
  leftMotor.spinFor(forward, rotationDegrees, degrees, false);
  rightMotor.spinFor(reverse, rotationDegrees, degrees, true);
}

void turnLeft(float targetDegrees) {
  float rotationDegrees = targetDegrees * gearRatio * wheelTrack / wheelDiameter;
  leftMotor.spinFor(reverse, rotationDegrees, degrees, false);
  rightMotor.spinFor(forward, rotationDegrees, degrees, true);
}

void makePolygon(float nSides, float sLength) {
  float polygonDegrees = ((180 * (nSides - 2)) / nSides); 
  for(int i = 0; i <= (int)nSides; i++){
    driveStraight(sLength);
    turnRight(polygonDegrees);
  }
}

void solveMaze() {
  driveStraight(20);
  turnRight(270);
  driveStraight(30);
  turnRight(90);
  driveStraight(18);
  turnRight(90);
  driveStraight(14);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  driveStraight(10);
  turnRight(90);
}

