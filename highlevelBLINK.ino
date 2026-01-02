void setup() {
  pinMode(13, OUTPUT);    // Abstraction checks which register controls pin 13
}

void loop() {
  digitalWrite(13, HIGH); // Abstraction sets the bit to 1
  delay(500);
  digitalWrite(13, LOW);  // Abstraction sets the bit to 0
  delay(500);
}
