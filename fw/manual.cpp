#include <Arduino.h>
#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

int speed = 40;
int newSpeed = speed;

void setup () {
  Serial.begin(9600);

  motor1.attach(3);
  motor2.attach(5);
  motor3.attach(6);
  motor4.attach(9);

  delay(10);

  motor1.write(speed);
  motor2.write(speed);
  motor3.write(speed);
  motor4.write(speed);

  delay(1000);
}

void loop () {
  if (Serial.available()) {
    newSpeed = Serial.parseInt();
    Serial.println("available");

    while (Serial.available()) {
      Serial.read();
    }
  }

  if (newSpeed != speed) {
    if (newSpeed > speed) {
      speed++;
    } else if (newSpeed < speed) {
      speed--;
    }

    Serial.println(speed);

    motor1.write(speed);
    motor2.write(speed);
    motor3.write(speed);
    motor4.write(speed);
  }

  delay(10);
}
