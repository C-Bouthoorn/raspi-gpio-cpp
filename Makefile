# Compiler
CXX=g++
# Compiler flags
CPPFLAGS=-Wall

all: GPIO EasyGPIO
clean-all: clean clean-easy
remake-all: clean-all all

### GPIO
# Removing / Rebuilding
remake: clean all
clean: clean-test
	rm -f GPIO.o GPIO.hpp.gch
clean-test:
	rm -f GPIO-test

# Building GPIO
GPIO: GPIO.o GPIO.hpp.gch
	
# Building test [D: GPIO]
GPIO-test: GPIO-test.cpp   GPIO
	$(CXX) $(CPPFLAGS) -I . -o GPIO-test GPIO-test.cpp
	
GPIO.o: GPIO.cpp
GPIO.hpp.gch: GPIO.hpp
	$(CXX) $(CPPFLAGS) -c GPIO.hpp

### Easy GPIO
# Removing / Rebuilding
remake-easy: clean-easy easy
clean-easy: clean-easy-test
	rm -f EasyGPIO.o EasyGPIO.hpp.gch 
clean-easy-test:
	rm -f EasyGPIO-test

# Building EasyGPIO
EasyGPIO: EasyGPIO.o EasyGPIO.hpp.gch
	
# Building easy-test [D: EasyGPIO]
EasyGPIO-test: EasyGPIO-test.cpp   EasyGPIO
	$(CXX) $(CPPFLAGS) -I . -o EasyGPIO-test EasyGPIO-test.cpp
	
EasyGPIO.o: EasyGPIO.cpp   GPIO.o
EasyGPIO.hpp.gch: EasyGPIO.hpp   GPIO.hpp.gch
	$(CXX) $(CPPFLAGS) -c EasyGPIO.hpp