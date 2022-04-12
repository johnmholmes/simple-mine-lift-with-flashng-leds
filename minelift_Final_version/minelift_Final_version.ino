#include <Stepper.h>

const int stepsPerRevolution = 2048;

#define SENSOR1_PIN          A5         // push button on pin A5
#define LED_PIN1             A1         // Led on pin A1 resistor 220ohms used for each led
#define LED_PIN2             A2         // Led on pin A2 
#define LED_PIN3             A4         // Led on pin A3
#define LED_PIN4             A3         // Led on pin A4
#define LIGHT_DELAY          1500       // This has a value of 1.5 second delay
#define FLASH_DELAY          1000       // This has a value of 1 second delay  
#define LIFT_DELAY           60000      // This has a value of 1 minute delay

int speeda = 3;                         // The speed range for this stepper motor is between 1 and 13 I have found
int speedb = 5;
int speedc = 13;
int stepa = -600;                       // The number of steps I need the stepper motor to run there are 4 speeds use in each movement
int stepb = -300;
int stepc = -7800;
int stepd = -250;
int stepe = 600;
int stepf = 300;
int stepg = 7800;
int steph = 250;


Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);   // steps for full rev 2048 and the pin sequence is 8 10 9 11

void setup() {
  pinMode(SENSOR1_PIN, INPUT_PULLUP);     // Setup the sensor pin as an input and uses the pull up resistor to hold the pin high
  pinMode(LED_PIN1, OUTPUT);              // All the leds get setup as outputs
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
}
// There a 8 functions iI use to control the lift movements and LED flashing I can use delay here in this code as the is no interupts
// Which would have nedd me to use the Millis function in stead making it more complicated.

// This function turns all the LEDs on when it is called
void LIGHTS_ON() {
  digitalWrite(LED_PIN1, HIGH);          
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, HIGH);
}

// This function turns all the LEDS off when it is called
void LIGHTS_OFF() {
  digitalWrite(LED_PIN1, LOW);           
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW);
}

// This function is used to flash all 4 LEDS on and off with a 1 second delay
void FLASH() {
  digitalWrite(LED_PIN1, HIGH);          
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, HIGH);
  delay(1000);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW);
  delay(1000);
  
}

// This function sets the LEDS to flash in a sequence starting from the top
void DOWN_FLASH(){
  digitalWrite(LED_PIN2, HIGH);         // Top Led in my case  
  delay(500);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, HIGH);         // 2nd LED from the top
  delay(500);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN1, HIGH);         // 3rd LED from the top
  delay(500);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN4, HIGH);         // Bottom Led in my case
  delay(500);
  digitalWrite(LED_PIN4, LOW);
  delay(500);
  digitalWrite(LED_PIN2, HIGH);
  delay(500);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, HIGH);
  delay(500);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN1, HIGH);
  delay(500);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN4, HIGH);
  delay(500);
  digitalWrite(LED_PIN4, LOW);
  delay(1000);
}

// This function start the LEDS to flash in a sequence from the bottom up
void UP_FLASH(){
  digitalWrite(LED_PIN4, HIGH);       
  delay(500);
  digitalWrite(LED_PIN4, LOW);
  digitalWrite(LED_PIN1, HIGH);
  delay(500);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN3, HIGH);
  delay(500);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN2, HIGH);
  delay(500);
  digitalWrite(LED_PIN2, LOW);
  delay(500);
  digitalWrite(LED_PIN4, HIGH);
  delay(500);
  digitalWrite(LED_PIN4, LOW);
  digitalWrite(LED_PIN1, HIGH);
  delay(500);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN3, HIGH);
  delay(500);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN2, HIGH);
  delay(500);
  digitalWrite(LED_PIN2, LOW);
  delay(1000);
}

// This function turns off the stepper motors when not in motion
void STEPPER_OFF(){
  digitalWrite(8, LOW);                         
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

// This function send the lift downwards for the retun starting slowly
// Moves so many steps befor speeding up 
void LIFT_DOWN() {
  myStepper.setSpeed(speeda);                   
  myStepper.step(stepe);                                           
  myStepper.setSpeed(speedb);
  myStepper.step(steph);
  myStepper.setSpeed(speedc);                   // Lift at its fasted speed
  myStepper.step(stepg);
  myStepper.setSpeed(speedb);                   // Lift starts to slow down
  myStepper.step(stepf);
  myStepper.setSpeed(speeda);
  myStepper.step(stepe);                        // Lift reaches the bottom and stops
  delay(1000); 
}

// This is the reverse of the downward travel so not explained
void LIFT_UP() {
  myStepper.setSpeed(speeda);                  
  myStepper.step(stepa);
  myStepper.setSpeed(speedb);//max 15
  myStepper.step(stepb);
  myStepper.setSpeed(speedc);//max 15
  myStepper.step(stepc);
  myStepper.setSpeed(speedb);//max 15
  myStepper.step(stepd);
  myStepper.setSpeed(speeda);//max 15
  myStepper.step(stepa);
  delay(1000);
}
// start of the void loop which will run for ever while the Arduino has power its just a case of one fuction call after another 
// With a delay in between each function call
void loop() {
  if(digitalRead(SENSOR1_PIN) == LOW){          // Waiting for the sensor or button to be activated
    LIGHTS_ON();                                // Calls the relvent function and once that function is complete it will move to the next line 
    delay(500);
    LIGHTS_OFF();
    delay(500);
    LIGHTS_ON();
    delay(1000);
    LIGHTS_OFF();
    delay(1000);
    UP_FLASH();
    delay(500);
    LIGHTS_ON();
    delay(LIGHT_DELAY);
    LIFT_UP();
    delay(LIGHT_DELAY);
    STEPPER_OFF();
    LIGHTS_OFF();
    delay(LIFT_DELAY);
    
  // Lift delayed at the top for 60 seconds before going back down
    
    LIGHTS_ON();
    delay(500);
    LIGHTS_OFF();
    delay(500);
    LIGHTS_ON();
    delay(1000);
    LIGHTS_OFF();
    delay(1000);
    DOWN_FLASH();
    delay(1000);
    LIGHTS_ON();
    delay(LIGHT_DELAY);
    LIFT_DOWN();
    delay(LIGHT_DELAY);
    STEPPER_OFF();
    LIGHTS_OFF();

  }
 }
