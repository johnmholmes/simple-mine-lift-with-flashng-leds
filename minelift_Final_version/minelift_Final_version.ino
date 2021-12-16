#include <Stepper.h>

const int stepsPerRevolution = 2048;

#define SENSOR1_PIN          A5         // push button
#define LED_PIN1             A1
#define LED_PIN2             A2
#define LED_PIN3             A4
#define LED_PIN4             A3
#define LIGHT_DELAY          1500
#define FLASH_DELAY          1000
#define LIFT_DELAY           60000

int speeda = 3;
int speedb = 5;
int speedc = 13;
int stepa = -600;
int stepb = -300;
int stepc = -7800;
int stepd = -250;
int stepe = 600;
int stepf = 300;
int stepg = 7800;
int steph = 250;


Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(SENSOR1_PIN, INPUT_PULLUP);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
}

void LIGHTS_ON() {
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN4, HIGH);
}

void LIGHTS_OFF() {
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  digitalWrite(LED_PIN4, LOW);
}

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
void DOWN_FLASH(){
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


void STEPPER_OFF(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void LIFT_DOWN() {
  myStepper.setSpeed(speeda);//max 15 takes about 33 seconds to lower
  myStepper.step(stepe);
  myStepper.setSpeed(speedb);//max 15
  myStepper.step(steph);
  myStepper.setSpeed(speedc);//max 15
  myStepper.step(stepg);
  myStepper.setSpeed(speedb);//max 15
  myStepper.step(stepf);
  myStepper.setSpeed(speeda);//max 15
  myStepper.step(stepe);
  delay(1000); 
}

void LIFT_UP() {
  myStepper.setSpeed(speeda);//max 15 takes about 33 seconds to raise
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

void loop() {
  if(digitalRead(SENSOR1_PIN) == LOW){
    LIGHTS_ON();
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
