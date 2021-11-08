#include "vex.h"
#include "vex_brain.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotor = motor(PORT1, ratio18_1, false);
motor rightMotor = motor(PORT2, ratio18_1, true);
motor armMotor = motor(PORT3, ratio18_1, false);

line leftLine = line(Brain.ThreeWirePort.A);
line rightLine = line(Brain.ThreeWirePort.B);
sonar rangeFinder = sonar(Brain.ThreeWirePort.C);
// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
