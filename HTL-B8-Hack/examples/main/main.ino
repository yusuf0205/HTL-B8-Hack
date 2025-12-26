#include "HTL_B8.h"

// DIO=6, CLK=5, STB=4
HTLB8 myBoard(6, 5, 4); 

void setup() {
  Serial.begin(9600);
  myBoard.begin();
  myBoard.clear();
  myBoard.showNumber(0000); // Start with 0000
}

void loop() {
  // 1. Read the button status
  byte keys = myBoard.readButtons();

  // 2. If a button is pressed, show its code!
  if (keys != 0) {
    Serial.print("Button Pressed Code: ");
    Serial.println(keys);
    
    myBoard.showNumber(keys); // Display the button code on the 7-segment
  } 
  
  delay(100); // Small delay
}