/*****************************************************
    MOTION DETECTOR
    Use a photoresistor to detect motion. If something
    moves, set off an alarm and turn on an LED.
    ***************************************************/
    
    // Include constant note values
    #include "pitches.h"
    
    // Create variable to store pin numbers for sensors
    int speakerPin = 9;
    int ledPin = 10;
    int photoPin = A0;
    
    // Set threshold value to detect motion
    int threshold = 800;
    
    // Initalize variables
    void setup() {
      // Speaker and LED are output, photoresistor is input
      pinMode(speakerPin, OUTPUT);
      pinMode(ledPin, OUTPUT);
      pinMode(photoPin, INPUT);
    }
    
    // This method repeats continuously while Arduino is powered
    void loop() {
      // Find value from photoresistor
      int value = analogRead(photoPin);
      
      // If the value is high enough, motion is detected
      if(value > threshold) {
        // Turn on LED and speaker alarm
        digitalWrite(ledPin, HIGH);
        tone(speakerPin, NOTE_C5);
      }
      
      // Otherwise, no motion has been detected
      else {
        // Turn off LED and speaker
        digitalWrite(ledPin, LOW);
        noTone(speakerPin);
      }
    }
