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
  moveForward(700, 40);
  wait(3000,msec);
  moveBackward(700, 40);
  wait(3000, msec);
  turnLeft(700, 40);
  wait(3000, msec);
  turnRight(700, 40);
  while (1) {
    //

    wait(15, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
                    //this
  }
}

bool autonSel(int select)
{
  bool sel = false;
  int currentSel = select;
  if (currentSel >= 0 && currentSel < 5)
      sel = true;
  return sel;
}

bool control(int controlRes)
{
  bool con = false;
  int currentControl = controlRes;
  if (currentControl > 5 && currentControl < 10)
      con = true;
  return con;
}

//
// Main will set up the functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  int current_page = 1;
  int autoSelect = 0;

  int paramSpeed = 40;
  int paramDist = 800;

  // Print start up screen
  print_page(current_page, autoSelect, paramSpeed, paramDist);
  Brain.Timer.reset();
  
  vex::brain::sdcard SDcard;//sdcard initialization for file io
  TryToDrawImageFile(0,0,&Brain, &SDcard,"info.png");
  vex::wait(1, msec);


  while (true) {
    // GUI page controlls
    int xPress = Brain.Screen.xPosition();
    int yPress = Brain.Screen.yPosition();

    if (current_page == 2){
      
      Brain.Screen.setCursor(3, 4);
      Brain.Screen.print("LDB: %.3f");
      Brain.Screen.setCursor(4, 4);
      Brain.Screen.print("LDT: %.3f");
      Brain.Screen.setCursor(5, 4);
      Brain.Screen.print("RDB: %.3f");
      Brain.Screen.setCursor(6, 4);
      Brain.Screen.print("RDT: %.3f");
      Brain.Screen.setCursor(8, 4);
      Brain.Screen.print("FTOP: %.3f");
      Brain.Screen.setCursor(9, 4);
      Brain.Screen.print("FBOT: %.3f");
      Brain.Screen.setCursor(10, 4);
      Brain.Screen.print("BTOP: %.3f");
      Brain.Screen.setCursor(11, 4);
      Brain.Screen.print("BBOT: %.3f");
      Brain.Screen.setCursor(10, 31);
      Brain.Screen.print("INR: %.3f");
      Brain.Screen.setCursor(11, 31);
      Brain.Screen.print("INL: %.3f");
      
    }

    bool testAuto = false;
    bool testControl = false;
    //check if brain is being pressed
    if (Brain.Screen.pressing()){
      while(Brain.Screen.pressing()){}
      // page shifting
      if((xPress >= 10 && xPress <= 130) && (yPress >= 10 && yPress <= 40)){
        // Go to page one
        current_page = 0;
        print_page(current_page, autoSelect, paramSpeed, paramDist);
      }
      else if((xPress >= 100 && xPress <= 240) && (yPress >= 10 && yPress <= 40)){
        // Go to page two
        current_page = 1;
        print_page(current_page, autoSelect, paramSpeed, paramDist);
      }
      else if((xPress >= 270 && xPress <= 370) && (yPress >= 10 && yPress <= 40)){
        // Go to page three
        current_page = 2;
        print_page(current_page, autoSelect, paramSpeed, paramDist);
      }
      else if((xPress >= 380 && xPress <= 470) && (yPress >= 10 && yPress <= 40)){
        // Go to page four
        current_page = 3;
        print_page(current_page, autoSelect, paramSpeed, paramDist);
      }

      //auto selection
      if(current_page == 1)
      {
        if((xPress >= 320 && xPress <= 380) && (yPress >= 65 && yPress <= 115))
        {
          paramSpeed -= 10;
          print_page(current_page, autoSelect, paramSpeed, paramDist);
        }
        else if((xPress >= 380 && xPress <= 440) && (yPress >= 65 && yPress <= 115))
        {
          paramSpeed += 10;
          print_page(current_page, autoSelect, paramSpeed, paramDist);
        }

        if((xPress >= 320 && xPress <= 380) && (yPress >= 145 && yPress <= 195))
        {
          paramDist -= 100;
          print_page(current_page, autoSelect, paramSpeed, paramDist);
        }
        else if((xPress >= 380 && xPress <= 440) && (yPress >= 145 && yPress <= 195))
        {
          paramDist += 100;
          print_page(current_page, autoSelect, paramSpeed, paramDist);
        }

        if((xPress >= 35 && xPress <= 159) && (yPress >= 45 && yPress <= 110)){
          autoSelect = 1; //Forward
          testAuto = autonSel(autoSelect);
          if(testAuto)
          {
            print_page(current_page, autoSelect, paramSpeed, paramDist);
            moveForward(paramDist, paramSpeed);
          }
        }
        else if((xPress >= 35 && xPress <= 159) && (yPress >= 155 && yPress <= 220)){
          autoSelect = 2; //Turn Left
          print_page(current_page, autoSelect, paramSpeed, paramDist);
          turnLeft(paramDist, paramSpeed);
        }
        else if((xPress >= 179 && xPress <= 303) && (yPress >= 45 && yPress <= 110)){
          autoSelect = 3; //Backward
          print_page(current_page, autoSelect, paramSpeed, paramDist);
          moveBackward(paramDist, paramSpeed);
        }
        else if((xPress >= 179 && xPress <= 303) && (yPress >= 155 && yPress <= 220)){
          autoSelect = 4; //Turn Right
          testAuto = autonSel(autoSelect);
          if(testAuto)
          {
            print_page(current_page, autoSelect, paramSpeed, paramDist);
            turnRight(paramDist, paramSpeed);
          }
        }
        
      }

      //Control
      if(current_page == 3){
        if((xPress >= 320 && xPress <= 390) && (yPress >= 35 && yPress <= 105)){
          autoSelect = 6; //Forwards
          testControl = control(autoSelect);
          if(testControl)
          {
            print_page(current_page, autoSelect, paramSpeed, paramDist);
          }
        }
        else if((xPress >= 255 && xPress <= 325) && (yPress >= 95 && yPress <= 165)){
          autoSelect = 7; //Left
          print_page(current_page, autoSelect, paramSpeed, paramDist);
        }
        else if((xPress >= 385 && xPress <= 455) && (yPress >= 95 && yPress <= 165)){
          autoSelect = 8; //Right
          print_page(current_page, autoSelect, paramSpeed, paramDist);
        }
        else if((xPress >= 320 && xPress <= 390) && (yPress >= 155 && yPress <= 225)){
          autoSelect = 9; //Backwards
          testControl = control(autoSelect);
          if(testControl)
          {
            print_page(current_page, autoSelect, paramSpeed, paramDist);
          }
        }
      }
    }

    wait(6, msec);
  }
  return 0;
}
