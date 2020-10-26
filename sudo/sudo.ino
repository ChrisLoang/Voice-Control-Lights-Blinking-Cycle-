
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
 This pins colors will be used with the wave and button switch
 * LED Green_light digital pin D13
 * LED Orange_Light digital pin D8
 * LED Red_Light digital pin D9
 * LED Blue_Light digital pin D10
 * Switch Button switch_but digital D7
 These pins colors will be used with the circular pattern.
 *LED Green_ligt2 Anolog pin A0
 *LED Orange_Light Anolog pin A1
 *LED Red_Light2 Anolog pin A2
 *LED Blue_Light2 Anolog pin A3
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
const int Green_Light = 13; 
const int Orange_Light = 8;
const int Red_Light = 9;
const int Blue_Light = 10;

// call each Anolog led light that will be used in the circular pattern, disco pattern.
const int Green_Ligt2 = A0;
const int Orange_Light2 = A1;
const int Red_Light2 = A2;
const int Blue_Light2 = A3;

//call each pin to the bluetooth adaptor
 
 SoftwareSerial MyBlue(0, 1); // RX | TX
  int store_voice_frequency = 0;
//call a variable for the button switch
const int button_switch = 7;

void setup(){
  // set up the LCD's number of columns and rows and input:
  lcd.begin(16, 2);
  
  // All inputs will be setup.
  MyBlue.begin(9600);
  
  //Button Switch:
  pinMode(button_switch, INPUT);
  
  // All outputs will be setup.
  //Circular and Disco LED lights 
  pinMode(Green_Ligt2, OUTPUT);
  pinMode(Orange_Light2, OUTPUT);
  pinMode(Red_Light2, OUTPUT);
  pinMode(Blue_Light2, OUTPUT);
  
  //Wave, Disco and Button switch
  pinMode(Green_Light, OUTPUT);
  pinMode(Orange_Light,OUTPUT);
  pinMode(Red_Light, OUTPUT);
  pinMode(Blue_Light, OUTPUT);
  
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

//digitalWrite(A0, HIGH); or digitalWrite(A0, LOW); works as if they are digital pins.
//This function is used in med range voice.
void circular_pattern(){
  digitalWrite(Green_Light2, HIGH);
  digitalWrite(Orange_Light2, LOW);
  digitalWrite(Red_Light2, LOW);
  digitalWrite(Blue_Light2, LOW);
  delay(1000);
  
  digitalWrite(Green_Light2, LOW);
  digitalWrite(Orange_Light2, HIGH);
  digitalWrite(Red_Light2, LOW);
  digitalWrite(Blue_Light2, LOW);
  delay(1000);
  
  digitalWrite(Green_Light2, LOW);
  digitalWrite(Orange_Light2, LOW);
  digitalWrite(Red_Light2, HIGH);
  digitalWrite(Blue_Light2, LOW);
  delay(1000);
  
  digitalWrite(Green_Light2, LOW);
  digitalWrite(Orange_Light2, LOW);
  digitalWrite(Red_Light2, LOW);
  digitalWrite(Blue_Light2, HIGH);
  delay(1000);
  
  digitalWrite(Green_Light2, LOW);
  digitalWrite(Orange_Light2, LOW);
  digitalWrite(Red_Light2, HIGH);
  digitalWrite(Blue_Light2, LOW);
  delay(1000);

  digitalWrite(Green_Light2, LOW);
  digitalWrite(Orange_Light2, HIGH);
  digitalWrite(Red_Light2, LOW);
  digitalWrite(Blue_Light2, LOW);
  delay(1000);

  digitalWrite(Green_Light2, HIGH);
  digitalWrite(Orange_Light2, LOW);
  digitalWrite(Red_Light2, LOW);
  digitalWrite(Blue_Light2, LOW);
  delay(1000);

  
}
void circular_pattern2(){}//optional if we use neopixal led.
void disco_pattern(){}//similar to the wave and circular pattern just use both patterns together.
void disco_pattern2(){}//optional if we use neopixal led.

// all digital pins will be used in here. 
//this function will be called for low range frequency of our voices.
void wave_pattern(){
  digitalWrite(Green_Light, HIGH);
  digitalWrite(Orange_Light, LOW);
  digitalWrite(Red_Light, LOW);
  digitalWrite(Blue_Light, LOW);
  delay(1000);
  
  digitalWrite(Green_Light, LOW);
  digitalWrite(Orange_Light, HIGH);
  digitalWrite(Red_Light, LOW);
  digitalWrite(Blue_Light, LOW);
  delay(1000);
  
  digitalWrite(Green_Light, LOW);
  digitalWrite(Orange_Light, LOW);
  digitalWrite(Red_Light, HIGH);
  digitalWrite(Blue_Light, LOW);
  delay(1000);
  
  digitalWrite(Green_Light, LOW);
  digitalWrite(Orange_Light, LOW);
  digitalWrite(Red_Light, LOW);
  digitalWrite(Blue_Light, HIGH);
  delay(1000);
  
  digitalWrite(Green_Light, LOW);
  digitalWrite(Orange_Light, LOW);
  digitalWrite(Red_Light, HIGH);
  digitalWrite(Blue_Light, LOW);
  delay(1000);

  digitalWrite(Green_Light, LOW);
  digitalWrite(Orange_Light, HIGH);
  digitalWrite(Red_Light, LOW);
  digitalWrite(Blue_Light, LOW);
  delay(1000);

  digitalWrite(Green_Light, HIGH);
  digitalWrite(Orange_Light, LOW);
  digitalWrite(Red_Light, LOW);
  digitalWrite(Blue_Light, LOW);
  delay(1000);

}

void button_switch_control(int bitbutton){}//similar to lab two. You may use the wave pattern for this function.
void voice_ledfrequency(int voice_recoded){} // still looking for how to do it for now work on the other three. 
