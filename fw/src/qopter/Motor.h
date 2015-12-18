#ifndef QOPTER_MOTOR_H
#define QOPTER_MOTOR_H

#include <Servo.h>

namespace qopter {
  class Motor {
  public:
    Motor(int pin);

    void attach();

    void initialize();

    void loop();

    void setSpeed(int speed);

  private:
    int pin;
    int speed;
    int targetSpeed;
    Servo servo;
  };
}

#endif
