///////////////////////////////////
// Filename : Record.cpp
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Implementation file for "Record.h"
//////////////////////////////////

#include <iostream>
#include "Record.h"

// Constructor
Record::Record(string na, int nu){
  name = na;
  number = nu;
}

Record::Record(){
}

string Record::getName(){
  return name;
}

int Record::getNumber(){
  return number;
}

void Record::setName(string s){
  name = s;
  return;
}

void Record::setNumber(int n){
  number = n;
  return;
}

// Default Deconstructor
Record::~Record(){
}
