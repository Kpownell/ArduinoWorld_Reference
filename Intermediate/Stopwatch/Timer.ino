/*****************************************************
    TIMER
    Use the LCD as a simple stopwatch. Pressing one 
    button will start the timer counting up from 0.
    The middle button will pause the timer until it is
    resumed by pressing the first button again. The
    last button resets the timer to 0.
    
    The LED will be on when the timer is counting and 
    off when it's paused or reset. The speaker buzzes
    whenever a button is pressed to start/stop.
    ***************************************************/

  #include <LiquidCrystal.h>
  #define NOTE_C4 262
  
  const int led = 10;
  const int buttonStart = 6;
  const int buttonStop = 7;
  const int buttonReset = 8;
  const int speakerPin = 9;
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  
  int timerOn = 0;
  unsigned long start, finished, elapsed, pause;
  
  void setup() {
    pinMode(led,OUTPUT);
    pinMode(speakerPin,OUTPUT);
    pinMode(buttonStart,INPUT);
    pinMode(buttonStop,INPUT);
    pinMode(buttonReset,INPUT);
    lcd.begin(16,2);
    start = millis();
    finished = millis();
  }
  
  //Code to break down time reading into 4 digits for LCD
  void displayResult() {
     float h, m, s, ms;
     int d3,d2,d1,d0;
     unsigned long over;
     
     // If timer is going, use raw millis for time;
     // if timer is paused, use stored stop point
     if(timerOn) elapsed = millis() - start;
     else elapsed = finished - start;
     
     // Convert milliseconds into min/sec
     h = int(elapsed / 3600000);
     over = elapsed % 3600000;
     m = int(over / 60000);
     over = over % 60000;
     s = int(over / 1000);
     
     // Display either hours or minutes
     if (h < 1) {
       d3 = (int)m%10;
       d2 = (int)m/10;
       d1 = (int)s/10;
       d0 = (int)s%10;
     } else {
       d3 = (int)h%10;
       d2 = (int)h/10;
       d1 = (int)m/10;
       d0 = (int)m%10;
     }
     
     //Store time as a string that can be printed to LCD
     String time = (String)d3 + (String)d2 + ":" + (String)d1 + (String)d0;
     lcd.setCursor(0,0);
     lcd.print(time);
  }
  
  //Determine if timer should be on, paused, or reset
  void loop() {
    int startPressed = digitalRead(buttonStart);
    int stopPressed = digitalRead(buttonStop);
    int resetPressed = digitalRead(buttonReset);
    
    if(resetPressed) {
      //For first starting out - clear everything
      digitalWrite(led, LOW);
      start = millis();
      finished = millis();
      timerOn = 0;
      delay(200);
    } else if(startPressed and !timerOn) {
      //Start the timer; store time when started
      digitalWrite(led, HIGH);
      if(start == finished)
        //If timer is starting from scratch
        start = millis();
      else
        //If timer is starting from pause
        start = start + (millis() - pause);
      timerOn = 1;
      tone(speakerPin, NOTE_C4, 100);
      delay(200); //for debounce
    } else if(stopPressed and timerOn) {
      //Pause the timer; store the current time elapsed and restart from there later
      digitalWrite(led, LOW);
      finished = millis();
      pause = millis();
      tone(speakerPin, NOTE_C4, 100);
      timerOn = 0;
      delay(200);
    }
    displayResult();
  }
    
