/*****************************************************
    RANDOM DRAWING ROBOT
    Use servo motors and the random library to create
    a simple robot that draws random strokes at the
    touch of a button.
    ***************************************************/
    
    #include <Servo.h>
    
    int buttonPin = 7;
    int servoPin = 10;
    
    // Declare your servo
    Servo myServo;
    // Keep track of robot state
    int robotOn = 0;
    
    void setup() {
      pinMode(buttonPin, INPUT);
      pinMode(servoPin, OUTPUT);
      // Initalize servo for pin 10
      myServo.attach(10);
      // Initialize random number generator
      randomSeed(analogRead(0));
    }
    
    void loop() {
      // Change robot state if button pressed
      if(digitalRead(buttonPin)) {
        robotOn = !robotOn;
        delay(200);
       }
       
       // If robot is running, write a random value
       if(robotOn) {
         // Generate a random number between 30 and 120
         int randNum = random(30,120);
         // Rotate the servo to our random number of degrees
         myServo.write(randNum);
         // Generate a random number for delay between strokes
         int randDelay = random(100,500);
         delay(randDelay);
      }
    }
       

      
      
