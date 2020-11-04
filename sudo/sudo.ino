
/*   Voice Control Lights Blinking Cycle.

Discription of our project.
We will have an Android emulator on Windows or Mac to connect to bluetooth with a HC - 05 bluetooth sensor module 
to enable voice recognition. We will have a Serial port from Arduino, and perform serial readStrings to get the string from the serial port,
and that will be our input for the project. Our input will be an input to command LEDs functionality, we will have NeoPixels and use our NeoPixels LEDs to display disco,
wave functionality, also changing the colors. To display disco functionality, we will have it blink multiple in random, and for a wave functionality, 
we will flash the first led, follow with a second one, and along the strip of the neopixel leds. At the same time, we will have an LCD display that displays current 
information about the NeoPixels functionality that is being used, and for the second row of the LCD, we will show suggestions for the alternative functionality of the 
LEDs that you can input. We will also have a button or a switch, that you can manually change the LEDs functionalities rather than have your voices as input.
 
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

//call each pin to the bluetooth adaptor
 SoftwareSerial MyBlue(0, 1); // RX | TX
 //must decided one if not try to see how it may work. 
 String store_voice_string = "";
 int store_voice_pitch = 0;

//call a variable for the button switch
const int button_switch = 7;
int button_count = 0;
long random_number = 0;

//setup has change to fit neopixal led light. 
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

  randomSeed(analogRead(0));
  // Print a message that introduces the group(optional).
  lcd.print("");
}

//loop is not done yet please continue working on it.
void loop() {
  //seeing if the bluetooth is connected and if it worked use the store_voice_frequency in void voice_ledfrequency(int voice_recoded){}.
 // if (MyBlue.available()){store_voice_frequency = MyBlue.read();}
  lcd.setCursor(0,1);
  //if and else if statements must be added here so that the lcd display knows what to print. 
  lcd.print("Switch button has the power to ");
  lcd.print("Voice frequency detected and will power up ");
  delay(1000);//delay can be modified
}

//Possible needed functions. 
//patterns
// ring rgb neopixal led.
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
//call CirculWave and WaveCycle or create your won pattern.
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
//rgb neopixel led light strips
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

//if the switch button selects this function then
//let the button_count be randomly selected to choose one of the three pattern.
void RandomCycle(){
 lcd.print("Random decides to select ");
  button_count = random(3);// will select a number between 0 through 2.
  
  // figuring out which one to turn on. 
  if (button_count == 1){
    lcd.print("Wave pattern.");
    WaveCycle();
    }
  else if (button_count == 2){
    lcd.print("Circular pattern.");
    CircularWave();
   }
  else{
    lcd.print("Disco pattern.");
    DiscoWave();
  } 
 button_count = 0;
}
  
//Helper function. 
//this function is called when the switch button has been press. 
void blinkWave(){
//depending on the button_count determines which of the four wave pattern, circular pattern, disco pattern or random selection pattern will be activated. 
 
 //Depending on the button_count, determines which one will be turn on. 
   if (button_count == 1){
   lcd.print(" turn on Wave pattern."); 
   WaveCycle();
    }
  else if (button_count == 2){
    lcd.print(" turn on Circular pattern."); 
    CircularWave();
   }
  else if (button_count == 3){
    lcd.print(" turn on Disco pattern."); 
    DiscoWave(); 
  }
  else{
    lcd.print(" give random a chance to select which one will turn on."); 
    RandomCycle();
  }
}
// still looking for how to do it for now work on the other three.
void ReceivingVocieFromPhone(int voice_recoded){}  

void turn_off(){}// turns off all neopixel lights. 
