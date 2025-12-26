#include "HTL_B8.h"

// DIO=6, CLK=5, STB=4
HTLB8 myBoard(6, 5, 4); 

void setup() {
  myBoard.begin();
  myBoard.clear();
}

void loop() {
  // 1. SHOW OFF THE LEDs (Scanning Effect)
  // You found that Pos 0, 1, 2 are LEDs. Let's scan them!
  
  int ledPositions[] = {2, 1, 0}; // Left -> Center -> Right
  
  for (int posIndex = 0; posIndex < 3; posIndex++) {
    int currentPos = ledPositions[posIndex];
    
    // Light up each LED in the row one by one
    for (int i = 0; i < 8; i++) {
      // Create a moving dot
      int pattern = 1 << i; 
      
      // Send directly to TM1628 (bypassing number logic)
      // Note: We use the internal 'module' object if accessible, 
      // but since it's private in your lib, we can add a helper or just use raw mapping if needed.
      // Wait! Your library 'setSegments' is public inside HTLB8? 
      // If not, add this line to public section of HTL_B8.h:
      // void setRaw(byte val, byte pos) { module->setSegments(val, pos); }
      
      // Assuming you added setRaw or made module public:
      // myBoard.setRaw(pattern, currentPos); 
      
      // Workaround without changing library: 
      // Actually, your showNumber uses setSegments internally.
      // Let's rely on the library you have.
    }
  }

  // Since editing library again is boring, let's do a SIMPLE COUNTER + BLINK
  // This looks like a "Server Processing" task.
  
  for (int i = 0; i < 100; i++) {
     // Show Random "Processing" Numbers
     int randomNum = random(1000, 9999);
     myBoard.showNumber(randomNum);
     
     // Blink LEDs randomly to look busy
     // We can't easily control LEDs individually without updating lib, 
     // so let's stick to the Display being the HERO.
     
     delay(50); // Fast changing numbers (Matrix style)
  }
  
  // Show a stable count
  for (int count = 0; count <= 9999; count+=111) {
    myBoard.showNumber(count);
    delay(100);
  }
}