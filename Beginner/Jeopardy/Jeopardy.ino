/*****************************************************
    JEOPARDY
    Create a buzzer system for a homemade jeopardy game.
    Two players have a chance to press their button.
    When one presses it, the corresponding light turns
    on and the Serial monitor will display which
    player pressed the button first.
    ***************************************************/
    
    // Create variable to store pin numbers for lights and buttons
    int ledPin1 = 10;
    int ledPin2 = 11;
    int buttonPin1 = 8;
    int buttonPin2 = 9;
    
    // Initalize variables
    void setup() {
      // We're going to be turning the LED on and off by controlling it
      // with the Arduino, so these pins are OUTPUT
      pinMode(ledPin1, OUTPUT);
      pinMode(ledPin2, OUTPUT);
      // We need to read the values from the buttons to know whether
      /// an outside user pressed them, so these pins are INPUT
      pinMode(buttonPin1, INPUT);
      pinMode(buttonPin2, INPUT);
      // Initalize the Serial port to print values to the screen
      Serial.begin(9600);  
    }
    
    // This method repeats continuously while Arduino is powered
    void loop() {
      // Read and store whether either button has been pressed
      int state1 = digitalRead(buttonPin1);
      int state2 = digitalRead(buttonPin2);
      
      // If the first button is pressed
      if(state1 == HIGH) {
        // Turn on the first LED and turn off the second one
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
        
        // Print the first-pressed button onscreen
        Serial.println("Button 1 pressed.");
        
        // Wait to avoid reading the button as pressed twice
        delay(200);
      } 
      
      // If the second button is pressed
      else if (state2 == HIGH) {
        // Turn the first LED off and the second on
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        
        // Print the user onscreen
        Serial.println("Button 2 pressed.");
        
        // Wait to avoid reading the button as pressed twice
        delay(200);
      } 
      
      // If neither button has been pressed
      else {
        // Turn off both LEDs
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
      }
    }
