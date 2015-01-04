#include <Arduino.h>
#include <SoftwareSerial.h>

#include "qopter/Motor.h"

int pin = 10;
qopter::Motor motor(pin);

SoftwareSerial radio(10, 11);

void setup () {
  //motor.initialize();

  pinMode(10, INPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
  radio.begin(57600);

  radio.listen();
}

void loop () {
  // if (Serial.available()) {
  //   motor.setSpeed(Serial.parseInt());
  // }

  //motor.loop();

  while (radio.available()) {
    int x = radio.read();

    radio.print(x);
    radio.println();
  }

  // for (int i = 0; i <= 255; i++) {
  //   Serial.write(i);
  //   radio.write(i);
  // }

  delay(200);
}
