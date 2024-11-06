////////////////////////////////
// Filename : myGpioApp.cpp
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Main function file that implements the class in "myGpio.h"
// Sets the direction of GPIO 60 and 46, and turns on GPIO 60 for 3 seconds and
// off, then prints its value. Next it reads the value of GPIO 46.
//
// Arguments:
// None
// 
// Example Invocation:
// ./myGpioApp
////////////////////////////////

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "myGpio.h"

int main(){

  // (a) Pushbutton Pin
  MYGPIO PushBtn(46);
  PushBtn.setDirection(IN);

  // (b) LED Pin
  MYGPIO LED(60);
  LED.setDirection(OUT);

  // (c)
  LED.setValue(HIGH);
  cout << "GPIO " << LED.getNumber() << " has been set to " << LED.getValue() << endl;
  sleep(3);
  LED.setValue(LOW);
  cout << "GPIO " << LED.getNumber() << " has been set to " << LED.getValue() << endl;

  // (d)
  cout << "The value of GPIO " << PushBtn.getNumber() << " is ";
  cout << PushBtn.getValue() << endl;

  return 0;
}
