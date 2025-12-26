/*
  HTL-B8 Washing Machine Board Library
  Reverse Engineered by: [H Mohammed Yusuf]
  Date: 2025-12-24
*/

#ifndef HTL_B8_H
#define HTL_B8_H

#include <TM1638.h>

class HTLB8 {
  private:
    TM1638* module; // Pointer to the TM1638 object
    
    // The Magic Map you discovered!
    const byte digitMap[10] = {235, 136, 230, 174, 141, 47, 111, 138, 239, 175};

  public:
    // Constructor: Takes the pins (DIO, CLK, STB)
    HTLB8(byte dio, byte clk, byte stb) {
      module = new TM1638(dio, clk, stb);
    }

    // Initialize the board
    void begin() {
      module->setupDisplay(true, 7); // Max brightness
    }

    // Function to show Number (0 to 9999)
    void showNumber(int value) {
      // Limit to 9999
      if (value > 9999) value = 9999;
      
      // Extract digits
      int th = (value / 1000) % 10;
      int hu = (value / 100) % 10;
      int te = (value / 10) % 10;
      int un = value % 10;

      // Map to positions 3, 4, 5, 6 (Based on your finding)
      module->setSegments(digitMap[th], 3);
      module->setSegments(digitMap[hu], 4);
      module->setSegments(digitMap[te], 5);
      module->setSegments(digitMap[un], 6);
    }

    // Function to control individual LEDs (The Rows 0, 1, 2)
    // row: 0 (Right), 1 (Center), 2 (Left)
    // bit: 0-7 (Which LED in that row)
    void setLed(int row, int bit, bool state) {
       // Logic to turn on/off specific bit... 
       // For now, let's keep it simple or expand later based on need.
       // This uses raw TM1638 commands if needed.
    }
    
    // Clear display
    void clear() {
      module->clearDisplay();
    }
};

#endif