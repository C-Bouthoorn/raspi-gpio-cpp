#include <iostream>
#include <string>
#include <stdlib.h>

#include "EasyGPIO.cpp"

using namespace std;

int main() {
  // Open pins 4 and 17
  EasyGPIO* gpio4  = new EasyGPIO("4");
  EasyGPIO* gpio17 = new EasyGPIO("17");

  // Set pin 4 to output
  gpio4->start("out");
  gpio4->start("in");

  // Get value from pin 17
  string gpio17_val;
  gpio17->getval(gpio17_val);

  // Debug value
  cout << "Current input pin state is " << gpio17_val  <<endl;

  // Turn pin 4 on
  gpio4->setval("1");

  // While the button is being pressed
  while(gpio17_val == "1") {
    // Recheck value
    gpio17->getval( gpio17_val );
  }

  // Turn pin 4 off
  gpio4->setval("0");

  // Remove objects (Free memory)
  // Yes, it's C++, we need to do weird things. Deal with it ._.
  free(gpio4);
  gpio4=NULL;

  free(gpio17);
  gpio17=NULL;

  // Exit program
  return 0;
}
