/*****************************************************
    SPINNER
    Spin a DC motor. Toggle the state of on/off with
    a switch.
    ***************************************************/
    
    // Store pins for components and a boolean to tell
    // whether motor is running or paused
    int buttonPin = 11;
    int motorPin = 9;
    int running = 0;
    
    // Set up input/output
    void setup() {
      pinMode(motorPin, OUTPUT);
      pinMode(buttonPin, INPUT);
    }
    
    void loop() {
      int buttonPressed = digitalRead(buttonPin);
      // If button is pressed, change state
      if(buttonPressed) {
        // Switch from on->off or off->on
        running = !running;
        // Debounce button
        delay(300);
      }
      // Run motor at medium speed
      // If motor is off, this command will do nothing
      analogWrite(motorPin, 150*running);
    }
