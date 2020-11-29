
/*
60 LED Neopixel  Lightt Strip Test 

Link to a demo of the Nepixel Light Strip:

Discription of our projec.
This will help you test if the strip is working properly. 
Be advice what you see here will be on our actual coding.
Also, thought out the test you will see Green Red Blue instead 
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
 CircularWave();
  //DiscoWave();
  
  delay(1000);//delay can be modified

}

//Strip activiation functions:
//Spliting the RGB 60 LED lights into two groups.
// code is part of Mark Kriegsman Multiple controller examples found 
// in the FastLed library made by Daniel Garcia. 
//the Mirroring method has been used in both the WaveCycle2() and CircularWave2().

//This function will test the first 30 neopixal lights in a wave pattern.
void WaveCycle(){

  int j = 153;//Alters Green
  int p = 255;//Alters Red
  int q = 51;// Alter Blue
  int i = 0; //Random color selection

  
  //This while loop will help in altering the color per each led light on the strip.  
  while(i < 254){
      p = p + i;
      j = j - i;
      q = q + i;
      
      //testing each variable to make sure they are not out of bounce.If they are we will rest them to default.
      if (i > 254){
        i = 0;
        } 
      if (j < 0 ){
        j = 255;
        }
     if (q > 254){
        q = 0;
       }
    if (p > 254){
        p = 0;
        }
    
    //this for loop is foward.
    for(int t = 0; t < 30; t++) {
     // setting up our current led light
      i++;
      p = p + i;
      j = j - i;
      q = q + i;
      
      leds[t] = CRGB((p),(j),(q));
      FastLED.show();
      // clear our current dot before we move on
      leds[t] = CRGB::Black;
      delay(1000);
    }
    
    //this for loop is to go backward. 
      for(int t = 29; t > -1; t = t - 1) {
      // setting our current led light.         
      i++;
      p = p + i;
      j = j - i;
      q = q + i;
      
      leds[t] = CRGB((p),(j),(q));
      FastLED.show();
      // clear our current dot before we move on
      leds[t] = CRGB::Black;
      delay(1000);
    }
      
  }
}

  //This function will assist to test the  last 30 neopixal lights
  //The two  for loops will help in turning on 5 lights at one time.
  //Look closely at leds because it increase/decrease from 5. 
  //This means every fifth light will be the same color.
  //in a circular pattern. 
  void CircularWave(){
  int j = 153;//Alters Green
  int p = 255;//Alters Red
  int q = 51;// Alter Blue
  int i = 0; //Random color selection

  
  //This while loop will help in altering the color per each led light on the strip.  
  while(i < 254){
      p = p + i;
      j = j - i;
      q = q + i;
      
      //testing each variable to make sure they are not out of bounce.If they are we will rest them to default.
      if (i > 254){
        i = 0;
        } 
      if (j < 0 ){
        j = 255;
        }
     if (q > 254){
        q = 0;
       }
    if (p > 254){
        p = 0;
        }
    
    //this for loop is foward.
    for(int t = 30; t < 60; t++) {
     // setting up our current led light
      i++;
      p = p + i;
      j = j - i;
      q = q + i;  
      leds[t] = CRGB((p),(j),(q));
      FastLED.show();
      delay(100);
    }
    //this for loop is foward.
    for(int t = 30; t < 60; t++) {
     // setting up our current led light
      leds[t] = CRGB::Black;
      FastLED.show();
      
    }
    
    //this for loop is to go backward. 
      for(int t = 59; t > 29; t = t - 1) {
      // setting our current led light.         
      i++;
      p = p + i;
      j = j - i;
      q = q + i;
      
      leds[t] = CRGB((p),(j),(q));
      FastLED.show();
      delay(100);
    }
    //this for loop is backwards.
    for(int t = 59; t > 29; t = t-1) {
     // setting up our current led light
      leds[t] = CRGB::Black;
      FastLED.show();
      
    } 
  }
  }

  // for DisoWave()we will be using the same method as the other two with an added  while loop instead.
  void DiscoWave(){
    
    int i = 0; // the changer of lights 
    int p = 153; // holds the Green positions.
    int j = 255; // holds the Red postions.
    int q = 51; // holds the Blue postion 

    
    //this while loop will change the color per iteration.
    while (i < 255){
      
      p = p + i;
      j = j - i;
      q = q + i;
      //testing each variable to make sure they are not out of bounce.If they are we will rest them to default.
      if (i > 254){
        i = 0;
        } 
      if (j < 0 ){
        j = 255;
        }
     if (q > 254){
        q = 0;
       }
    if (p > 254){
        p = 0;
        }
      
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
      delay(1000);//delay for a second 
    }
  } 
// --------------------------------------------------------------------------------------------
