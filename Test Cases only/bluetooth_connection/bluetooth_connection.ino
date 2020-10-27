
/* Please download Android Meets Robot app on an android device. 
 *  You could use another app if using ios device. 
 * The circuit:
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
 * 220 resistor
 * 
 * Warning this test case can be altered if needed. 
*/

//Included libraries
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

//constant  variables
int led = 9;
SoftwareSerial blue(0,1);//RX/TX

// initialize any needed LCD interface pin, bluethooth module pin, button switch, and LED. 
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  //setup of lcd screen.
  blue.begin(9600);
  lcd.begin(16,2);
  lcd.print("Get ready to test your voice!");

  //setup led light
  pinMode(led, OUTPUT);
}

void loop() {
  led_lcd();
  //Bluetooth to Serial communicatiolsllsn.
  if (blue.available()){Serial.write(blue.read());}

  //Serial to bluetooth communicatoin
  if (Serial.available()){blue.write(Serial.read());}
  
}

//this function helps light up the screen and print to LCD display.
void led_lcd(){
  if(blue.read() > 0 && Serial.read()){
    digitalWrite(led,HIGH);
    lcd.print("Voice detected.");
    }
  else{
    digitalWrite(led,HIGH);
    lcd.print("Voice detected.");
    }
}


//
