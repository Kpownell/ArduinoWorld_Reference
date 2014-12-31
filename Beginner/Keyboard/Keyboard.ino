/*****************************************************
    KEYBOARD
    Pressing buttons allows different notes to play and
    different-colored lights to light up.
    ***************************************************/
    
    // Include constant note values
    #include "pitches.h"
    
    // Create variable to store pin numbers for sensors
    int ledPin1 = 6;
    int ledPin2 = 7;
    int ledPin3 = 8;
    
    int buttonPin1 = 10;
    int buttonPin2 = 11;
    int buttonPin3 = 12;
    
    int speakerPin = 9;
    
    //Store notes for keyboard
    int notes[] = {NOTE_C4, NOTE_E4, NOTE_G4};

    // Initalize variables
    void setup() {
      // Lights and speaker are output
      pinMode(ledPin1, OUTPUT);
      pinMode(ledPin2, OUTPUT);
      pinMode(ledPin3, OUTPUT);
      pinMode(speakerPin, OUTPUT);
      
      // Buttons are input
      pinMode(buttonPin1, INPUT);
      pinMode(buttonPin2, INPUT);
      pinMode(buttonPin3, INPUT);
    }
    
    // This method repeats continuously while Arduino is powered
    void loop() {
      // Check if any button has been pressed
      int state1 = digitalRead(buttonPin1);
      int state2 = digitalRead(buttonPin2);
      int state3 = digitalRead(buttonPin3);
      
      // First button pressed
      if(state1 == HIGH) {
        // Turn on first light and turn other lights off
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        
        // Play first note on speaker
        tone(speakerPin, notes[0]);
      } 
      
      // Second button pressed
      else if(state2 == HIGH) {
        // Turn on second light and turn other lights off
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, LOW);
        
        // Play second note on speaker
        tone(speakerPin, notes[1]);
      } 
      
      // Third button pressed
      else if(state3 == HIGH) {
        // Turn on third light and turn other lights off
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW):
        digitalWrite(ledPin3, HIGH);
        
        // Play third note on speaker
        tone(speakerPin, notes[2]);
      } 
      
      // No buttons pressed
      else {
        // Turn off all lights
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        
        // Silence speaker
        noTone(speakerPin);
      } 
    }
