/*****************************************************
    BLINK
    Turn an LED on and off every half-second.
    ***************************************************/
    
    // Create variable to store pin number for LED output
    int ledPin = 10;
    
    // Initalize variables
    void setup() {
      pinMode(ledPin, OUTPUT);
    }
    
    // This method repeats continuously while Arduino is powered
    void loop() {
      // Turn on LED
      digitalWrite(ledPin, HIGH);
      // Wait half a second
      delay(500);
      // Turn off LED
      digitalWrite(ledPin, LOW);
      // Wait another half-second
      delay(500);
    }
