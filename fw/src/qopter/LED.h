#ifndef QOPTER_LED_H
#define QOPTER_LED_H

namespace qopter {
  class LED {
  public:
    LED(int pin);

    void blink(int ms);
    void panicBlink(int ms);

  private:
    int pin;
  };
}

#endif
