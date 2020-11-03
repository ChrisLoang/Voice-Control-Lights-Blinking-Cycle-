/*  Voice to Frequency to Switch LED light show. 

Discription of our project.

 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * Bluetooth RXD pin to digital pin RX/D0
 * Bluetooth TXD pin to digital pin TX/D1
 * Bluetooth VCC pin tO Analog  pin 5V
 * Potentioment 100K 
 * 220 resistor:
 *This pins will connet a circular ring and strip colors will be used with the wave and button switch.
 *Switch button pin to digital pin 7
 * 220 resistor:
 * Ground connection
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


// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//call each digital led light that will be used in wave pattern, disco pattern and button switch.

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

//call each pin to the bluetooth adaptor
 SoftwareSerial MyBlue(0, 1); // RX | TX
 //must decided one if not try to see how it may work. 
 String store_voice_string = "";
 int store_voice_pitch = 0;

//call a variable for the button switch
const int button_switch = 7;
int button_count = 0;

//setup has change please change it to fit neopixal led light. 
void setup(){
  // set up the LCD's number of columns and rows and input:
  lcd.begin(16, 2);
  
  // All inputs will be setup.
  MyBlue.begin(9600);
  
  //Button Switch:
  pinMode(button_switch, INPUT);
  
  // All outputs will be setup.
  //Circular and Disco LED lights 
  circular_ring.begin();
  circular_ring.show();// by default all pixels are "off".
  
  //Wave, Disco and Button switch
  wave_strip.begin();
  wave_strip.show();// by default all pixels are "off".
 
  Serial.begin(9600);

  // Print a message that introduces the group(optional).
  lcd.print("");
}

//loop is not done yet please continue working on it.
void loop() {
  //seeing if the bluetooth is connected and if it worked use the store_voice_frequency in void voice_ledfrequency(int voice_recoded){}.
 // if (MyBlue.available()){store_voice_frequency = MyBlue.read();}

  lcd.setCursor(0,1);
  
  delay(500);//delay can be modified
}

//Possible needed functions. 
//patterns
void CircularWave(){}// ring rgb neopixal led.
void DiscoWave(){}//call CirculWave and WaveCycle or create your won pattern.
//rgb neopixel led light strips
void WaveCycle(){
 wave_strip.fill(first_ten, 0, 9);
 wave_strip.show();
 wave_strip.fill(second_ten, 10, 19);
 wave_strip.show();
 wave_strip.fill(first_ten, 20, 29);
 wave_strip.show();
 wave_strip.fill(first_ten, 30, 39);
 wave_strip.show();
 wave_strip.fill(first_ten, 40, 49);
 wave_strip.show();
 wave_strip.fill(first_ten, 50, 59);
 wave_strip.show();
 wave_strip.fill(first_ten, 40, 49);
 wave_strip.show();
 wave_strip.fill(first_ten, 30, 39);
 wave_strip.show();
 wave_strip.fill(first_ten, 20, 29);
 wave_strip.show();
 wave_strip.fill(second_ten, 10, 19);
 wave_strip.show();
 wave_strip.fill(first_ten, 0, 9);
 wave_strip.show();
}

void RandomCycle(){} // optional if needed a 4th type of pattern.
void BlinkCycle(int bitbutton){}//similar to lab two. You may use the wave pattern for this function.

//Helper function. 
void ReceivingVocieFromPhone(String voice_recoded){} // still looking for how to do it for now work on the other three. 
void LCDText(){}// Display text for function we having and next functikon as suggestion.
void HandleString(){}// to handle the string received from voice command and will convert our voice to string.
void turn_off(){}// turns off all neopixel lights. 
