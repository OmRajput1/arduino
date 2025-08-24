The obstacle avoider robot uses an arduino, motor driver, 2 motors and a caster wheel with 2 ultrasonic sensors at the front like eyes

PARTS USED -

Arduino Uno
Motor driver (L298N)
Ultrasonic sensors (HC-SR04 ×2)
DC motors ×2
Caster wheel ×1
Chassis
Battery (x2 8V)
Jumper wires, breadboard
Switch

The pins connected are mentioned in the first few lines of the program

WORKING -

Checks the dist on both sides using the right and left ultrasonic sensor.
IF both the sensor detect the distance to be more than 20cm then it moves FORWARD
IF the right sensor detects more the 20cm and left sensor detects less than 20cm it turns LEFT
IF the LEFT sensor detects more than 20cm and RIGHT sensors detects MORE than 20cm it turns right
IF both the sensors detect less than 20cm it moves BACKWARD
Process repeats in a LOOP
