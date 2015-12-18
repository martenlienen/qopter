#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#include "qopter/Bluetooth.h"
#include "qopter/LED.h"

#define SECOND 1000

// The built-in LED
qopter::LED led(13);

SoftwareSerial serial(2, 3);
qopter::Bluetooth bt(serial);

bool initialized = false;

bool setupBluetooth() {
  serial.begin(115200);

  delay(100);

  if (bt.commandMode()) {
    delay(100);

    // Reduce baud rate, because SoftwareSerial cannot keep up with the default
    // of 115200 kbps.
    if (!bt.baudRate("9600")) {
      Serial.println("Could not reduce the baud rate");
      led.panicBlink(SECOND);
      return false;
    }

    // From here on we can communicate at a rate of 9600 kbps
    serial.begin(9600);

    delay(100);

    if (!bt.commandMode()) {
      Serial.println("Could not enter command mode at low baud rate");
      led.panicBlink(SECOND);
      return false;
    }
  } else {
    // This is a valid assumption, because it happens every time in development,
    // when you just redeploy the application without restarting the arduino.
    Serial.println("Could not enter command mode at high baud rate");
    Serial.println("Assuming that BT chip already runs at 9600 kbps");
    Serial.println("and is in command mode");
  }

  return true;
}

void serialToBluetooth() {
  char buffer[1000];
  int n = 0;

  while (Serial.available() && n < 1000) {
    buffer[n] = (char)Serial.read();

    n++;
  }

  if (n > 0) {
    serial.write(buffer, n);
    serial.flush();
  }

  n = 0;

  while (serial.available() && n < 1000) {
    buffer[n] = (char)serial.read();

    n++;
  }

  if (n > 0) {
    for (int i = 0; i < n; i++) {
      Serial.write(buffer[i]);
      Serial.flush();
    }
  }
}

void setup() {
  // Initialize serial communication via cable
  Serial.begin(9600);

  // TODO: FACTORY RESET GPIO4

  if (setupBluetooth()) {
    initialized = true;
  } else {
    Serial.println("Could not set up bluetooth");
  }
}

void loop() {
  if (!initialized) {
    led.panicBlink(SECOND);
    return;
  }

  serialToBluetooth();
}
