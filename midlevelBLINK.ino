void setup() {
  // DDRB is the name for address 0x24
  // We use bitwise OR (|=) to turn ON bit 5 without changing bits 0-4
  DDRB |= (1 << 5);       // Set PB5 (Pin 13) to Output
}

void loop() {
  // PORTB is the name for address 0x25
  PORTB |= (1 << 5);      // Set PB5 HIGH (Turn LED ON)
  delay(500);
  
  // We use bitwise AND (&) with NOT (~) to turn OFF only bit 5
  PORTB &= ~(1 << 5);     // Set PB5 LOW (Turn LED OFF)
  delay(500);
}
