#ifndef EASYGPIO_H
#define EASYGPIO_H

#include <string>
#include "GPIO.cpp"

using namespace std;

class EasyGPIO {
  public:
    EasyGPIO(string);
    ~EasyGPIO();

    int start(string dir);
    int stop();

    int on();
    int off();
    int get();
  private:
    GPIO* gpio;
    string dir;
};

#endif
