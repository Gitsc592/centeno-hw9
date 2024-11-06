/////////////////////////////////
// Filename : myGpio.h
// Author : Sed Centeno
// Date : 11/6/2024
//
// Description:
// Header file for myGpio.cpp and myGpioApp.cpp
/////////////////////////////////

using namespace std;

enum GPIO_DIRECTION {
  IN,
  OUT
};

enum GPIO_VALUE {
  LOW,
  HIGH
};

class MYGPIO {
  private:
    int number;
    string name, path;
    int write(string path, string filename, string value);
    int write(string path, string filename, int value);
    string read(string path, string filename);
    ofstream stream;
  public:
    // NOTE, changed "number" to "N" so to avoid compiler confusion with private var.
    MYGPIO(int N); //constructor
    int getNumber();
    void setDirection(GPIO_DIRECTION dir);
    GPIO_DIRECTION getDirection();
    int setValue(GPIO_VALUE val);
    GPIO_VALUE getValue();
    void toggleOutput();
    ~MYGPIO(); //destructor
};
