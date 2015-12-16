#include <iostream>
#include <string>

#include "EasyGPIO.hpp"

using namespace std;

// Custom constructor: pin `pin`
EasyGPIO::EasyGPIO(string pin) {
  this->gpio = new GPIO(pin);
  this->gpio->gpio_export();
}

// When object gets destroyed: Unexport
EasyGPIO::~EasyGPIO() {
  this->gpio->gpio_unexport();
}

// Start pin
int EasyGPIO::start(string dir) {
  
  if( !( dir=="in" || dir=="out") ) {
    cerr << "Invalid direction: '" << dir << "'!" << endl;
    return -1;
  }
  
  this->dir=dir;
  return this->gpio->setdir(dir);
}

// Turn on
int EasyGPIO::on() {
  if(this->dir=="in") {
    
    return -1;
  }
  return this->gpio->setval("1");
}

// Get current gpio pin
string EasyGPIO::get_gpionum(){
  return this->gpio->gpionum;
}