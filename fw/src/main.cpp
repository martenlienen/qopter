#include <Arduino.h>
#include <Servo.h>

Servo motor;
int pin = 10;

int speed = 40;
int newSpeed = speed;

void setup () {
  Serial.begin(9600);

  motor.attach(pin);

  delay(10);

  motor.write(speed);

  delay(1000);
}

void loop () {
  if (Serial.available()) {
    newSpeed = Serial.parseInt();
  }

  if (newSpeed != speed) {
    if (newSpeed > speed) {
      speed++;
    } else if (newSpeed < speed) {
      speed--;
    }

    Serial.println(speed);

    motor.write(speed);
  }

  delay(10);
}
