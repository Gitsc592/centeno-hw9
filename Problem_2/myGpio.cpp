//////////////////////////////////
// Filename : myGpio.cpp
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Implements the class in "myGpio.h"
//////////////////////////////////

#include <iostream>
#include <fstream>

#include "myGpio.h"

int MYGPIO::write(string path, string filename, string value){
  fstream file;
  file.open((path + filename).c_str(), fstream::out);
  file << value;
  file.close();
  return 0;
}

int MYGPIO::write(string path, string filename, int value){
  fstream file;
  file.open((path + filename).c_str(), fstream::out);
  file << value;
  file.close();
  return 0;
}

string MYGPIO::read(string path, string filename){
  string line;
  fstream file;
  file.open((path + filename).c_str(), fstream::in);
  getline(file, line);
  return line;
}

// Constructor
MYGPIO::MYGPIO(int N){
  number = N;
  name = "gpio" + to_string(N);
  path = "/sys/class/gpio/" + name;
}

// Deconstructor
MYGPIO::~MYGPIO(){
}

int MYGPIO::getNumber(){
  return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir){
  if (dir == IN){
    write(path, "/direction", "in");
  }
  else if (dir == OUT){
    write(path, "/direction", "out");
  }
  return;
}

GPIO_DIRECTION MYGPIO::getDirection(){
  GPIO_DIRECTION dir;
  string line = read(path, "/direction");

  if (line == "in"){
    dir = IN;
  }
  else if (line == "out"){
    dir = OUT;
  }

  return dir;
}

int MYGPIO::setValue(GPIO_VALUE val){
  write(path, "/value", val); // By default, 1st ENum = 0, 2nd = 1, etc.
  return 0;
}

GPIO_VALUE MYGPIO::getValue(){
  GPIO_VALUE val;
  string line = read(path, "/value");

  if (line == "0"){
    val = LOW;
  }
  else if (line == "1"){
    val = HIGH;
  }

  return val;
}

void MYGPIO::toggleOutput(){
  if (getDirection() != OUT){
    cout << "Pin is not an output, please set it to output first." << endl;
    return;
  }
  
  
  if (getValue() == LOW){
    setValue(HIGH);
  }
  else if (getValue() == HIGH){
    setValue(LOW);
  }
  
  return;
}
