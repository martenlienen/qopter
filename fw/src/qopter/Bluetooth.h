#ifndef QOPTER_BLUETOOTH_H
#define QOPTER_BLUETOOTH_H

#include <SoftwareSerial.h>

namespace qopter {
  class Bluetooth {
  public:
    Bluetooth(SoftwareSerial& serial);

    bool commandMode();
    void exitCommandMode();
    bool baudRate(const char* rate);

  private:
    static const int TIMEOUT;

    SoftwareSerial& serial;

    bool ensureResponse(const char* expected, int ms);
  };
}

#endif
