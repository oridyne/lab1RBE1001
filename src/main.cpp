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
// rangeFinder          sonar         EF
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "vex_global.h"

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

void turnLeft(float targetDegrees) {
  float rotationDegrees = targetDegrees * gearRatio * wheelTrack / wheelDiameter;
  leftMotor.spinFor(forward, rotationDegrees, degrees, false);
  rightMotor.spinFor(reverse, rotationDegrees, degrees, true);
}

void turnRight(float targetDegrees) {
  float rotationDegrees = targetDegrees * gearRatio * wheelTrack / wheelDiameter;
  leftMotor.spinFor(reverse, rotationDegrees, degrees, false);
  rightMotor.spinFor(forward, rotationDegrees, degrees, true);
}

void makePolygon(float nSides, float sLength) {
  float polygonDegrees = (90 - ( 180 * (nSides - 2)) / nSides)+3; 
  turnRight(polygonDegrees);
  driveStraight(sLength);
  polygonDegrees = 183 - ((180 * (nSides - 2)) / nSides); 
  for(int i = 1; i < (int)nSides; i++){
    turnRight(polygonDegrees);
    driveStraight(sLength);
  }
}

void solveMaze() {
  driveStraight(20);
  turnLeft(90);
  driveStraight(30);
  turnRight(90);
  driveStraight(18);
  turnRight(95);
  driveStraight(17);
}

void driveField() {
  float angle = 97;
  driveStraight(13);
  turnLeft(angle); 
  driveStraight(59);
  turnLeft(angle);
  driveStraight(105);
  turnLeft(angle);
  driveStraight(62);
  turnLeft(angle);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.clearScreen();
  float kP = 0.2f;
  double setDistance = 15;
  leftMotor.setVelocity(70,percent);
  rightMotor.setVelocity(70,percent);
  /* int buttonW = 40; */
  /* int buttonH = 40; */
  /* while(true) { */
  /*   Brain.Screen.drawRectangle(0,0,buttonW,buttonH); */
  /*   if(Brain.Screen.pressing()) { */
  /*     int X = Brain.Screen.xPosition(); */
  /*     int Y = Brain.Screen.yPosition(); */
  /*     if ((X >= 0 && X <= buttonW) && (Y >= 0 && Y <= buttonH)){ */
  /*       Brain.Screen.printAt(50,50,"Pressed!"); */
  /*     } */
  /*   } else { */
  /*     Brain.Screen.clearScreen(); */
  /*   } */
  /*   task::sleep(500); */
  /* } */
  while(true) {
    double rfDistance = rangeFinder.distance(inches);
    double rfError = rfDistance - setDistance;
    int left = leftLine.reflectivity();
    int right = rightLine.reflectivity();
    int error = left - right;
    /* leftMotor.setVelocity(30 + (float)error * kP, percent); */
    /* rightMotor.setVelocity(30 + (float)error * kP, percent); */
    /* leftMotor.spin(forward); */
    /* rightMotor.spin(forward); */
    Brain.Screen.printAt(30,30,"left: %d",left);
    Brain.Screen.printAt(30,60,"right: %d",right);
    Brain.Screen.printAt(30,90,"error: %d",error);
    /* Brain.Screen.printAt(30,60,"sonar distance: %d error: %d", rfDistance,rfError); */
    task::sleep(500); 
  }
  /* while(true) { */
  /*       leftMotor.setVelocity(30 + float(rfError) * kP, percent); */
  /*   rightMotor.setVelocity(30 + float(rfError) * kP, percent); */
  /*   rightMotor.spin(forward); */
  /*   leftMotor.spin(forward); */
  /*   task::sleep(500); */
  /* } */
}

