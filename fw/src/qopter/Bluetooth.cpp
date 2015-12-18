#include <Arduino.h>

#include "Bluetooth.h"

namespace qopter {
  const int Bluetooth::TIMEOUT = 100;

  Bluetooth::Bluetooth(SoftwareSerial& serial) : serial(serial) {
  }

  bool Bluetooth::commandMode() {
    this->serial.print("$$$");

    return this->ensureResponse("CMD\r\n", Bluetooth::TIMEOUT);
  }

  void Bluetooth::exitCommandMode() {
    this->serial.print("---\r\n");
  }

  bool Bluetooth::baudRate(const char* rate) {
    this->serial.print("U,");
    this->serial.print(rate);
    this->serial.print(",N\r\n");

    return this->ensureResponse("AOK\r\n", Bluetooth::TIMEOUT);
  }

  bool Bluetooth::ensureResponse(const char* expected, int ms) {
    unsigned long end = millis() + ms;
    int next = 0;

    while (expected[next] != '\0') {
      if (millis() >= end) {
        return false;
      }

      if (this->serial.available()) {
        int byte = this->serial.read();

        if (byte != -1) {
          if (byte == expected[next]) {
            next++;
          } else {
            return false;
          }
        }
      }
    }

    return true;
  }
}
