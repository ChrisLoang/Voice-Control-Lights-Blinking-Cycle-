


/*Bluetooth adaptor and application test.
    *Discriptoin: 
        * Test the bluetooth adaptor by using the application on an andriod device.
 
    *The circuit:
        * Bluetooth RXD pin to Arduino digital pin TX/D1
        * Bluetooth TXD pin to Arduino digital pin DX/D0   
        * Bluetooth GND pin to Arduino Anolog GND
        * Bluetooth VCC pin to Arduino Anolog 5V or 3.3V
        * LCD RS pin to digital pin 12
        * LCD Enable pin to digital pin 11
        * LCD D4 pin to digital pin 5
        * LCD D5 pin to digital pin 4
        * LCD D6 pin to digital pin 3
        * LCD D7 pin to digital pin 2
        * LCD R/W pin to ground
        * 10K resistor:
        * ends to +5V and ground
 */

// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//creating the bluetooth adapter.
String store_voice_frequency; 
int voice = 0;
void setup() {
  // set up the LCD's number of columns and rows and input:
  lcd.begin(16, 2);
  // All inputs will be setup.
  Serial.begin(9600);
  
}

void loop() {
   //seeing if the bluetooth is connected and if it worked use the store_voice_frequency in void voice_ledfrequency(int voice_recoded){}.
    
    
    //remove "/*" and use "//" on the voice text and then reupload the code to your Ardruino.
    //do me a favor do not have RX/TX on the bluetooth connected other wise it will not be able to upload. 
    // Also, make sure you reconnect RX/TX correctly. This way it will read correctly. 
    while (Serial.available()){
      delay(10);
      char c = Serial.read();
      if (c == '#'){break;}
      store_voice_frequency += c; // shorthand for voice = voice + c
    }
      Serial.print("Voice Frequency is: ");  
      Serial.print(store_voice_frequency);
      Serial.print('\n');
      lcd.print("Voice Frequency is: "); 
      lcd.print(store_voice_frequency);
      
    if (store_voice_frequency.length() > 0) {
     Serial.print(hello_world());
     Serial.print('\n');
    }
    
    store_voice_frequency = "";
   
   //used this to test out voice frequency. 
//   voice = Serial.read();
//      Serial.print("Voice Frequency is: ");  
//      Serial.print(voice);
//      Serial.print('\n');
//      lcd.print("Voice Frequency is: "); 
//      lcd.print(voice);
delay(1000);
}

// The function below will only work if you use either: 
//turn on wave
//turn on circular
//turn on both   
String hello_world(){
  if (store_voice_frequency == "*turn on Wave"|| store_voice_frequency == "*Turn on wave" || store_voice_frequency == "*turn on wave" || store_voice_frequency == "*Turn on Wave"){return "wave on!";}
  else if (store_voice_frequency == "*Turn on circular" || store_voice_frequency == "*turn on Circular" || store_voice_frequency == "*Turn on Circular" || store_voice_frequency == "*turn on circular"){return "circular on!";}
  else if (store_voice_frequency == "turn on Disco" || store_voice_frequency == "turn on disco" || store_voice_frequency == "Turn on Disco" || store_voice_frequency == "Turn on Disco"){return "Disco on!";}
  return "not a command try again.";
  }
