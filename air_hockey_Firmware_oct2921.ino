/*
Air Hockey Table Firmware
Oct. 29, 2021
0.0.1

Goal of this verison is to get scoring working so 
that goals can be counted and that the score of each 
side can be displayed on a seven segment display.
*/

// #########################
// ###  FUN WITH HOCKET  ###
// #########################

// Libraries
#include <Arduino.h>

// Variables
int blueGoalSensor = 7;
int redGoalSensor = 8;
int ledPins[] = {9, 10, 11};

// ###################
// ###  Main Code  ###
// ###################
void setup() {
    
    pinMode(blueGoalSensor, INPUT);
    pinMode(redGoalSensor, INPUT);

    Lights ledStrip(ledPins);

    
}

void loop() {
    
}





// ####################
// ###  Led Lights  ###
// ####################
class Lights {
  private:
    int pins[];           // Contains a list of all pins for the light strip
    bool lightState;      // Boolean for state of the light strip

  public:
    // Creates the Light Object
    Lights(byte pins[]) {
      this->pins = pins;
      lightState = false;
      init();
    }
  
  
    // Initialises the Light Strip
    void init() {
      for (i = 0; i < sizeOf(pins); i++) {
        pinMode(i, INPUT);
      }
    }
  
  
    // Returns the state of the lights (on / off) as a boolean
    // on   ->  true
    // off  ->  false
    bool getState() {
      return (lightMode == HIGH);
    }
};
