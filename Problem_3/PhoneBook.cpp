////////////////////////////////////
// Filename : PhoneBook.cpp
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Implementation file for "PhoneBook.h"
////////////////////////////////////

#include <iostream>
#include "PhoneBook.h"

using namespace std;

int PhoneBook::findName(string s){
  int record_num = 0;

  if (num_records == 0){
    cout << "There are no records in this phone book. ";
    cout << "Please add some record before searching." << endl;
    return 999;
  }

  for (int i = 0; i < getNumberofRecords(); i++){
    if (list[i].getName() == s){
      return i;
    }
  }
  
  return 999;
}

// Default Constructor
PhoneBook::PhoneBook(){
}

// Constructor
PhoneBook::PhoneBook(string s){
  bookName = s;
  num_records = 0;
}

string PhoneBook::getPhoneBookName(){
  return bookName;
}

int PhoneBook::getNumberofRecords(){
  return num_records;
}

void PhoneBook::insert(string name, int number){
  if ((getNumberofRecords() + 1) > MAXSIZE){
    cout << "No more space in this PhoneBook, please remove some entries";
    cout << " before adding new ones." << endl;
    return;
  }

  list[getNumberofRecords()].setName(name);
  list[getNumberofRecords()].setNumber(number);
  num_records++;
  return;
}

void PhoneBook::displayPhoneBook(){
  if (getNumberofRecords() == 0){
    cout << "There are no records in this Phone Book, add some entries." << endl;
    return;
  }

  cout << "---------------------------------------------------------------" <<
  endl << endl;
  
  for (int i = 0; i < getNumberofRecords(); i++){
    cout << "Entry #" << i + 1 << ":" << endl;
    cout << "Person's Name: " << list[i].getName() << endl;
    cout << "Person's Number: " << list[i].getNumber() << endl << endl;
  }

  cout << "---------------------------------------------------------------" << endl;
  return;
}

void PhoneBook::removeName(string s){ 
  if (getNumberofRecords() == 0){
    cout << "There are no records in this Phone Book, add some entries." << endl;
    return;
  }
 
  int index = findName(s);
  if (index == 999){
    cout << "Name not found." << endl;
    return;
  }

  // Check if entry is the last entry.
  if (index == getNumberofRecords()){
    num_records--;
    return;
  }
  
  // If first or in the middle, shift all records to the right of it to the left,
  // replacing the entry.
  for (int i = index; i < getNumberofRecords() - 1; i++){
    list[i] = list[i + 1];
  }
  num_records--;

  return;
}

int PhoneBook::getPhoneNumber(string s){  
  if (getNumberofRecords() == 0){
    cout << "There are no records in this Phone Book, add some entries." << endl;
    return -1;
  }
 
  int index = findName(s);
  if (index == 999){
    cout << "Name not found." << endl << endl;
    return -1;
  }

  return list[index].getNumber();
}
