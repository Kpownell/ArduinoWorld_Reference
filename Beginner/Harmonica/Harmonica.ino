/*****************************************************
    HARMONICA
    Vary the pitch output on a speaker using a
    potentiometer.
    ***************************************************/
    
    // Include constant note values
    #include "pitches.h"
    
    // Create variable to store pin numbers for speaker and potentiometer
    int speakerPin = 9;
    int potPin = A0;
    
    // Store the eight notes we want to play on our speaker
    int notes[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
    
    // Initalize variables
    void setup() {
      // Speaker is output, potentiometer is input
      pinMode(speakerPin, OUTPUT);
      pinMode(potPin, INPUT);
    }
    
    // This method repeats continuously while Arduino is powered
    void loop() {
      // Read potentiometer value
      int potValue = analogRead(potPin);
      
      // Change potentiometer reading into index value for notes array
      int newValue = map(potValue, 512, 1023, 0, 7);
      
      // Use read value to play corresponding note on speaker
      tone(speakerPin, notes[newValue]);
    }
