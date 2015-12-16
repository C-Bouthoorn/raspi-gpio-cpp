#ifndef GPIO_H
#define GPIO_H

#include <string>
using namespace std;

class GPIO {
  public:
    GPIO();
    GPIO(string);
    ~GPIO();
    
    int gpio_export();
    int gpio_unexport();
    
    int setdir(string);
    int setval(string);
    int getval(string&);
    
    string get_gpionum();
  private:
    string gpionum;
};

#endif