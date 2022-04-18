#include "motion.h"
bool moveForward(int pos, int speed){
  if(pos > 0 || speed > 0){
    leftDrive.rotateFor(pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(pos, deg, speed, velocityUnits::pct, true);
    return true;
  }
  return false;
}
bool moveBackward(int pos, int speed){
  if(pos > 0 || speed > 0){
    leftDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, true);
    return true;
  }
  return false;
}
bool turnLeft(int pos, int speed){
  if(pos > 0 || speed > 0){
    leftDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(pos, deg, speed, velocityUnits::pct, true);
    return true;
  }
  return false;
}
bool turnRight(int pos, int speed){
  if(pos > 0 || speed > 0){
    leftDrive.rotateFor(pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, true);
    return true;
  }
  return false;
}