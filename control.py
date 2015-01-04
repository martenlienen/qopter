# Send strings to a serial device

import serial

port = serial.Serial("/dev/ttyUSB1", 57600)

for i in range(255):
    port.write(bytes(i))

while True:
    print("Number? ")

    number = raw_input()

    port.write(number)
