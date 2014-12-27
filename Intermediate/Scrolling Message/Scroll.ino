/*****************************************************
    SCROLLING MESSAGE
    Use the LCD display to scroll a message across the
    screen. Modified version of Scroll example from
    Arduino LiquidCrystal library.
    ***************************************************/
    
    #include <LiquidCrystal.h>
    
    //Setup LCD with correct pin numbers
    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
    String myString = "Hello, world!!!"
    
    void setup() {
      //Setup LCD with 16 cols, 2 rows
      lcd.begin(16, 2);
      lcd.print(myString);
      delay(1000);
    }
    
    void loop() {
      // Number of positions to scroll:
      // 16 cols + length of string to print
      int numPos = 16 + myString.length();
      
      //Scroll string across display
      for(int count = 0; count < numPos; count++) {
        lcd.scrollDisplayLeft();
        delay(150);
      }
    }
