  /*****************************************************
    MOOD LIGHTING
    This sketch reads in a temperature value
    from a TMP36 sensor and uses it to set the
    color of an RGB LED. The LED only responds to
    a range of temperatures from about 12-34 C
    (~54-93 F). Every 2 C (~3.6 F) temp change will
    shift the mood light to a new color.
    ***************************************************/
  
  // Initialize pins for temperature sensor and RBG LED
  int tempPin = A0;
  int r = 9;
  int g = 10;
  int b = 11;
  
  // Set colors for mood light to cycle through
  // Color index:{0   1   2   3   4   5   6   7   8   9   10  11 };
  int rRange[] = {255,255,127,0,  0,  0,  0,  0,  127,255,255,255};
  int bRange[] = {0,  0,  0,  0,  127,255,255,255,255,255,127,0  };
  int gRange[] = {127,255,255,255,255,255,127,0,  0,  0,  0,  0  };
  
  void setup() {
    Serial.begin(9600);
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
  }    
  
  void loop() {
    int val = analogRead(tempPin);
    float milliVolts = val*5000.0/1024.0;
    int color = (int)milliVolts;
    
    // 720 mV = 22 C, 72 F (approx room temp)
    // Operating range: 12-34 C (~54-93 F)
    // +1 C = + 1.8 F = +10 mV
    // If we change color every 20 mV, we need
    // to use the range from 620-840 mV
    if(color < 620) color = 620;
    else if (color > 840) color = 840;
    // Convert color into an index for RGB array
    color = (color-620)/20;
  
    analogWrite(r,rRange[color]);
    analogWrite(g,gRange[color]);
    analogWrite(b,bRange[color]);
    
    // Convert voltage reading to temperature
    // Reading will give a value b/n 0 and 1023
    // 0.5V = 25 C; each 0.1V = 1 C
    float volts = milliVolts/1000.0;
    float tempC = (volts-0.5) * 100;
    float tempF = tempC * 1.8 + 32;
    // Print out temp in Fahrenheit
    Serial.println(tempF);
    delay(500);
  }

