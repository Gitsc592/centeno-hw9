//////////////////////////////////////////
// Filename : PushBtn.cpp
// Author : Sed Centeno
// Date : 11/5/2024
//
// Description:
// Checks to see if a pull-up pushbutton is pressed,
// if so, it will turn on an external LED.
//
// Arguments:
// None
//
// Example Invocation:
// ./PushBtn
///////////////////////////////////////////

#include<iostream>
#include<fstream>

#define GPIO_PATH "/sys/class/gpio/"

using namespace std;

int main(){
  
  string path(GPIO_PATH);
  
  // Setting directions for gpio60 and gpio46
  fstream file;
  
  // Pushbutton
  file.open((path + "gpio46/direction").c_str(), fstream::out);
  file << "in";
  file.close();

  // External LED
  file.open((path + "gpio60/direction").c_str(), fstream::out);
  file << "out";
  file.close();

  string line;

  // Getting Pushbutton value
  file.open((path + "gpio46/value").c_str(), fstream::in);
  getline(file, line);
  file.close();
  
  // If button is pressed, value will be 0.
  file.open((path + "gpio60/value").c_str(), fstream::out);
  if (line == "0"){
    file << "1";
  }
  else{
    file << "0";
  }
  file.close();

  return 0;
}
