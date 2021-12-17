#This code is for demonstartion purpose only as used on my layout
This is a simple sketch that moves a lift up and down a various speeds, it has 4 leds that flash in a sequence to show which way it is going and it is triggered by a switch or a sensor to start the animation.

It is based on a arduino nano which sits on asensor shield

The trigger sensor is on pin  A5 and returns to a GND pin

The four leds are connected to pins
led 1 pin A1, led 2 pin A2, led 3 pin A4, led 4 pin A3 and return to a GND pin each led has a builtin 220ohm resistor in my case.


There are 3 speeds that the stepper motor uses int speeda = 3;, int speedb = 5;, int speedc = 13;, Max speed is 15 for the stepper motor i use.


