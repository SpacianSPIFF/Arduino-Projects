# 8x8 LED Matrix Space Shooter Game

### Objective: Shoot the aliens, move the spaceship, and try to survive the longest! Don't let the aliens come too close to you!

### Setup and Controls:

1. Joystick
   - Setup
     - Connect Joystick's Y axis pin to analog pin **A0** of Arduino
     - Connect Joystick's K pin to digital pin **4** of Arduino
   - Controls
     - Move joystick left or right to move the spaceship accordingly
     - Click the joystick's button to fire the bullet
2. Button
   - Setup
     - Connect a button to digital pin **7** of the Arduino, and it will be the left button
     - Connect a button to digital pin **6** of the Arduino, and it will be the right button
     - Connect a button to digital pin **5** of the Arduino, and it will be the fire button
   - Controls
     - Press the left button to move the spaceship left
     - Press the right button to move the spaceship right
     - Press the fire button fire the bullet
3. Serial Monitor (Serial Port Communication)
   - Setup
     - Connect to the Arduino using serial monitor(recommended) or through any script/application which allows serial communication and can send strings
   - Commands
     - Left - Moves the spaceship left
     - Right - Moves the spaceship right
     - Fire - Fires the bullet
