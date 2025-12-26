#include "HTL_B8.h"

// DIO=6, CLK=5, STB=4
HTLB8 myBoard(6, 5, 4); 

void setup() {
  myBoard.begin();
  myBoard.clear();
}

void loop() {
  // 1. Read the button status
  byte keys = myBoard.readButtons();

  // 2. If a button is pressed (keys > 0), show the value!
  if (keys != 0) {
    myBoard.showNumber(keys);
  } else {
    // Optional: Clear or show 0 when nothing is pressed
    // myBoard.showNumber(0); 
  }
  
  delay(100); // Small delay to avoid flickering
}