////////////////////////////////////////////
// Filename : myApp.cpp
// Author : Sed Centeno
// Date : 11/6/2024
// 
// Description:
// Implements a Phonebook & Record class and allows the user
// to manipulate the Phonebook, they can insert, delete, display, or obtain a
// number.
//
// Arguments:
// None
//
// Example Invocation:
// ./myApp
///////////////////////////////////////////

#include <iostream>
#include "PhoneBook.h"
#include "Record.h"

using namespace std;

int main(){
  PhoneBook Book("Yellow Pages");
  
  // Menu
  int userchoice, number;
  string name;

  while (true){
    cout << "Please make a selection:" << endl;
    cout << "1. Insert a name and number." << endl;
    cout << "2. Get a number for a person." << endl;
    cout << "3. Display phone book." << endl;
    cout << "4. Remove a person from the phone book" << endl;
    cout << "5. Quit." << endl;
    cout << "Enter your choice: ";
    cin >> userchoice;

    // Choices
    if (userchoice == 1){
      cout << endl << "Enter the name: ";
      cin >> name;
      cout << "Enter the number: ";
      cin >> number;

      Book.insert(name, number);
      cout << endl << "Done." << endl << endl;
    }
    else if (userchoice == 2){
      cout << endl << "Enter the name: ";
      cin >> name;

      int number = Book.getPhoneNumber(name);
      if (number != -1){
        cout << name << "'s number is: " << number << endl << endl;
      }
    }
    else if (userchoice == 3){
      cout << endl;
      Book.displayPhoneBook();
      cout << endl;
    }
    else if (userchoice == 4){
      cout << endl << "Enter the name: ";
      cin >> name;

      Book.removeName(name);
      cout << "Done." << endl << endl;
    }
    else if (userchoice == 5){
      return 0;
    }
  }

  return 0;
}
