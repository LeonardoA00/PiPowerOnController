# PiPowerOnController
 Code that use RaspberryPi GPIO to power on a computer shorting the switch cables using an optocoupler

## Usage
Call the program with one argument representing the time holding the power button in seconds

    ./PowerOnController 0.5

Suggested push times are

-   `0.5s` normal startup
-   `7s` hard reset

## Bash Aliases
To launch the program directly from bash, use an alias.
Add this line in `~/.bashrc`

    alias pwron="sudo /home/pi/PiPowerOnController/PowerOnController 0.5"

## Compile
To compile use:

    gcc PowerOnController.c -o PowerOnController -lpigpio -lrt -Wall -pthread

PiGPIO Library is needed
Download it following the instructions at:

https://abyz.me.uk/rpi/pigpio/

Big thanks to the creator of the C library.
   
