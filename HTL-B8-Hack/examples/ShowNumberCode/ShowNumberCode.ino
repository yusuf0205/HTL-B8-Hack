#include <TM1638.h>

// Pins: DIO=6, CLK=5, STB=4
TM1638 module(6, 5, 4);

// YOUR MAPPED NUMBERS (0-9)
// 0=235, 1=136, 2=230, 3=174, 4=141, 5=47, 6=111, 7=138, 8=239, 9=175
const byte digitMap[] = {235, 136, 230, 174, 141, 47, 111, 138, 239, 175};

void setup() {
  module.setupDisplay(true, 7); // Wake up, Max Brightness
  Serial.begin(9600);
}

// FUNCTION TO SHOW ANY NUMBER
void showNumber(int value) {
  // Break the number into 4 digits
  int th = (value / 1000) % 10; // Thousands
  int hu = (value / 100) % 10;  // Hundreds
  int te = (value / 10) % 10;   // Tens
  int un = value % 10;          // Units

  // Map to your nPos (3, 4, 5, 6)
  // Assuming 3=Leftmost, 6=Rightmost based on your loop
  module.setSegments(digitMap[th], 3);
  module.setSegments(digitMap[hu], 4);
  module.setSegments(digitMap[te], 5);
  module.setSegments(digitMap[un], 6);
}

void loop() {
  // showNumber(1234);
  // delay(1000);
  showNumber(1111);
}