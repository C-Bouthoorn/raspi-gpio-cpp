#include <iostream>
#include <string>
#include <stdlib.h>

#include "EasyGPIO.cpp"

using namespace std;

int main() {
  // Open pins 4 and 17
  EasyGPIO* gpio4  = new EasyGPIO( "4",  EasyGPIO::OUT );
  EasyGPIO* gpio17 = new EasyGPIO( "17", EasyGPIO::IN  );

  // Get value from pin 17
  int gpio17_val = gpio17->get();

  // Debug value
  cout << "Current input pin state is " << gpio17_val  <<endl;

  // Turn pin 4 on
  gpio4->on();

  // While the button is being pressed
  while ( gpio17->get() == 1 ) {
    // ...
  }

  // Turn pin 4 off
  gpio4->off();

  // Remove objects (Free memory)
  // Yes, it's C++, we need to do weird things. Deal with it ._.
  delete gpio4;
  delete gpio17;

  // Exit program
  return 0;
}
