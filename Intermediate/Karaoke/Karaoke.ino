/*****************************************************
    KARAOKE
    Display lyrics and pitches on the LCD screen
    while playing a short melody on a speaker.
    ***************************************************/
    
    // Import libraries for LCD and header file with defined pitches
    #include <LiquidCrystal.h>
    #include "pitches.h"
    
    // Setup LCD, speaker, and button
    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
    int speakerPin = 9; 
    int buttonPin = 8;
    
    // Setup song
    // Lyrics for top line of LCD, note names for underneath, pitches for speaker
    String words[] = {"Twinkle, Twinkle","Little Star","How I Wonder","What You Are"};
    String notes[] = {"C   C    G   G  ","A  A   G   ","F   F E  E  ","D    D   C  "};
    int pitches[] = {NOTE_C3, NOTE_C3, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_G3, 0, 
                    NOTE_F3, NOTE_F3, NOTE_E3, NOTE_E3, NOTE_D3, NOTE_D3, NOTE_C3, 0};  
                    
   void setup() {
      lcd.begin(16,2);
      pinMode(buttonPin, INPUT);
    }
                    
    void loop () {
      // If button is pressed, start song
      if(digitalRead(buttonPin) == HIGH) {
        // Scroll through entire song (4 entires in LCD arrays)
        for(int i = 0; i < 4; i++) {
          // Print words on top line
          lcd.setCursor(0,0);
          lcd.print(words[i]);
          // Print note names underneath
          lcd.setCursor(0,1);
          lcd.print(notes[i]);
          
          //Each line = 4 notes; loop through notes
          for(int j = 0; j < 4; j++) {
            // If pitch is 0 (silence), don't play
            if(pitches[i*4+j] == 0) noTone(speakerPin);
            // Otherwise, play note
            else tone(speakerPin, pitches[i*4+j],250);
            // Wait for note to play
            delay(500);
          }
          // Clear display
          lcd.clear();
        }
      }
    }
