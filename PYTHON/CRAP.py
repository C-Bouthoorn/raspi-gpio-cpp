# STUPID IMPORTS
import RPi.GPIO as GPIO
import time
import random

# I DON'T EVEN KNOW WHAT THIS DOES
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False) # STUPID PYTHON NOTATION

# STUPID PYTHON TYPES
led = 4
right_button = 15
left_button = 14

# STUPID THINGS
GPIO.setup(led, GPIO.OUT)

# MORE STUPID THINGS
GPIO.setup(right_button, GPIO.IN, GPIO.PUD_UP)
GPIO.setup(left_button, GPIO.IN, GPIO.PUD_UP)

# FINALLY SOME NORMAL CODE
GPIO.output(led, 1)

# STUPID PYTHON FUNCTIONS WITH WEIRD NAMES
time.sleep(random.uniform(5, 10))

# AGAIN NORMAL CODE, THANKS
GPIO.output(led, 0)

# STUPID PYTHON FORMATTING
while True:
    # OH LORD
    if GPIO.input(left_button) == False:
        # PLEASE
        print("Left button pressed")
        break
    # KILL
    if GPIO.input(right_button) == False:
        print("Right button pressed")
        # ME
        break
# WHO INVENTED THIS NOTATION ?!

# MORE PYTHON CRAP
GPIO.cleanup()

# FINALLY!! PYTHON CODE IS OVER!! BYE GUYS