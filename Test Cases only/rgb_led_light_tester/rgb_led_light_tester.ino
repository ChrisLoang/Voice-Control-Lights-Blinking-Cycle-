/*RGB LED lights Testing. 
 
 * Discription:
  * The purpose of ths is project is to test out the RGB LED light ring. 
  * 
  *Circuit:
    *RGB 93 LED light Ring
      *RGB 93 LED light ring red ocrd goes to Arduino Anolog pin 5V.
      *RGB 93 LED light ring black ocrd goes to Arduino Anolog pin GRD.
      *RGB 93 LED light ring power pin goes to Arduino Digital pin  
    *RGB 60 LED light Strip
      *RGB 93 LED light strip red ocrd goes to Arduino Anolog pin 5V.
      *RGB 93 LED light strip black ocrd goes to Arduino Anolog pin GRD.
      *RGB 93 LED light strip power pin goes to Arduino Anolog pin
 * 
 */

// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

//for wave pattern function.
#define wave_pin 6
#define wave_count 60

//for circular pattern function.
#define circular_pin 9
#define circular_count 94

// Declare our NeoPixel strip and ring objects:

//wave
Adafruit_NeoPixel wave_strip(wave_count, wave_pin, NEO_GRB + NEO_KHZ800);
//what you see in the bellow is we are grouping 10 rgb led lights together and placing them 
// all the same color. Therefore we will be needing 6 since we have 60 rgb led lights.
uint32_t first_ten = wave_strip.Color(255,0,255);//0 through 9
uint32_t second_ten = wave_strip.Color(255,255,0);// 10 through 19
uint32_t third_ten = wave_strip.Color(0,0,255); // 20 through 29
uint32_t fourth_ten = wave_strip.Color(0,255,0);// 30 through 39
uint32_t fifth_ten = wave_strip.Color(255,0,0);// 40 through 49
uint32_t six_ten = wave_strip.Color(198,100,200);//50 through 59

//circular
Adafruit_NeoPixel circular_ring(circular_count, circular_pin, NEO_GRB + NEO_KHZ800);
// all the same color. Therefore we will be needing 6 since we have 60 rgb led lights.
uint32_t first_ring = circular_ring.Color(255,0,255);//0 through 31
uint32_t second_ring = circular_ring.Color(255,255,0);// 32 through 55 
uint32_t third_ring = circular_ring.Color(0,0,255); //  56 through 71
uint32_t fourth_ring = circular_ring.Color(0,255,0);//  72 through 83 
uint32_t fifth_ring = circular_ring.Color(255,0,0);//  84 through 91
uint32_t six_ring = circular_ring.Color(198,100,200);//  92 through 92


void setup() {
 // All outputs will be setup.
 
  //Circular and Disco LED lights 
  circular_ring.begin();
  circular_ring.show();// by default all pixels are "off".
  
  //Wave, Disco and Button switch
  wave_strip.begin();
  wave_strip.show();// by default all pixels are "off".
 
  Serial.begin(9600);

}

void loop() {
  // Calling up the functions to test the RGB LED ring and strip. 
  // you may test them seperate by using // to one of the functions 
  //by the way to test them both together all you need is disco funtion you do not need all three. 
  DiscoWave(); 
  CircularWave();
  WaveCycle();
  
}
// RGB 60 LED Light ring  
void CircularWave(){
 circular_ring.fill(first_ring, 0, 31);
 circular_ring.show();
 circular_ring.fill(second_ring, 32, 55);
 circular_ring.show();
 circular_ring.fill(third_ring, 56, 71);
 circular_ring.show();
 circular_ring.fill(fourth_ring, 72, 83);
 circular_ring.show();
 circular_ring.fill(fifth_ring, 84, 91);
 circular_ring.show();
 circular_ring.fill(six_ring, 92, 92);
 circular_ring.show();
 circular_ring.fill(fifth_ring, 84, 91);
 circular_ring.show();
 circular_ring.fill(fourth_ring, 72, 83);
 circular_ring.show();
 circular_ring.fill(third_ring, 56, 71);
 circular_ring.show();
 circular_ring.fill(second_ring, 32, 55);
 circular_ring.show();
 circular_ring.fill(first_ring, 0, 21);
 circular_ring.show();

}
//RGB 60 LED light Strip light up.
void WaveCycle(){
 wave_strip.fill(first_ten, 0, 9);
 wave_strip.show();
 wave_strip.fill(second_ten, 10, 19);
 wave_strip.show();
 wave_strip.fill(third_ten, 20, 29);
 wave_strip.show();
 wave_strip.fill(fourth_ten, 30, 39);
 wave_strip.show();
 wave_strip.fill(fifth_ten, 40, 49);
 wave_strip.show();
 wave_strip.fill(six_ten, 50, 59);
 wave_strip.show();
 wave_strip.fill(fifth_ten, 40, 49);
 wave_strip.show();
 wave_strip.fill(fourth_ten, 30, 39);
 wave_strip.show();
 wave_strip.fill(third_ten, 20, 29);
 wave_strip.show();
 wave_strip.fill(second_ten, 10, 19);
 wave_strip.show();
 wave_strip.fill(first_ten, 0, 9);
 wave_strip.show();
}

//Both RGB 60 LED light strip  and RGB LED Light ring
 void DiscoWave(){
  circular_ring.fill(first_ring, 0, 31);
  circular_ring.show();
  wave_strip.fill(first_ten, 0, 9);
  wave_strip.show();
  circular_ring.fill(second_ring, 32, 55);
  circular_ring.show();
  wave_strip.fill(second_ten, 10, 19);
  wave_strip.show();
  circular_ring.fill(third_ring, 56, 71);
  circular_ring.show();
  wave_strip.fill(third_ten, 20, 29);
  wave_strip.show();
  circular_ring.fill(fourth_ring, 72, 83);
  circular_ring.show();
  wave_strip.fill(fourth_ten, 30, 39);
  wave_strip.show();
  circular_ring.fill(fifth_ring, 84, 92);
  circular_ring.show();
  wave_strip.fill(fifth_ten, 40, 49);
  wave_strip.show();
  circular_ring.fill(six_ring, 92, 92);
  circular_ring.show();
  wave_strip.fill(six_ten, 50, 59);
  wave_strip.show();
  circular_ring.fill(fifth_ring, 84, 91);
  circular_ring.show();
  wave_strip.fill(fifth_ten, 40, 49);
  wave_strip.show();
  circular_ring.fill(fourth_ring, 72, 83);
  circular_ring.show();
  wave_strip.fill(fourth_ten, 30, 39);
  wave_strip.show();
  circular_ring.fill(third_ring, 56, 71);
  circular_ring.show();
  wave_strip.fill(third_ten, 20, 29);
  wave_strip.show();
  circular_ring.fill(second_ring, 32, 55);
  circular_ring.show();
  wave_strip.fill(second_ten, 10, 19);
  wave_strip.show();
  circular_ring.fill(first_ring, 0, 31);
  circular_ring.show();
  wave_strip.fill(first_ten, 0, 9);
  wave_strip.show();
  
  }
