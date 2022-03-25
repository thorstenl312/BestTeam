/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "GUI_initialize.h"
#include "GUI_initialize.cpp"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    //

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  int current_page = 1;
  int autoSelect = 4;

  // Print start up screen
  print_page(current_page, autoSelect);

  Brain.Timer.reset();

  while (true) {
    // GUI page controlls
    int xPress = Brain.Screen.xPosition();
    int yPress = Brain.Screen.yPosition();

    if (current_page == 2){
      /*
      Brain.Screen.setCursor(3, 4);
      Brain.Screen.print("LDB: %.3f", Left_Drive_Bot.current());
      Brain.Screen.setCursor(4, 4);
      Brain.Screen.print("LDT: %.3f", Left_Drive_Top.current());
      Brain.Screen.setCursor(5, 4);
      Brain.Screen.print("RDB: %.3f", Right_Drive_Bot.current());
      Brain.Screen.setCursor(6, 4);
      Brain.Screen.print("RDT: %.3f", Right_Drive_Top.current());
      Brain.Screen.setCursor(8, 4);
      Brain.Screen.print("FTOP: %.3f", Front_Top.current());
      Brain.Screen.setCursor(9, 4);
      Brain.Screen.print("FBOT: %.3f", Front_Bot.current());
      Brain.Screen.setCursor(10, 4);
      Brain.Screen.print("BTOP: %.3f", Back_Top.current());
      Brain.Screen.setCursor(11, 4);
      Brain.Screen.print("BBOT: %.3f", Back_Bot.current());
      Brain.Screen.setCursor(10, 31);
      Brain.Screen.print("INR: %.3f", In_Right.current());
      Brain.Screen.setCursor(11, 31);
      Brain.Screen.print("INL: %.3f", In_Left.current());
      */
    }

    //check if brain is being pressed
    if (Brain.Screen.pressing()){
      while(Brain.Screen.pressing()){}
      // page shifting
      if((xPress >= 10 && xPress <= 130) && (yPress >= 10 && yPress <= 40)){
        // Go to page one
        current_page = 0;
        print_page(current_page, autoSelect);
      }
      else if((xPress >= 180 && xPress <= 300) && (yPress >= 10 && yPress <= 40)){
        // Go to page two
        current_page = 1;
        print_page(current_page, autoSelect);
      }
      else if((xPress >= 360 && xPress <= 480) && (yPress >= 10 && yPress <= 40)){
        // Go to page three
        current_page = 2;
        print_page(current_page, autoSelect);
      }

      //auto selection
      if(current_page == 1){
        if((xPress >= 35 && xPress <= 159) && (yPress >= 45 && yPress <= 110)){
          autoSelect = 1; //red1
          print_page(current_page, autoSelect);
        }
        else if((xPress >= 35 && xPress <= 159) && (yPress >= 135 && yPress <= 200)){
          autoSelect = 2; //red2
          print_page(current_page, autoSelect);
        }
        else if((xPress >= 179 && xPress <= 303) && (yPress >= 45 && yPress <= 200)){
          autoSelect = 3; //skills
          print_page(current_page, autoSelect);
        }
        else if((xPress >= 323 && xPress <= 447) && (yPress >= 45 && yPress <= 110)){
          autoSelect = 4; //blue1
          print_page(current_page, autoSelect);
        }
        else if((xPress >= 323 && xPress <= 447) && (yPress >= 135 && yPress <= 200)){
          autoSelect = 5; //blue2
          print_page(current_page, autoSelect);
        }
      }
    }

    wait(5, msec);
  }

  return 0;
}
