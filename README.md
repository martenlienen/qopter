# Selfmade quadrocopter

## Motors

The arming sequence is:
- Send angle of 40
- Connect to battery
- *Beeep*

After that you can control the motor speed with PWM. The min and max speeds are
55 and 160.

## Radio

You have to operate the radio transmitters at a baud rate of 57600.

You have to connect the RX of the arduino to the TX of the radio transmitter and
vice versa.
