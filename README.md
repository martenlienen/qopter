# Selfmade quadrocopter

## Installation

```sh
# Create a virtualenv
virtualenv qopter.env

# Activate the environment
. qopter.env/bin/activate

# Install the python dependencies
pip install -r requirements.txt

# Now use platformio to deploy to an arduino
platformio install
```

## Motors

The arming sequence is:
- Send angle of 40
- Connect to battery
- *Beeep*

After that you can control the motor speed with PWM. The min and max speeds are
55 and 130.

## Radio

You have to operate the radio transmitters at a baud rate of 57600.

You have to connect the RX of the arduino to the TX of the radio transmitter and
vice versa.

## Rotor Configuration

- *1* and *3* clockwise
- *2* and *4* counterclockwise

## Peculiarities

Rotor *3* stops rotation after a short while at the lowest possible angle of
`55`. An angle of `60` keeps all rotors running consistently.
