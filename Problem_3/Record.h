///////////////////////////////////
// Filename : Record.h
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Record class header file.
///////////////////////////////////

#ifndef RECORD_H
#define RECORD_H
using std::string;

class Record {
  private:
    string name;
    int number;

  public:
    // Constructor
    // NOTE, vars changed so there's no confusion between private vars.
    Record();
    Record(string na, int nu);
    string getName();
    int getNumber();
    void setName(string s);
    void setNumber(int n);
    // Deconstructor
    ~Record();
};

#endif
