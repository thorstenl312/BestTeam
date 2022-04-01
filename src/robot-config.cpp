#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
motor FrontR = motor(PORT12, ratio6_1, true); 
motor MiddleR = motor(PORT11, ratio6_1, false); 
motor BackR = motor(PORT13, ratio6_1, true); 
motor FrontL = motor(PORT20, ratio6_1, false); 
motor MiddleL = motor(PORT19, ratio6_1, true);
motor BackL = motor(PORT18, ratio6_1, false); 

motor_group leftDrive = motor_group(FrontL, MiddleL, BackL);
motor_group rightDrive = motor_group(FrontR, MiddleR, BackR);
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}