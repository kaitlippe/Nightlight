//Capacitive sensor
#include <CapacitiveSensor.h>
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);

// Set up LED display
int ledState;
int ledSpeed = 800; // Speed at which the LEDs animate.
byte maxBrightness = 255; 
byte ledsVal[] = {0, 0, 0, 0, 0, 0}; // The (starting) brightness value of all of the pins.
byte ledsDir[] = {0, 0, 0, 0, 0, 0};
int ledsMax[] = {1000, 1000, 1000, 1000, 1000, 1000};
int ledsMin[] = {0, 0, 0, 0, 0, 0};

// Variables for writing to the LEDs. You should not need to change these:
int leds[] = {3, 5, 6, 9, 10, 11};
int fadeSpeed = 5; 
int fadePreviousMillis;
int pinCount = 6;
int prevLedTime;
int ledsSwitch;

//UV light variables
int ledPin = 13;
int ledPin2 = 7;

// Variables for logic
int i; 
int prevTime; // a variable for the logic timing
int interval = 500; // length of time for logic time
int touched;
int stateVar;
int lightVar;

//light sensore variables
int darkVar;
int darkState;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    pinMode(leds[thisPin], OUTPUT);
  }
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  darkSense();
  touchSense();
  logic();
  updateLED();
}
