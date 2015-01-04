#include "Motor.h"

namespace qopter {
  Motor::Motor(int pin) : pin(pin), speed(40), targetSpeed(40) {

  }

  void Motor::attach() {
    this->servo.attach(this->pin);
  }

  void Motor::initialize() {
    this->attach();
    this->servo.write(this->speed);
  }

  void Motor::loop() {
    if (this->speed != this->targetSpeed) {
      if (this->speed > this->targetSpeed) {
        this->speed--;
      } else {
        this->speed++;
      }

      this->servo.write(speed);
    }
  }

  void Motor::setSpeed(int speed) {
    this->targetSpeed = speed;
  }
}
