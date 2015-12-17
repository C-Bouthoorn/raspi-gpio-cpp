#include <iostream>
#include <string>
#include <stdlib.h>

#include "EasyGPIO.hpp"

using namespace std;

// Custom constructor: pin `pin`
EasyGPIO::EasyGPIO(string pin, int dir) {
  this->gpio = new GPIO(pin);

  // Set direction
  if ( !( dir==EasyGPIO::IN || dir==EasyGPIO::OUT )) {
    cerr << "Invalid direction: '" << dir << "'!" << endl;
    cerr << "Assume OUT" << endl;
    dir = EasyGPIO::OUT;
  }
  
  this->dir=dir;
  
  string s_dir = ( dir == EasyGPIO::IN ? "IN" : "OUT" );
  this->gpio->setdir(s_dir);
}

// When object gets destroyed: Unexport
EasyGPIO::~EasyGPIO() {
  // Free memory
  delete this->gpio;
  this->gpio = NULL;
}

// Turn on
int EasyGPIO::on() {
  if(this->dir != EasyGPIO::OUT) {
    cerr << "Can't change value of pin! [Wrong direction]" << endl;
    return -1;
  }

  return this->gpio->setval("1");
}

// Turn on
int EasyGPIO::off() {
  if(this->dir != EasyGPIO::OUT) {
    cerr << "Can't change value of pin! [Wrong direction]" << endl;
    return -1;
  }

  return this->gpio->setval("0");
}

// Check if pin is on
bool EasyGPIO::is_on() {
  return EasyGPIO::get() == 1;
}

// Check if pin is off
bool EasyGPIO::is_off() {
  return EasyGPIO::get() == 0;
}

// Get value from pin
int EasyGPIO::get() {
  if(this->dir != EasyGPIO::IN) {
    cerr << "Can't change value of pin! [Wrong direction]" << endl;
    return -1;
  }

  string val;
  int x = this->gpio->getval(val);

  if(x < 0) {
    return x;
  } else {
    return atoi( val.c_str() );
  }
}
