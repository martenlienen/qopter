#include <Arduino.h>

#include "LED.h"

namespace qopter {
  LED::LED(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
  }

  void LED::blink(int ms) {
    digitalWrite(this->pin, HIGH);
    delay(ms / 2);
    digitalWrite(this->pin, LOW);
    delay(ms / 2);
  }

  void LED::panicBlink(int ms) {
    for (int i = 0; i < ms; i += 100) {
      this->blink(100);
    }
  }
}
