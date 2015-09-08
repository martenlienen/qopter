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
    int speed;
    int targetSpeed;
    int pin;
    Servo servo;
  };
}
