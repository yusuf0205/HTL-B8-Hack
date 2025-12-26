// PIN CONFIGURATION
const int strobe = 4;
const int clock = 5;
const int data = 6;

void setup() {
  pinMode(strobe, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);

  Serial.begin(9600);
  Serial.println("--- BUTTON RAW TEST ---");
  
  // Turn on display just to be sure power is OK
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0x8F); // Display ON
  digitalWrite(strobe, HIGH);
}

void loop() {
  uint8_t buttons[4]; // TM1628 returns 4 bytes of key data

  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0x42); // Command: READ KEYS

  // Now we need to switch DIO pin to INPUT mode to "Listen"
  pinMode(data, INPUT); 
  
  // Read 4 bytes manually
  for (int i = 0; i < 4; i++) {
    buttons[i] = shiftIn(data, clock, LSBFIRST);
  }

  // Switch DIO back to OUTPUT mode for next loop
  pinMode(data, OUTPUT); 
  digitalWrite(strobe, HIGH);

  // Print results
  // If ALL are 0, then connection issue or no press.
  // If numbers change when you press, WE WON!
  Serial.print("Data: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(buttons[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  delay(200); // Fast update
}