# Send strings to a serial device

import numpy
import time
import serial
import mavlink

def send_mav():
    for i in range(10):
        mav.led_send((1 + i % 2) * 400)

        print(i)

        time.sleep(1)

def print_hist(h):
    s = float(max(h))

    for i in range(256):
        print("%3d %s" % (i, "-" * int(30.0 * (h[i] / s))))

    print("Min: %d, Mean: %f, Max: %d" % (min(h), numpy.mean(h), max(h)))

port = serial.Serial("/dev/ttyUSB0", 57600)
#port = serial.Serial("/dev/ttyACM0", 9600)
#port = serial.Serial("/dev/ttyUSB0", 9600)
mav = mavlink.MAVLink(port)

ds = []

try:
    while True:
        c = port.read()
        m = None

        try:
            m = mav.parse_char(c)
        except mavlink.MAVError as e:
            print("Error: %s" % e.message)

        if m:
            print(m)

            ds.append(m.duration)
except KeyboardInterrupt:
    hist, bins = numpy.histogram(ds, bins=range(257))

    print_hist(hist)
