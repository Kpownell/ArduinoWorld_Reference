/*****************************************************
    DIM THE LIGHTS
    Use a photoresistor to read the amount of light
    outside. If the light is high, lower the brightness
    of the RGB LED; if the light is low, raise the
    brightness.
    ***************************************************/
    
    // Create variable to store pin numbers for lights and buttons
    // Since photoresistor is analog, the pin is A0 instead of just 0
    int photoPin = A0;
    int ledPin1 = 9;
    int ledPin2 = 10;
    int ledPin3 = 11;
    
    // Initalize variables
    void setup() {
      // LED pins are turning on/off so they're OUTPUT
      pinMode(ledPin1, OUTPUT);
      pinMode(ledPin2, OUTPUT);
      pinMode(ledPin3, OUTPUT);
      
      // We're reading the photoresistor value so it's INPUT
      pinMode(photoPin, INPUT);
    }
    
    // This method repeats continuously while Arduino is powered
    void loop() {
      // Use analogRead to find the amount of light as an integer
      // between 512 and 1023
      int photoValue = analogRead(photoPin);
      
      // Use the map method to convert our read value into something
      // we can output to the LED - something between 0-255
      int newValue = map(photoValue, 512, 1023, 0, 255);
      
      // Write the corresponding light value to the LED
      // to control the brightness
      analogWrite(ledPin1, newValue);
      analogWrite(ledPin2, newValue);
      analogWrite(ledPin3, newValue);
    }
