
/*
60 LED Neopixel  Lightt Strip Test 

Link to a demo of the Nepixel Light Strip:

Discription of our projec.
This will help you test your strip if it works properly. 
Be advice what you see here will be on our actual coding.
Also, through out the test you will see Green Red Blue instead 
of Red Green Blue. That is normal because the Ardunio changes 
the order in Red Green Blue to Green Red Blue. 

The circuit:
 *RGB 60 LED light ground pin to Arduino Anolog GND
 *RGB 60 LED light power pin to Arduino Anolog 5v
 *RGB 60 LED light pin connector to Arduino digital pin 6
 *RGB 60 LED external(RED) power cable to power adaptor 5v port
 *RGB 60 LED external(WHITE) GND cable to power adaptor GND port

*/

// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <FastLED.h>

//RGB 60 led strip. This will help to determine the different pattern location.
#define wave_pin 6
#define wave_count 60
#define color__combination GRB
#define chip WS2812B
#define Bright 200
#define Frames_per_second 60

CRGB leds[wave_count];// used to turn on a random lights 

// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//this will help change the led lights to different color pallete/pattern
CRGBPalette16 gPal;

void setup() {
   // set up the LCD's number of columns and rows and input:
  lcd.begin(16, 2);

 // setting up the random colors for Disco pattern
  delay(3000); // sanity delay
  FastLED.addLeds<chip, wave_pin, color__combination>(leds, wave_count).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( Bright );
  gPal = HeatColors_p;

    //setting up the coloration for wave pattern and circular pattern
  FastLED.addLeds<NEOPIXEL, wave_pin>(leds, wave_count);

  // All outputs will be setup..
  Serial.begin(9600);
 
  // Print a message that introduces the group(optional).
  lcd.print("Welcome to the led strip test.");
  Serial.print("Welcome to the led strip test.");
  
}

void loop() {

  //You may select to turn on either DiscoWave() to test the entire strip or part of a strip by selecting only WaveCycle() and/or CircularWave().
  //WaveCycle();
  //CircularWave();
  DiscoWave();
  
  delay(1000);//delay can be modified

}

//Strip activiation functions:
//In the even we decide to use only the RGB 60 LED lights we must use these three functions.
//Spliting the RGB 60 LED lights into two groups.
// code is part of Mark Kriegsman Multiple controller examples. 

//the Mirroring method has been used in both the WaveCycle2() and CircularWave2().
//second attempts
void WaveCycle2(){
  //this for loop will head from left to right.
  for(int i = 0; i < 30; i++) {
    // set our current dot to red
    leds[i] = CRGB((153+i),(255-i),(51+i));
    FastLED.show();
    // clear our current dot before we move on
    leds[i] = CRGB::Black;
    delay(1000);
  }
  //this for loop will head from right to left.
  for(int i = 29; i > -1; i++) {
    // set our current dot to red
    leds[i] = CRGB((153+i),(255-i),(51+i));
    FastLED.show();
    // clear our current dot before we move on
    leds[i] = CRGB::Black;
    delay(1000);
  }
}

  //second attempts of the Circular wave 
  void CircularWave2(){
    //this will start from led 31 and end at led 60.
    for(int i = 30; i < 60; i = i + 5) {
    // set our current dot to red
    leds[i] = CRGB((153+i),(255-i),(51+i));
    leds[5+i] = CRGB((153+i),(255-i),(51+i));
    leds[10+i] = CRGB((153+i),(255-i),(51+i));
    leds[15+i] = CRGB((153+i),(255-i),(51+i));
    leds[20+i] = CRGB((153+i),(255-i),(51+i));
    FastLED.show();
    // clear our current dot before we move on
    leds[i] = CRGB::Black;
    leds[5+i] = CRGB::Black;
    leds[10+i] = CRGB::Black;
    leds[15+i] = CRGB::Black;
    leds[20+i] = CRGB::Black;
    delay(1000);
    }

    //this will start from led 31 and end at led 60.
    for(int i = 59; i >29; i = i - 5) {
    // set a group of 5 current leds to a random color. 
    leds[i] = CRGB((153+i),(255-i),(51+i));
    leds[i-5] = CRGB((153+i),(255-i),(51+i));
    leds[i-10] = CRGB((153+i),(255-i),(51+i));
    leds[i-15] = CRGB((153+i),(255-i),(51+i));
    leds[i-20] = CRGB((153+i),(255-i),(51+i));
    FastLED.show();
    // clear our current leds before we move on
    leds[i] = CRGB::Black;
    leds[i-5] = CRGB::Black;
    leds[i-10] = CRGB::Black;
    leds[i-15] = CRGB::Black;
    leds[i-20] = CRGB::Black;
    delay(1000);
    }
  }

  // for DisoWave()we will be using the same method as the other two with a while loop instead.
  void DiscoWave2(){
    
    int i = 0;
    int p = 153;
    int j = 255;
    int q = 51;

    
    //this while loop will change the color per iteration.
    while (i < 60){
      
      p = p + i;
      j = j - i;
      q = q + i;
       
    //using the for loop to light up and turn of all 60 led lights.
      for(int t = 0; t < 60; t++) {
      // set each light to the smame pattern
        leds[t] = CRGB(p,j,q);
      } 
      FastLED.show();
      //this for loop will turn all the lights off.
       for(int t = 0; t < 60; t++) {
      // set each light to the smame pattern
        leds[t] = CRGB::Black;
      }  
      i++;
      delay(1000);
    }
  } 
// --------------------------------------------------------------------------------------------
