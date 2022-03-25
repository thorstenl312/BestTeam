#include "vex.h"
#include <iostream>

void print_page(int page, int autoSelect){
  //Brain GUI print settings
  Brain.Screen.setPenColor(white);
  if(autoSelect <= 2){
    Brain.Screen.setFillColor(red);
  }
  else if (autoSelect == 3){
    // skills
    Brain.Screen.setFillColor(purple);
  }
  else{
    Brain.Screen.setFillColor(blue);
  }

  Brain.Screen.drawRectangle(0,0, 485, 245);  //boarder showing what color you are
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(15,15, 455, 215);

  // print page 1 screen
  if(page == 0){
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(15,25, "Information"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(185,25, "Auton Select"); //button print
    Brain.Screen.printAt(365,25, "Test Runs"); //button print

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
    if(autoSelect == 1){Brain.Screen.print("Auto: RED1");}
    if(autoSelect == 2){Brain.Screen.print("Auto: RED2");}
    if(autoSelect == 3){Brain.Screen.print("Auto: Skills");}
    if(autoSelect == 4){Brain.Screen.print("Auto: BLUE1");}
    if(autoSelect == 5){Brain.Screen.print("Auto: BLUE2");}
  }
  else if(page == 1){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Information"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(185,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(365,25, "Test Runs"); //button print

    // print auto buttons
    if(autoSelect == 1){
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(black); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 2){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(black); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 3){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 4){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(black); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }
    else if(autoSelect == 5){
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(35, 135, 124, 65);
      Brain.Screen.setFillColor(black); Brain.Screen.drawRectangle(179, 45, 124, 155);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(323, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(323, 135, 124, 65);
    }

    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(77, 80, "RED1"); Brain.Screen.printAt(77, 170, "RED2"); Brain.Screen.printAt(214, 125, "Skills"); Brain.Screen.printAt(360, 80, "BLUE1"); Brain.Screen.printAt(360, 170, "BLUE2");
  }
  else if(page == 2){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Information"); //button print
    Brain.Screen.printAt(185,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(365,25, "Test Runs"); //button print
    Brain.Screen.setFillColor(transparent);

    // print the general info
    Brain.Screen.setCursor(3, 31);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    Brain.Screen.setCursor(5, 31);
    if(autoSelect == 1){Brain.Screen.print("Auto: RED1");}
    if(autoSelect == 2){Brain.Screen.print("Auto: RED2");}
    if(autoSelect == 3){Brain.Screen.print("Auto: Skills");}
    if(autoSelect == 4){Brain.Screen.print("Auto: BLUE1");}
    if(autoSelect == 5){Brain.Screen.print("Auto: BLUE2");}
  }
}