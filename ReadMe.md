### Motor with 3 relays and 2 buttons

Test use of three relays for turning on and 
controlling polarity of power to a DC motor

Also have two buttons
- one controls power to motor: when pressed, motor turns
- other is a "toggle" switch: each time it's pressed, the motor direction is changed

For the relays, I'm using a
[Sainsmart 8 relay module](http://www.sainsmart.com/8-channel-dc-5v-relay-module-for-arduino-pic-arm-dsp-avr-msp430-ttl-logic.html)
which I got at
[amazon](http://www.amazon.com/exec/obidos/ASIN/B0057OC5WK/7210-20).

The first two relays are both triggered by a common Arduino pin.
Their common pins (middle) are each attached to one side of the motor.
For the other two pins, relay 1 has red (9v) attached to first pin (on
left) and black (ground) attached to third pin (on right). Relay 2 is
the opposite: the first pin (on left) is attached to ground and the
third pin (on right) is attached to 9v. In this one, in one state, the
motor has its left wire to 9v and right to ground, and in the other
state the opposite (left to ground and right to 9v). This achieves the
switching of direction, via the switching of polarity of power.

The 3rd relay turns the motor on or off. the common pin is attached to
a 9v battery and the first pin (on left) is attached to what will be
9v on relays 1 and 2.
