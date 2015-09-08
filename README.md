# Selfmade quadrocopter

## Installation

```sh
# Create a virtual environment
pyenv virtualenv qopter

# Activate the environment
pyenv local qopter

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

## BlueTooth

We use QGroundControl as a GCS and communicate with our qopter via MAVLink over
BlueTooth. To create a BT connection in QGC, use a python script to create a
serial device, that is a proxy for a BT connection, and connect to that.

## Rotor Configuration

- *1* and *3* clockwise
- *2* and *4* counterclockwise

## Peculiarities

Rotor *3* stops rotation after a short while at the lowest possible angle of
`55`. An angle of `60` keeps all rotors running consistently.
