#include "vex.h"
#include <iostream>

void print_page(int page, int autoSelect){
  //Brain GUI print settings
  Brain.Screen.setPenColor(white);
  if (autoSelect == 1){
    Brain.Screen.setFillColor(yellow);
  }
  else if (autoSelect == 2){
    // skills
    Brain.Screen.setFillColor(blue);
  }
  else if (autoSelect == 3){
    Brain.Screen.setFillColor(red);
  }
  else if (autoSelect == 4) {
    Brain.Screen.setFillColor(purple);
  }

  Brain.Screen.drawRectangle(0,0, 485, 245);  //boarder showing what color you are
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(15,15, 455, 215);

  // print page 1 screen
  if(page == 0){
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(15,25, "Vitals"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(100,25, "Auton Select"); //button print
    Brain.Screen.printAt(260,25, "Test Runs"); //button print
    Brain.Screen.printAt(380,25, "Controls"); //button print

    // print the sensor info
    Brain.Screen.setCursor(3, 4);
    //Brain.Screen.print("Brake Beam1: %s", beam1 ? "true" : "false");
    Brain.Screen.print("Brake Beam1: %s", true ? "true" : "false");
    Brain.Screen.setCursor(4, 4);
    //Brain.Screen.print("Brake Beam2: %s", beam1 ? "true" : "false");
    Brain.Screen.print("Brake Beam2: %s", false ? "true" : "false");
    Brain.Screen.setCursor(5, 4);
    //Brain.Screen.print("Brake Beam3: %s", beam1 ? "true" : "false");
    Brain.Screen.print("Brake Beam3: %s", true ? "true" : "false");
    Brain.Screen.printAt(150, 125, "o");
    Brain.Screen.setCursor(7, 4);
    //Brain.Screen.print("Heading: %.1f", Inertial.value());
    Brain.Screen.print("Heading: %.1f", 1.000);
    Brain.Screen.setCursor(8, 4);
    //Brain.Screen.print("Encoder: %.1f clicks", Encoder.value());
    Brain.Screen.print("Encoder: %.1f clicks", 1.2345);

    // print the general info
    Brain.Screen.setCursor(3, 31);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    Brain.Screen.setCursor(5, 31);
    if(autoSelect == 1){Brain.Screen.print("Auto: Forward");}
    if(autoSelect == 2){Brain.Screen.print("Auto: T-Left");}
    if(autoSelect == 3){Brain.Screen.print("Auto: Backward");}
    if(autoSelect == 4){Brain.Screen.print("Auto: T-Right");}
  }
  else if(page == 1){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Vitals"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(100,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(260,25, "Test Runs"); //button print
    Brain.Screen.printAt(380,25, "Controls"); //button print

    // print auto buttons
    if(autoSelect == 1){
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 135, 124, 65);
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.setCursor(4, 33);
      Brain.Screen.print("Speed: %.1f", 100.0);
      Brain.Screen.setCursor(9, 33);
      Brain.Screen.print("Distance: ");
    }
    else if(autoSelect == 2){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 135, 124, 65);
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.setCursor(4, 33);
      Brain.Screen.print("Speed: %.1f", 0.0);
      Brain.Screen.setCursor(9, 33);
      Brain.Screen.print("Distance: ");
    }
    else if(autoSelect == 3){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 135, 124, 65);
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.setCursor(4, 33);
      Brain.Screen.print("Speed: %.1f", 50.0);
      Brain.Screen.setCursor(9, 33);
      Brain.Screen.print("Distance: ");
    }
    else if(autoSelect == 4){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(179, 135, 124, 65);
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.setCursor(4, 33);
      Brain.Screen.print("Speed: %.1f", 0.0);
      Brain.Screen.setCursor(9, 33);
      Brain.Screen.print("Distance: ");
    }
    
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(60, 80, "Forward"); Brain.Screen.printAt(65, 170, "T-Left"); Brain.Screen.printAt(202, 80, "Backward"); Brain.Screen.printAt(206, 170, "T-Right");
  }
  else if(page == 2){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Vitals"); //button print
    Brain.Screen.printAt(100,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(260,25, "Test Runs"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(380,25, "Controls"); //button print

    // print the general info
    Brain.Screen.setCursor(3, 31);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    Brain.Screen.setCursor(5, 31);
    if(autoSelect == 1){Brain.Screen.print("Auto: Forward");}
    if(autoSelect == 2){Brain.Screen.print("Auto: T-Left");}
    if(autoSelect == 3){Brain.Screen.print("Auto: Backward");}
    if(autoSelect == 4){Brain.Screen.print("Auto: T-Right");}
  }
  else if(page == 3){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Vitals"); //button print
    Brain.Screen.printAt(100,25, "Auton Select"); //button print
    Brain.Screen.printAt(260,25, "Test Runs"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(380,25, "Controls"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement:");
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed:");
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Traverse:");
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");

    if(autoSelect == 6){
      Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Forwards");
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %.1f units/s", 100.0);
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Traverse: %.1f degrees", 0.0);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    }
    else if(autoSelect == 7){
      Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Turn Left");
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %.1f units/s", 0.0);
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Traverse: %.1f degrees", -15.0);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    }
    else if(autoSelect == 8){
      Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Turn Right");
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %.1f units/s", 0.0);
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Traverse: %.1f degrees", 15.0);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    }
    else if(autoSelect == 9){
      Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Backwards");
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %.1f units/s", -25.0);
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Traverse: %.1f degrees", 0.0);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    }
  }
}