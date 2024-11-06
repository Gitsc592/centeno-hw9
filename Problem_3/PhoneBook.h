///////////////////////////////////////
// Filename : PhoneBook.h
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Header file for the PhoneBook class.
///////////////////////////////////////

#include "Record.h"

#ifndef PB_H
#define PB_H
#define MAXSIZE 10

using std::string;

class PhoneBook {
  private:
    Record list[MAXSIZE];
    string bookName;
    int num_records;
    int findName(string s);

  public:
    // Default Constructor
    PhoneBook();
    // Constructor
    PhoneBook(string s);
    string getPhoneBookName();
    int getNumberofRecords();
    void insert(string name, int number);
    void displayPhoneBook();
    void removeName(string s);
    int getPhoneNumber(string s);
};

#endif
