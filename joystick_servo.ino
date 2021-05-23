/**************************************************************************************************************
 * 
 * Author:    Aly Khan Nuruddin
 * Date:      May 15, 2021
 * Purpose:   This program permits the user to toggle the angle of rotation of two servo motors between 10 and 
 *            170 degrees, by actuating the motion of an analog joystick on the horizontal and vertical axes.
 *            
 **************************************************************************************************************/
         
#include <Servo.h>                                // Enable communication between the microcontroller and the servo motors.

Servo myServo1;                                   // Define an object that actuates the rotation of the first servo motor.             
Servo myServo2;                                   // Define an object that actuates the rotation of the second servo motor.

int servo1 = 3;                                   // Define the Digital PWM Input Pin connection for the first servo motor.
int servo2 = 5;                                   // Define the Digital PWM Input Pin connection for the second servo motor.

int joystickX = A0;                               // Define the Analog Input Pin connection for the x-axis of the analog joystick.
int joystickY = A1;                               // Define the Analog Input Pin connection for the y-axis of the analog joystick.

void setup(){
  myServo1.attach(servo1);                        // Establish a connection between the object and the first servo motor.
  myServo2.attach(servo2);                        // Establish a connection between the object and the second servo motor.
}

void loop(){
  
  int xPosition = analogRead(joystickX);          // Read the position of the x-coordinate on the analog joystick.
  int yPosition = analogRead(joystickY);          // Read the position of the y-coordinate on the analog joystick.

  xPosition = map(xPosition, 0, 1023, 10, 170);   // Scale the value of the x-coordinate to allow for servo motor functionality.
  yPosition = map(yPosition, 0, 1023, 10, 170);   // Scale the value of the y-coordinate to allow for servo motor functionality.

  myServo1.write(xPosition);                      // Set the servo motor position using the scaled value of the x-coordinate.
  myServo2.write(yPosition);                      // Set the servo motor position using the scaled value of the y-coordinate.

  delay(5);                                       // Delay the process of toggling the servo motor position by 5 milliseconds.
}
