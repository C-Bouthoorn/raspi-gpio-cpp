#include <iostream>
#include <string>
#include <fstream>

#include "GPIO.hpp"

using namespace std;

// Default constructor: pin 4
GPIO::GPIO() {
  this->gpionum = "4";
  this->gpio_export();
}

// Custom constructor: pin `pin`
GPIO::GPIO(string pin) {
  this->gpionum = pin;
  this->gpio_export();
}

// When object gets destroyed: Unexport
GPIO::~GPIO() {
  this->gpio_unexport();
}

// Export GPIO pin
int GPIO::gpio_export() {
  string export_path = "/sys/class/gpio/export";
  
  // Open output file stream
  ofstream exportgpio( export_path.c_str() );
  if(exportgpio < 0) { // Error
    cerr << "Unable to export GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  
  // Write pin to stream
  exportgpio << this->gpionum;
  
  // Close stream
  exportgpio.close();
  
  return 0;
}

// Unexport GPIO pin
int GPIO::gpio_unexport() {
  string unexport_path = "/sys/class/gpio/unexport";
  
  // Open output file stream
  ofstream unexportgpio( unexport_path.c_str() );
  if(unexportgpio < 0) { // Error
    cerr << "Unable to unexport GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  
  // Write pin to stream
  unexportgpio << this->gpionum;
  
  // Close stream
  unexportgpio.close();
  
  return 0;
}

// Set direction of pin [in/out]
int GPIO::setdir(string dir) {
  string setdir_path = "/sys/class/gpio/gpio" + this->gpionum + "/direction";
  
  // Open output file stream
  ofstream setdirgpio( setdir_path.c_str() );
  if(setdirgpio < 0) { // Error
    cerr << "Unable to set direction of GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  
  // Write direction to stream
  setdirgpio << dir;
  
  // Close stream
  setdirgpio.close();
  return 0;
}

// Set value of pin [1/0] (on/off)
int GPIO::setval(string val) {
  string setval_path = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  
  // Open output file stream
  ofstream setvalgpio( setval_path.c_str() );
  if(setvalgpio < 0) { // Error
    cerr << "Unable to set the value of GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  
  // Write value to stream
  setvalgpio << val;
  
  // Close stream
  setvalgpio.close();
  return 0;
}

// Set value of pin to `val`
int GPIO::getval(string& val){
  string getval_path = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  
  // Open input file stream
  ifstream getvalgpio( getval_path.c_str() );
  if(getvalgpio < 0) { // Error
    cerr << "Unable to get value of GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  
  // Store pin value to `val`
  getvalgpio >> val;
  
  // If value isn't 0 or 1 (Some kind of error), set to 0
  if(val != "0" && val != "1") {
    val = "0";
  }
  
  // Close stream
  getvalgpio.close();
  return 0;
}

// Get current gpio pin
string GPIO::get_gpionum(){
  return this->gpionum;
}