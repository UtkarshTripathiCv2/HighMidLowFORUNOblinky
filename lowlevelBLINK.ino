void setup() {
  // 0x24 is the physical address of DDRB
  // We cast it to a pointer so we can write to it
  *(volatile uint8_t*)0x24 = 32;  // 32 is binary 00100000
}

void loop() {
  // 0x25 is the physical address of PORTB
  *(volatile uint8_t*)0x25 = 32;  // Turn ON
  delay(500);
  
  *(volatile uint8_t*)0x25 = 0;   // Turn OFF
  delay(500);
}
