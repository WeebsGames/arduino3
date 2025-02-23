/*

Areeb Jamili, ajami7, 669950568
Lab 3 - Scrolling Output
This code is supposed to scroll through any string in the quote[] variable while displaying my name in the center of the top row
I assumed the schematic I found online for the 16 pin lcd would work. I also assumed the components from my kit would work as intended.
I used an arduino forum to find the schematic and starting code for the 16 pin lcd.
https://docs.arduino.cc/learn/electronics/lcd-displays/ 

*/


// include the library code:
#include <LiquidCrystal.h>
#include <string.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long time;
unsigned long curr;
char buffer[5];
//extra spaces to allow the sting to smoothly loop around
char quote[] = "Protocol 3: Protect the pilot      ";
int thisChar = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // set the cursor to the middle of the top row
  lcd.setCursor(6,0);
  // put "Areeb" into the buffer and print to lcd
  sprintf(buffer, "Areeb");
  lcd.print(buffer);
}

void loop() {
  // get the time
  time = millis();

  if(time - curr >= 400){
    //every half seconds clear screen and print name in the middle again
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print(buffer);
    lcd.setCursor(0, 1);
    curr = time;
    //print a portion of the string staring at thisChar every time this if statement is excecuted
    for(int i = thisChar; i < thisChar + 16; i++){
      if(i < strlen(quote)){
        lcd.print(quote[i]);
      } else {
        //loops around to the beginning
        lcd.print(quote[i-strlen(quote)]);
      }
    }
    thisChar++;
    if(thisChar == strlen(quote)){
      //thisChar is at the end of the string so reset back to beginning
      thisChar = 0;
    }
  }
}