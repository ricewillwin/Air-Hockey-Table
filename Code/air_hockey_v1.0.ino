/*
Air Hockey Table Firmware
Oct. 29, 2021
0.0.1

Goal of this verison is to get scoring working so 
that goals can be counted and that the score of each 
side can be displayed on a seven segment display.
*/

// #########################
// ###  Air Hockey Code  ###
// #########################

// Libraries
#include <Arduino.h>
#include <Servo.h>





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



// ###################
// ###  Main Loop  ###
// ###################
void loop() {
    
}





// ####################
// ###  Led Lights  ###
// ####################
class Lights {
  private:
    int pins[];           // Contains a list of all pins for the light strip
    int color[];          // Contains the current color of the LEDs in RGBa form
    int redPin = 0;       // Red Pin Reference
    int greenPin = 0;     // Green Pin Reference
    int bluePin = 1;      // Blue Pin Reference
    bool lightState;      // Boolean for state of the light strip

  public:
    // Creates the Light Object
    Lights(int pins[]) {
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


    // Set Color
    void setColor(int colors[]) {
      this->color = colors;
      sendColors(colors);
    }
  
  
    // Returns the state of the lights (on / off) as a boolean
    bool getState() {
      return (this->lightMode == HIGH);
    }
    

    // Returns the color of the lights as an integer array
    int[] getColor() {
      return this->color;
    }


    // Sends the Color to the Lights
    void sendColors(int colors[]) {
      analogWrite(this->pins[this->redPin], colors[0]);
      analogWrite(this->pins[this->greenPin], colors[1]);
      analogWrite(this->pins[this->bluePin], colors[2]);
    }

};





// ################
// ###  Sensor  ###
// ################
class Sensor {
  private:
    int pins[];
    bool goal;

  public:

  Sensor(int pins[]) {
    this->pins = pins;
    init();
  }

  void init() {
    for (i = 0; i < sizeOf(pins); i++) {
      pinMode(i, INPUT);
    }
  }

  bool 

}
