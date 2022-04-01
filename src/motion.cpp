#include "motion.h"
void moveForward(int pos, int speed){
  leftDrive.rotateFor(pos, deg, speed, velocityUnits::pct, false);
  rightDrive.rotateFor(pos, deg, speed, velocityUnits::pct, true);
}
void moveBackward(int pos, int speed){
  leftDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, false);
  rightDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, true);
}
void turnLeft(int pos, int speed){
  leftDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, false);
  rightDrive.rotateFor(pos, deg, speed, velocityUnits::pct, true);
}
void turnRight(int pos, int speed){
  leftDrive.rotateFor(pos, deg, speed, velocityUnits::pct, false);
  rightDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, true);
}