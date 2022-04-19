#ifndef GUI_initialize_H_
#define GUI_initialize_H_

#include <stdint.h>
#include <stdbool.h>
#include <vex.h>
#pragma once

void moveForward(int pos = 800, int speed = 40);
void moveBackward(int pos = 800, int speed = 40);
void turnLeft(int pos = 800, int speed = 40);
void turnRight(int pos = 800, int speed = 40);

#endif