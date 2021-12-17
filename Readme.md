This code is for demonstartion purpose only as used on my layout
This is a simple sketch that moves a lift up and down a various speeds, it has 4 leds that flash in a sequence to show which way it is going and it is triggered by a switch or a sensor to start the animation.

It is based on a arduino nano which sits on a sensor shield

The trigger sensor is on pin  A5 and returns to a GND pin

The four leds are connected to pins
led 1 pin A1, led 2 pin A2, led 3 pin A4, led 4 pin A3 and return to a GND pin each led has a builtin 220ohm resistor in my case.

The motor i use requires 2048 steps to make 1 revolution.

const int stepsPerRevolution = 2048;


There are 3 speeds that the stepper motor uses  Max speed is 15 for the stepper motor i use.

int speeda = 3;

int speedb = 5;

int speedc = 13; 

There are 8 different amount of movement the stepper motor uses in this sketch.

int stepa = -600;

int stepb = -300; 

int stepc = -7800;

int stepd = -250; 

int stepe = 600; 

int stepf = 300; 

int stepg = 7800; 

int steph = 250;

The important thing to watch for is the pins that connect the motor driver to the arduino

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

Pin 1 on the drive board goes to pin 8 on the arduino 

Pin 2 on the drive board goes to pin 10 on the arduino 

Pin 3 on the drive board goes to pin 9 on the arduino 

Pin 4 on the drive board goes to pin 11 on the arduino 

Void STEPPER_OFF()

This is used to turn off the power to the stepper motor once the move has been completed> This stops the stepper motorgetting hot while it waits for next move trigger event.

Void loop()

It waits for the sensor to trigger then goes through each of the steps called in sequence and only runs 1 time and then waits for the next trigger event. I use delay in this code as the arduino is only being used to control the lift. I may include sound effects in the near future and may need to amend the code to use millis().


