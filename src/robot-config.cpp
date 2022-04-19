#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
//right drive
motor rightMotorA = motor(PORT16, ratio6_1, false); //front
motor rightMotorB = motor(PORT15, ratio6_1, true); //middle
motor rightMotorC = motor(PORT17, ratio6_1, false); //middle
motor rightMotorD = motor(PORT9, ratio6_1, true); //back
motor_group rightDrive = motor_group(rightMotorA, rightMotorB, rightMotorC, rightMotorD);

//left drive
motor leftMotorA = motor(PORT8, ratio6_1, true); //front
motor leftMotorB = motor(PORT18, ratio6_1, false); //middle
motor leftMotorC = motor(PORT20, ratio6_1, true); //middle
motor leftMotorD = motor(PORT19, ratio6_1, false); //back
motor_group leftDrive = motor_group(leftMotorA, leftMotorB, leftMotorC, leftMotorD);
limit beam1 = limit(Brain.ThreeWirePort.A);
limit beam2 = limit(Brain.ThreeWirePort.B);
limit beam3 = limit(Brain.ThreeWirePort.C);
inertial inert = inertial(PORT12);
rotation rotate = rotation(PORT2);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
