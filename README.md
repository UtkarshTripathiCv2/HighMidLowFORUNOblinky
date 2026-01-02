Markdown

# Arduino Blink: From Abstraction to Bare Metal

This repository demonstrates the classic "Blink" program implemented at three distinct levels of abstraction on the ATmega328P (Arduino Uno). 

The goal is to visualize the trade-offs between **code readability**, **portability**, and **hardware efficiency** (execution speed and memory size).

## 📂 Project Structure

1.  **Level 1 - Standard:** Uses Arduino High-Level APIs (`digitalWrite`).
2.  **Level 2 - Register Macros:** Uses C bitwise operations on Register names (`PORTB`, `DDRB`).
3.  **Level 3 - Raw Pointers:** Direct memory manipulation using hexadecimal addresses (`0x25`).

---

## 🛠 Hardware Requirements
* **Microcontroller:** ATmega328P (Arduino Uno, Nano, or standalone chip).
* **Pin:** Digital Pin 13 (Port B, Bit 5).

> **Note:** The register addresses used in Level 3 (`0x24`, `0x25`) are specific to the ATmega328P architecture. These will not work on ESP32, STM32, or ATmega2560 without modification.

---

## 📊 Technical Comparison

| Metric | Level 1: Standard API | Level 2: Register Macros | Level 3: Raw Pointers |
| :--- | :--- | :--- | :--- |
| **Syntax** | `digitalWrite(13, HIGH)` | `PORTB \|= (1<<5)` | `*(volatile uint8_t*)0x25 = 32` |
| **Compiled Size** | ~924 Bytes | ~178 Bytes | ~178 Bytes |
| **Execution Speed** | ~4 - 5 µs (Slow) | ~0.125 µs (Fast) | ~0.125 µs (Fast) |
| **Readability** | High | Medium | Low |
| **Portability** | High (Any Board) | Medium (AVR Family) | None (Specific Chip Only) |

---

## 📝 Code Breakdown

### 1. High-Level (Standard Arduino)
The abstraction layer. Easy to read and portable, but carries significant overhead due to safety checks (checking if the pin exists, disabling PWM timers, etc.).

```cpp
void loop() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW); 
  delay(500);
}
2. Mid-Level (Register Macros)
The industry standard for embedded firmware. We manipulate the DDRB (Data Direction) and PORTB (Output Data) registers directly using bitwise operators.

C++

void setup() {
  DDRB |= (1 << 5); // Set PB5 as Output
}

void loop() {
  PORTB |= (1 << 5);  // Set PB5 HIGH
  delay(500);
  PORTB &= ~(1 << 5); // Set PB5 LOW
  delay(500);
}
3. Low-Level (Raw Pointers)
"Bare metal" programming. We bypass the compiler's named definitions and write directly to the physical memory addresses of the hardware registers.

0x24: Address of DDRB

0x25: Address of PORTB

C++

void setup() {
  *(volatile uint8_t*)0x24 = 32; // Binary 00100000
}

void loop() {
  *(volatile uint8_t*)0x25 = 32; // Turn ON
  delay(500);
  *(volatile uint8_t*)0x25 = 0;  // Turn OFF
  delay(500);
}
🚀 How to Run
Open any of the .ino files in the Arduino IDE.

Select your board (Arduino Uno).

Upload the code.

Observe the built-in LED (L) on the board.

👤 Author
Utkarsh Tripathi Embedded Systems & Computer Vision Enthusiast
