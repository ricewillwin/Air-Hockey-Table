/*
Air Hockey Table Firmware
Oct. 29, 2021
0.0.1

Goal of this verison is to get scoring working so 
that goals can be counted and that the score of each 
side can be displayed on a seven segment display.
*/


// Variables
int blueGoalSensor = 7;
int redGoalSensor = 8;

int perimeterLedsPins[] = {9,10,11};

void setup() {
    
    pinMode(blueGoalSensor, INPUT);
    pinMode(redGoalSensor, INPUT);
    
    for(int pin = 0; pin < perimeterLedsPins; pin++) {
      pinMode(pin, OUTPUT);
    }
    
}

void loop() {
    
}
