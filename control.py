# Send strings to a serial device

import serial

port = serial.Serial("/dev/ttyACM0")

while True:
    print("Number? ")

    number = raw_input()

    port.write(number)
