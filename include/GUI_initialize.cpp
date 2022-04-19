#include "vex.h"
#include "GUI_initialize.h"
#include <iostream>

//Movement functions
void moveForward(int pos, int speed){
  if(pos < 2000 && pos > 200 && speed <= 100 && speed >= 10){
    leftDrive.rotateFor(pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(pos, deg, speed, velocityUnits::pct, true);
    
  }
  
}
void moveBackward(int pos, int speed){
  if(pos < 2000 && pos > 200 && speed <= 100 && speed >= 10){
    leftDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, true);
    
  }
  
}
void turnLeft(int pos, int speed){
  if(pos < 2000 && pos > 200 && speed <= 100 && speed >= 10){
    leftDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(pos, deg, speed, velocityUnits::pct, true);
    
  }
  
}
void turnRight(int pos, int speed){
  if(pos < 2000 && pos > 200 && speed <= 100 && speed >= 10){
    leftDrive.rotateFor(pos, deg, speed, velocityUnits::pct, false);
    rightDrive.rotateFor(-pos, deg, speed, velocityUnits::pct, true);

  }
  
}


void print_page(int page, int autoSelect, int paramSpeed, int paramDist){
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

//Min and Max Speed and Distance
  int maxSpeed = 100;
  int minSpeed = 10;
  int maxDist = 2000;
  int minDist = 200;

//Speed and Distance from User
  int userSpeed = 40;
  int userDistance = 800;

//Default Speed and Distance
  int defaultSpeed = 40;
  int defaultDistance = 800;

  //Vitals Page
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
    Brain.Screen.print("Brake Beam1: %s", beam1.value() ? "true" : "false");
    Brain.Screen.setCursor(4, 4);
    //Brain.Screen.print("Brake Beam2: %s", beam1 ? "true" : "false");
    Brain.Screen.print("Brake Beam2: %s", beam1.value() ? "true" : "false");
    Brain.Screen.setCursor(5, 4);
    //Brain.Screen.print("Brake Beam3: %s", beam1 ? "true" : "false");
    Brain.Screen.print("Brake Beam3: %s", beam1.value() ? "true" : "false");
    Brain.Screen.printAt(150, 125, "o");
    Brain.Screen.setCursor(7, 4);
    //Brain.Screen.print("Heading: %.1f", Inertial.value());
    Brain.Screen.print("Heading: %.1f", inert.heading());
    Brain.Screen.setCursor(8, 4);
    //Brain.Screen.print("Encoder: %.1f clicks", Encoder.value());
    Brain.Screen.print("Encoder: %.1f clicks", rotate.position(deg));
    Brain.Screen.setCursor(9, 4);
    Brain.Screen.print("Left Drive Temperature: %.1f °F", leftDrive.temperature(temperatureUnits::fahrenheit));
    Brain.Screen.setCursor(10, 4);
    Brain.Screen.print("Right Drive Temperature: %.1f °F", rightDrive.temperature(temperatureUnits::fahrenheit));
    // print the general info
    Brain.Screen.setCursor(3, 31);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");
    Brain.Screen.setCursor(5, 31);
    if(autoSelect == 1){Brain.Screen.print("Auto: Forward");}
    if(autoSelect == 2){Brain.Screen.print("Auto: T-Left");}
    if(autoSelect == 3){Brain.Screen.print("Auto: Backward");}
    if(autoSelect == 4){Brain.Screen.print("Auto: T-Right");}
  }

  //Auton Select Page
  else if(page == 1){
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(15,25, "Vitals"); //button print
    Brain.Screen.setFillColor(green);
    Brain.Screen.printAt(100,25, "Auton Select"); //button print
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(260,25, "Test Runs"); //button print
    Brain.Screen.printAt(380,25, "Controls"); //button print
    Brain.Screen.setFillColor(black); Brain.Screen.drawRectangle(149, 112, 40, 40);

    // print auto buttons
    //Forward
    if(autoSelect == 0){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 155, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 155, 124, 65);

      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 65, 120, 50);
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 145, 120, 50);

      //Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(149, 112, 40, 40);
      
      Brain.Screen.setFillColor(orange);

      Brain.Screen.setCursor(5, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(5, 41);
      Brain.Screen.print("+");
      Brain.Screen.setCursor(9, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(9, 41);
      Brain.Screen.print("+");


      //moveForward(paramDist, paramSpeed);
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.setCursor(3, 33);
      Brain.Screen.print("Speed: %d", paramSpeed);
      Brain.Screen.setCursor(7, 33);
      Brain.Screen.print("Distance: %d", paramDist);
    }
    if(autoSelect == 1){
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 155, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 155, 124, 65);

      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 65, 120, 50);
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 145, 120, 50);

      //Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(149, 112, 40, 40);
      
      Brain.Screen.setFillColor(orange);

      Brain.Screen.setCursor(5, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(5, 41);
      Brain.Screen.print("+");
      Brain.Screen.setCursor(9, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(9, 41);
      Brain.Screen.print("+");


      //moveForward(paramDist, paramSpeed);
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.setCursor(3, 33);
      Brain.Screen.print("Speed: %d", paramSpeed);
      Brain.Screen.setCursor(7, 33);
      Brain.Screen.print("Distance: %d", paramDist);
      
    }

    //Turn Left
    else if(autoSelect == 2){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(35, 155, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 155, 124, 65);
      
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 65, 120, 50);
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 145, 120, 50);
      
      Brain.Screen.setFillColor(orange);

      Brain.Screen.setCursor(5, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(5, 41);
      Brain.Screen.print("+");
      Brain.Screen.setCursor(9, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(9, 41);
      Brain.Screen.print("+");


      Brain.Screen.setFillColor(transparent);

      //turnLeft(paramDist, paramSpeed);
      Brain.Screen.setCursor(3, 33);
      Brain.Screen.print("Speed: %d", paramSpeed);
      Brain.Screen.setCursor(7, 33);
      Brain.Screen.print("Distance: %d", paramDist);
      
    }

    //Backward
    else if(autoSelect == 3){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 155, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(purple); Brain.Screen.drawRectangle(179, 155, 124, 65);
      
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 65, 120, 50);
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 145, 120, 50);
      
      Brain.Screen.setFillColor(orange);

      Brain.Screen.setCursor(5, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(5, 41);
      Brain.Screen.print("+");
      Brain.Screen.setCursor(9, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(9, 41);
      Brain.Screen.print("+");


      Brain.Screen.setFillColor(transparent);
      
      //moveBackward(paramDist,paramSpeed);
      Brain.Screen.setCursor(3, 33);
      Brain.Screen.print("Speed: %d", paramSpeed);
      Brain.Screen.setCursor(7, 33);
      Brain.Screen.print("Distance: %d", paramDist);
      
    }

    //Turn Right
    else if(autoSelect == 4){
      Brain.Screen.setFillColor(yellow); Brain.Screen.drawRectangle(35, 45, 124, 65);
      Brain.Screen.setFillColor(blue); Brain.Screen.drawRectangle(35, 155, 124, 65);
      Brain.Screen.setFillColor(red); Brain.Screen.drawRectangle(179, 45, 124, 65);
      Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(179, 155, 124, 65);
      
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 65, 120, 50);
      Brain.Screen.setFillColor(orange); Brain.Screen.drawRectangle(320, 145, 120, 50);
      
      Brain.Screen.setFillColor(orange);

      Brain.Screen.setCursor(5, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(5, 41);
      Brain.Screen.print("+");
      Brain.Screen.setCursor(9, 35);
      Brain.Screen.print("-");
      Brain.Screen.setCursor(9, 41);
      Brain.Screen.print("+");
      
      Brain.Screen.setFillColor(transparent);

      //turnRight(paramDist,paramSpeed);
      Brain.Screen.setCursor(3, 33);
      Brain.Screen.print("Speed: %d", paramSpeed);
      Brain.Screen.setCursor(7, 33);
      Brain.Screen.print("Distance: %d", paramDist);
      
      
    }
    
    
      
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(60, 80, "Forward"); Brain.Screen.printAt(65, 190, "T-Left"); Brain.Screen.printAt(202, 80, "Backward"); Brain.Screen.printAt(206, 190, "T-Right");
      vex::wait(2,seconds);
    Brain.Screen.setFillColor(green); Brain.Screen.drawRectangle(149, 112, 40, 40); 
  }

  //Test Run Page
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

  //Controls Page
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
    Brain.Screen.print("Distance:");
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%%");

    if(autoSelect == 6){
      Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Forward");

    moveForward(defaultDistance, defaultSpeed);
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %d%s", defaultSpeed, "%");
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Distance: %d units", defaultDistance);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%");
    }
    else if(autoSelect == 7){
      Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Turn Left");

    turnLeft(defaultDistance, defaultSpeed);
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %d%s", defaultSpeed, "%");
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Distance: %d units", defaultDistance);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%");
    }
    else if(autoSelect == 8){
      Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Turn Right");

    turnRight(defaultDistance, defaultSpeed);
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %d%s", defaultSpeed, "%");
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Distance: %d units", defaultDistance);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%");
    }
    else if(autoSelect == 9){
      Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(355, 70, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(290, 130, 35);
    Brain.Screen.setFillColor(red); Brain.Screen.drawCircle(420, 130, 35);
    Brain.Screen.setFillColor(green); Brain.Screen.drawCircle(355, 190, 35);

    Brain.Screen.setCursor(3, 4);
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.print("Movement: Backward");

    moveBackward(defaultDistance, defaultSpeed);
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Speed: %d%s", defaultSpeed, "%");
    Brain.Screen.setCursor(5, 4);
    Brain.Screen.print("Distance: %d units", defaultDistance);
    Brain.Screen.setCursor(11, 4);
    Brain.Screen.print("Battery lvl: %d%s", Brain.Battery.capacity(pct), "%");
    }
  }
}

//File I/O Functions
 /* example test function call from main for below functions
 vex::brain::sdcard SDcard;
if(TryToWriteTextFile(&Brain,&SDcard,"out.txt","when i test this what to put in da thingnew")){
std::cout<<"1\n";
  std::cout<<"3MissingImageTest- "<<TryToDrawImageFile(0,0,&Brain,&SDcard,"nothere.png")<<" should be: 0"<<std::endl;
}*/
bool TryToDrawImageFile(int x, int y,  vex::brain* B, vex::brain::sdcard* sd, const char* filename){
  //attempts to draw png filename at x,y. If placed below or to the right of the screen(out of bounds), no sd card, file DNE, or draw request returns false, then return false. Negative x/y should be allowed (up and to the left of the screen)
  if(x>=480||y>=240){return false;}  
    else if ((*sd).isInserted()){
      if(!(*sd).exists(filename)){
          return false;
        }
    else return (Brain.Screen.drawImageFromFile( filename, x, y ));

    }
    else return false;
    }
  

bool TryToWriteTextFile(vex::brain* B, vex::brain::sdcard* sd,const char* filename, std::string text){ 
  //if file exists, overwriteit, return true; if file DNE write it, return true. In either case, if it does not return #bytes written to t, return false
   char arr[text.length()];
   strcpy(arr,text.c_str());
    if ((*sd).isInserted()){
        if(((*sd).exists(filename))){  
            int t=-1;
            uint8_t* at=(uint8_t*) arr;
            t=(*sd).savefile(filename,at,text.length());
            if(t>=0){return true;}
            else{return false;}
        }
        else {
          int t=-1;
          uint8_t* at=(uint8_t*) arr;
          t=(*sd).savefile(filename,at,text.length());
          if(t>=0){return true;}
           else{return false;}
        }
    }
return false;
}

bool TryToAppend(vex::brain* B, vex::brain::sdcard* sd,const char* filename, std::string text){
   //if file exists, append text to it, return true if successful(number of bytes appended passed to t). If file DNE, do nothing, return false
    char arr[text.length()];
     strcpy(arr,text.c_str());
    if ((*sd).isInserted()){
        if(((*sd).exists(filename))){  
            int t=-1;
            uint8_t* at=(uint8_t*) arr;
            t=(*sd).appendfile(filename,at,text.length());
            if(t>=0){return true;}
           else{return false;}
        }
        else {
          return false;
        }
    }
   return false;
}
bool AppendOrNew(vex::brain* B, vex::brain::sdcard* sd,const char* filename, std::string text){
   //if file exists, append text to it, return true if successful(number of bits appended passed to t). If file DNE, create new file, return true if successful(number of bytes written passed to t)
      char arr[text.length()];
      strcpy(arr,text.c_str());
      if ((*sd).isInserted()){
        if(((*sd).exists(filename))){  
          int t=-1;
          uint8_t* at=(uint8_t*) arr;
          t=(*sd).appendfile(filename,at,text.length());
            if(t>=0){return true;}
            else{return false;}
        }
        else {
          int t=-1;
          uint8_t* at=(uint8_t*) arr;
          t=(*sd).savefile(filename,at,text.length());
            if(t>=0){return true;}
            else{return false;}
        }
        
      }
  return false;
}
