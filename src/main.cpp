#include <Arduino.h>
#include <SoftwareSerial.h>

#include "mavlink/cqql/mavlink.h"

#include "qopter/Motor.h"

int pin = 10;
qopter::Motor motor(pin);

SoftwareSerial radio(10, 11);

void setup () {
  //motor.initialize();

  Serial.begin(9600);

  // LED
  pinMode(13, OUTPUT);

  // Radio Pins
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);

  radio.begin(57600);
  //radio.begin(9600);

  radio.listen();
}

void send_message(uint32_t duration) {
  mavlink_message_t msg;

  uint16_t length = mavlink_msg_led_pack(20, 200, &msg, duration);

  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  mavlink_msg_to_send_buffer(buf, &msg);

  radio.write(buf, length);
}

uint8_t i = 0;

void loop () {
  // if (Serial.available()) {
  //   motor.setSpeed(Serial.parseInt());
  // }

  //motor.loop();

  send_message(i);

  // uint8_t bytes = 0;

  mavlink_message_t msg;
  mavlink_status_t status;
  uint32_t duration = 0;

  // while (radio.available() > 0) {
  // //   bytes++;

  //   uint8_t c = radio.read();

  //   if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
  //     if (msg.msgid == MAVLINK_MSG_ID_LED) {
  //       duration = mavlink_msg_led_get_duration(&msg);

  //       if (duration == i) {
  //         i++;
  //       }
  //     }
  //   }
  // }
  i++;

  delay(5);

  // if (bytes > 0) {
  //   char log[100];
  //   snprintf(log, 100, "bytes %d, num_rec %d, num_err %d, seq %d, succ %d, drop %d, duration %d", bytes, status.msg_received, status.parse_error, status.current_rx_seq, status.packet_rx_success_count, status.packet_rx_drop_count, duration);
  //   Serial.println(log);
  // }
}
