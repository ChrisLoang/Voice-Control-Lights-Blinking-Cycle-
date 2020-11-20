

/*Button Switch test.
    *Discriptoin: 
        * Test the button switch.
 
    *The circuit:
        * Bluetooth connecter  pin to Arduino digital pin 6
        * Button Switch power pin to Arduino  Anolog pin 5V   
        * Button Switch  GND pin to Arduino Anolog GND
        * Resister 220
        * LCD RS pin to digital pin 12
        * LCD Enable pin to digital pin 11
        * LCD D4 pin to digital pin 5
        * LCD D5 pin to digital pin 4
        * LCD D6 pin to digital pin 3
        * LCD D7 pin to digital pin 2
        * LCD R/W pin to ground
        * 10K resistor:
        * ends to +5V and ground
        * 
*/
// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

// a digital pin on the arduino to read in when the button switch has been press.
#define button_switch 6
int count = 0;
int button_press = 0;
// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Starting up the input devices:
  pinMode(button_switch, INPUT);

  //Starting up the lcd and Serial
  Serial.begin(9600);
  lcd.begin(16,2);

}

void loop() {
  // steting up the button switch to increase the count.
  button_press = digitalRead(button_switch);

  //test to see if it was press.
  if(button_press == HIGH){
    count++;

    //Serial Print outs
    Serial.print("Button was press. ");
    Serial.print("value of count is now: ");
    Serial.print(count);
    Serial.print("."); 
    Serial.print('\n');
    
    //lcd print outs
    lcd.print("Button was press. ");
    lcd.print("value of count is now: ");
    lcd.print(count);
    lcd.print(".");
    lcd.print('\n');
  }
  button_press = LOW;
  delay(10000);

}
