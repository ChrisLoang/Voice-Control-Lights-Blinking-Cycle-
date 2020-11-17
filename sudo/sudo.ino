
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
 * Bluetooth RXD pin to  Arduino digital pin RX/D0
 * Bluetooth TXD pin to  Arduino digital pin TX/D1
 * Bluetooth VCC pin to Arduino Analog  pin 5V
 * Bluetooth GND pin to Arduino Analog pin GRN
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
#include <FastLED.H>

//for wave pattern function.
#define wave_pin 6
#define wave_count 60
#define color__combination GRB
#define chip WS2812B
#define Bright 200
#define Frame 60



// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Declare our NeoPixel strip and ring objects:
//wave
Adafruit_NeoPixel wave_strip(wave_count, wave_pin, NEO_GRB + NEO_KHZ800);
//what you see in the bellow is we are grouping 10 rgb led lights together and placing them 
// all the same color. Therefore we will be needing 6 since we have 60 rgb led lights.
uint32_t first_ten = wave_strip.Color(255,0,255);//0 through 9 or 0 through 4
uint32_t second_ten = wave_strip.Color(255,255,0);// 10 through 19 or 5 through 9
uint32_t third_ten = wave_strip.Color(0,0,255); // 20 through 29 or 10 through 14
uint32_t fourth_ten = wave_strip.Color(0,255,0);// 30 through 39 or 15 through 19
uint32_t fifth_ten = wave_strip.Color(255,0,0);// 40 through 49 or 20 through 24
uint32_t six_ten = wave_strip.Color(198,100,200);//50 through 59 or 25 through 29

//second group of RGB 30 led lights Circular 
uint32_t seven_ten = wave_strip.Color(255,0,255);//30 through 34. 
uint32_t eight_ten = wave_strip.Color(255,255,0);// 35 through 39. 
uint32_t nine_ten = wave_strip.Color(0,0,255); // 40 through 44.
uint32_t ten_ten = wave_strip.Color(0,255,0);// 45 through 49.
uint32_t eleven_ten = wave_strip.Color(255,0,0);// 50 through 54.
uint32_t tweleve_ten = wave_strip.Color(198,100,200);//54 through 59.

//used for oppiste direction
bool direction = false;

//CRGB coding from Danial Garcia the creator of the library Fast
CRGB leds(wave_count);
CRGBPalettel6 dynamp;

//call each pin to the bluetooth adaptor
//must decided one if not try to see how it may work. 
 String store_voice_string = "";
 

//call a variable for the button switch
const int button_switch = 7;
int button_count = 0;
long random_number = 0;

//setup has change to fit neopixal led light. 
void setup(){
  // set up the LCD's number of columns and rows and input:
  lcd.begin(16, 2);
;
  dynamp = HeatColors_p;
  //Button Switch:
  pinMode(button_switch, INPUT);

  // All outputs will be setup.
  
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
if(Serial.availble()){  
	while (Serial.available()){
		delay(10);
		char c = Serial.read();
		if (c == '#'){break;}
		store_voice_frequency += c; // shorthand for voice = voice + c
	}
	lcd.print("Voice frequency detected and will power up ");
	lcd.print(ReceivingVocieFromPhone(store_voice_frequency(store_voice_frequency));
    }
else{
    	lcd.print("Switch button has the power to ");
    	blinkWave();
    	switchLEDs();
    } 
  lcd.setCursor(0,1);
  //if and else if statements must be added here so that the lcd display knows what to print. 
  
  
  delay(1000);//delay can be modified
}

//Possible needed functions. 
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

//In the even we decide to use only the RGB 60 LED lights we must use these three functions.
//Spliting the RGB 60 LED lights into two groups.
void WaveCycle(){
 wave_strip.fill(first_ten, 0, 4);
 wave_strip.show();
 wave_strip.fill(second_ten, 5, 9);
 wave_strip.show();
 wave_strip.fill(third_ten, 10, 14);
 wave_strip.show();
 wave_strip.fill(fourth_ten, 15, 19);
 wave_strip.show();
 wave_strip.fill(fifth_ten, 20, 24);
 wave_strip.show();
 wave_strip.fill(six_ten, 25, 29);
 wave_strip.show();
 wave_strip.fill(fifth_ten, 20, 24);
 wave_strip.show();
 wave_strip.fill(fourth_ten, 15, 19);
 wave_strip.show();
 wave_strip.fill(third_ten, 10, 14);
 wave_strip.show();
 wave_strip.fill(second_ten, 5, 9);
 wave_strip.show();
 wave_strip.fill(first_ten, 0, 4);
 wave_strip.show();

}

// RGB 30 LED lights second group  
void CircularWave(){
 wave_strip.fill(seven_ten, 30, 34);
 wave_strip.show();
 wave_strip.fill(eight_ten, 35, 39);
 wave_strip.show();
 wave_strip.fill(nine_ten, 40,44 );
 wave_strip.show();
 wave_strip.fill(ten_ten, 45, 49);
 wave_strip.show();
 wave_strip.fill(eleven_ten, 50, 54);
 wave_strip.show();
 wave_strip.fill(twelve_ten, 55, 59);
 wave_strip.show();
 wave_strip.fill(eleven_ten, 50, 54);
 wave_strip.show();
 wave_strip.fill(ten_ten, 45, 49);
 wave_strip.show();
 wave_strip.fill(nine_ten, 40, 44);
 wave_strip.show();
 wave_strip.fill(eight_ten, 35, 39);
 wave_strip.show();
 wave_strip.fill(seven_ten, 30, 34);
 wave_strip.show();

}

//combining the RGB 60 LED strip together
 void DiscoWave(){
  wave_strip.fill(seven_ten,30 , 34);
  wave_strip.show();
  wave_strip.fill(first_ten, 0, 4);
  wave_strip.show();
  wave_strip.fill(eight_ten, 35, 39);
  wave_strip.show();
  wave_strip.fill(second_strip, 5, 9);
  wave_strip.show();
  wave_strip.fill(nine_ten, 40, 44);
  wave_strip.show();
  wave_strip.fill(third_ten,10 ,14 );
  wave_strip.show();
  wave_strip.fill(ten_ten, 45, 49);
  wave_strip.show();
  wave_strip.fill(fourth_ten, 15 ,19);
  wave_strip.show();
  wave_strip.fill(eleven_ten,50 ,54);
  wave_strip.show();
  wave_strip.fill(fifth_ten, 20, 24);
  wave_strip.show();
  wave_strip.fill(twelve_ten, 55, 59);
  circular_ring.show();
  wave_strip.fill(six_ten, 50, 59);
  wave_strip.show();
  wave_strip.fill(eleven_ten,50 ,54);
  wave_strip.show();
  wave_strip.fill(fifth_ten, 20, 24);
  wave_strip.show();
  wave_strip.fill(ten_ten, 45, 49);
  wave_strip.show();
  wave_strip.fill(fourth_ten, 15 ,19);
  wave_strip.show();
  wave_strip.fill(nine_ten, 40, 44);
  wave_strip.show();
  wave_strip.fill(third_ten,10 ,14 );
  wave_strip.show();
  wave_strip.fill(eight_ten, 35, 39);
  wave_strip.show();
  wave_strip.fill(second_strip, 5, 9);
  wave_strip.show();
  wave_strip.fill(seven_ten,30 , 34);
  wave_strip.show();
  wave_strip.fill(first_ten, 0, 4);
  wave_strip.show();
  
  }
//Alternative Button function
void switchLEDs()
{
	lcd.print(“Turn on the wave pattern”);
	lcd.setCursor(0,1)
	Scrolling function(“Alternative functions are: Turn on Circular pattern”);
 button = digitalRead(button_switch);

 if(button == HIGH){WaveCycle();}
}


// still looking for how to do it for now work on the other three.
void ReceivingVocieFromPhone(int voice_recoded){
	//this will turn on the wave pattern on. 
	if (store_voice_frequency == "*turn on wave"){
		WaveCycle();
		return "wave on!";
	}
	//this will turn on the circular pattern on.
  	else if (store_voice_frequency == "*turn on circular"){
		CircularWave();
		return "circular on!";
	}
	//this will activate the disco pattern.
  	else if (store_voice_frequency == "*turn on both"){
		DiscoWave();
		return "Disco on!";
	}
  	return "not a command try again.";
}  

void turn_off(){}// turns off all neopixel lights. 
