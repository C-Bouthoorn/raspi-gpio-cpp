# Compiler
CC=g++
# Compiler flags
CFLAGS=-Wall

all: GPIO-test
easy: EasyGPIO-test

clean:
	rm -f *.o *.gch GPIO-test EasyGPIO-test

# GPIO
remake: clean all
	
GPIO-test: GPIO.o
	$(CC) $(CFLAGS) -I . -o GPIO-test GPIO-test.cpp
	
GPIO.o:
	$(CC) $(CFLAGS) -c GPIO.hpp GPIO.cpp
	
# Easy GPIO
remake-easy: clean easy
EasyGPIO-test: EasyGPIO.o
	$(CC) $(CFLAGS) -I . -o EasyGPIO-test EasyGPIO-test.cpp
	
EasyGPIO.o: GPIO.o
	$(CC) $(CFLAGS) -c EasyGPIO.hpp EasyGPIO.cpp