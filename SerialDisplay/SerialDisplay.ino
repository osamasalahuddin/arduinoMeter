/*
  LiquidCrystal Library - Serial Input
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch displays text sent over the serial port 
 (e.g. from the Serial Monitor) on an attached LCD.
 
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
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/LiquidCrystalSerial
 */

// include the library code:
#include <LiquidCrystal.h>
byte fuel1[8] = {0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};

byte fuel2[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111
};

byte fuel3[8] =   {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111
};

byte fuel4[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte fuel5[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte fuel6[8] = {
  0b11111,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte fuel7[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char dataread[256];

int i,datalength;

int lcdcount = 0;

void setup(){

  lcd.createChar(0,fuel1);
  lcd.createChar(1,fuel2);
  lcd.createChar(2,fuel3);
  lcd.createChar(3,fuel4);
  lcd.createChar(4,fuel5);
  lcd.createChar(5,fuel6);
  lcd.createChar(6,fuel7);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial1.begin(115200);
  Serial.begin(9600);

  lcd.write("Hello");
  delay(1000);

  lcd.write(byte(0));
  delay(1000);
  lcd.write(byte(1));
  delay(1000);
  lcd.write(byte(2));
  delay(1000);
  lcd.write(byte(3));
  delay(1000);
  lcd.write(byte(4));
  delay(1000);
  lcd.write(byte(5));
  delay(1000);
  lcd.write(byte(6));
  delay(1000);

}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial1.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    i = 0;
    datalength = 0;
    lcd.setCursor(0,0);
    while (Serial1.available() > 0) {
      // display each character to the LCD
      dataread[i++] = Serial1.read();
    }
    while (datalength < i)
    {
      lcd.write(dataread[datalength]);
      Serial.write(dataread[datalength++]);
    }
    lcd.setCursor(0,1);
    switch (lcdcount){
      case 0:{
        lcd.write(byte(0));
        lcdcount++;
        break;
      }
      case 1:{
        lcd.write(byte(1));
        lcdcount++;
        break;
      }
      case 2:{
        lcd.write(byte(2));
        lcdcount++;
        break;
      }
      case 3:{
        lcd.write(byte(3));
        lcdcount++;
        break;
      }
      case 4:{
        lcd.write(byte(4));
        lcdcount++;
        break;
      }
      case 5:{
        lcd.write(byte(5));
        lcdcount++;
        break;
      }
      case 6:{
        lcd.write(byte(6));
        lcdcount = 0;
        break;
      }
    }
  }
}
