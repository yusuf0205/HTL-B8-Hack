# HTL-B8 Washing Machine Board Hack 🛠️⚡
by H Mohammed yusuf

Reverse engineering and custom Arduino driver for a scrapped **HTL-B8 Washing Machine Control Panel** (powered by **TM1628**).

![Board Image](diagrams/board_photo.jpg)

## 📖 The Story
I found this control board in a junk shop and decided to bring it back to life. Without any datasheet or manual, I reverse-engineered the PCB traces, decoded the scrambled 7-segment display mapping, and wrote this custom library to control it using an Arduino.

## ⚙️ Hardware Details
* **Board Model:** HTL-B8 (Date: 2012-08-10)
* **Driver Chip:** TM1628 (SOP28)
* **Display:** 4-Digit 7-Segment Display (Common Anode/Cathode Scrambled)
* **Input:** 5V DC

## 🔌 Pinout & Wiring
Connecting the HTL-B8 board to Arduino:

| Board Pin (White Connector) | Arduino Pin (Default) | Function |
| :--- | :--- | :--- |
| **Pin 2** | **GND** | Ground |
| **Pin 3** | **5V** | VCC |
| **Pin 4** | **D4** | STB (Strobe) |
| **Pin 5** | **D5** | CLK (Clock) |
| **Pin 6** | **D6** | DIO (Data) |

*(Note: Pins 1, 7, 8 are not used for the display)*

## 🚀 How to Use
1.  Download the `HTL_B8.h` file from the `library` folder.
2.  Place it in your sketch folder.
3.  Include it in your code:

```cpp
#include "HTL_B8.h"

// Initialize with pins: DIO, CLK, STB
HTLB8 myBoard(6, 5, 4);

void setup() {
  myBoard.begin();
  myBoard.clear();
}

void loop() {
  myBoard.showNumber(1234); // Displays "1234"
  delay(1000);
}

🧠 Reverse Engineering Notes
The board uses a non-standard mapping for the 7-segment display.

Grid Mapping:

Pos 3, 4, 5, 6 -> 7-Segment Digits

Pos 0, 1, 2 -> LED Indicators

Segment Mapping:

I brute-forced the segment values to find the correct numbers.

0 = 235, 1 = 136, 2 = 230 ... (See HTL_B8.h for full map).

⚠️ Known Limitations
Buttons: The buttons on this board use a separate dedicated chip (possibly capacitive touch via springs) and are not directly accessible via the TM1628 data lines. This library currently supports Display Output Only.

📜 License
This project is open-source under the MIT License. Feel free to use it, modify it, and hack more junk!

Reverse Engineered with ❤️ by @yusufiwho (H Mohammed Yusuf)