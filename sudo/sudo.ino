
/*  Title of our project. 

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
//optional libraries
#include <Adafruit_NeoPixel.h>
#include <CurieBLE.h>
#define printJSON 1
#define BLEenabled 1


// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//call each digital led light that will be used in wave pattern, disco pattern and button switch.



//call each pin to the bluetooth adaptor
 
 SoftwareSerial MyBlue(0, 1); // RX | TX
  int store_voice_frequency = 0;
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

  
  //Wave, Disco and Button switch

  
  Serial.begin(9600);

  // Print a message that introduces the group(optional).
  lcd.print("");
}

//loop is not done yet please continue working on it.
void loop() {
  //seeing if the bluetooth is connected and if it worked use the store_voice_frequency in void voice_ledfrequency(int voice_recoded){}.
  if (MyBlue.available()){store_voice_frequency = MyBlue.read();}

  lcd.setCursor(0,1);
  
  delay(500);//delay can be modified
}

//Possible needed functions. 
//Wave pattern
void CircularWave(){}// ring rgb neopixal led.
void DiscoWave(){}//call CirculWave and WaveCycle or create your won pattern.
void WaveCycle(){}//rgb neopixel led light strips
void RandomCycle(){} // optional if needed a 4th type of pattern.
void BlinkCycle(int bitbutton){}//similar to lab two. You may use the wave pattern for this function.

//Helper function. 
void ReceivingVocieFromPhone(int voice_recoded){} // still looking for how to do it for now work on the other three. 
void LCDText(){}// Display text for function we having and next functikon as suggestion.
void HandleSting(){}// to handle the string received from voice command and will convert our voice to string.
void loop(){}// will loop 

