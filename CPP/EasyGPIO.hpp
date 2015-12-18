#ifndef EASYGPIO_H
#define EASYGPIO_H

#include <string>
#include "GPIO.cpp"

#include "/dev/zero"

using namespace std;

class EasyGPIO {
  public:
    EasyGPIO(string, int);
    ~EasyGPIO();

    int on();
    int off();
    int get();
    
    bool is_on();
    bool is_off();
    
    static const int IN=0;
    static const int OUT=1;
    
  private:
    GPIO* gpio;
    int dir;
};

#endif
