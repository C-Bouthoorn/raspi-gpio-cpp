#include <iostream>
#include <string>
#include <stdlib.h>

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
    cerr << "Can't change value of pin when direction is input." << endl;
    return -1;
  }

  return this->gpio->setval("1");
}

// Turn on
int EasyGPIO::off() {
  if(this->dir=="in") {
    cerr << "Can't change value of pin when direction is input." << endl;
    return -1;
  }

  return this->gpio->setval("0");
}

int EasyGPIO::get() {
  if(this->dir=="out") {
    cerr << "Can't get value of pin when direction is output." << endl;
    return -1;
  }

  string val;
  int x=this->gpio->getval(val);

  if(x < 0) {
    return x;
  } else {
    return atoi(val);
  }
}
