ESP8266 Wi-Fi Controlled Robot Car

Developed by Technical BD

A Wi-Fi Controlled Robot Car built using the ESP8266 NodeMCU development board. This project uses a local Wi-Fi Access Point and an HTTP Web Server to control the robot wirelessly from a smartphone or other Wi-Fi-enabled device.

Project Overview

This project allows users to control a robot car wirelessly using an ESP8266-based web server. The ESP8266 creates its own Wi-Fi network, allowing a compatible controller application to send movement and speed commands.

Features

- Wi-Fi Access Point Mode
- Wireless Robot Car Control
- Forward Movement
- Backward Movement
- Left Turn
- Right Turn
- Stop Function
- Adjustable Motor Speed (0–1023)
- Buzzer Horn Function
- HTTP Web Server Communication
- Smartphone-Based Control

Hardware Requirements

Component| Quantity
ESP8266 NodeMCU| 1
L298N Motor Driver| 1
DC Gear Motors| 2 or 4
Robot Car Chassis| 1
Passive Buzzer| 1
Battery Pack| 1
Jumper Wires| As required

Pin Configuration

ESP8266 Pin| Connected Component
D5| Motor Driver IN1
D6| Motor Driver IN2
D7| Motor Driver IN3
D8| Motor Driver IN4
D0| Passive Buzzer

Wi-Fi Configuration

The ESP8266 creates a Wi-Fi Access Point with the following credentials:

- Wi-Fi Name: My_Robot_Car
- Password: 12345678
- IP Address: 192.168.4.1

Connect your smartphone to this Wi-Fi network to communicate with the robot.

Control Commands

Command| Function
F| Move Forward
B| Move Backward
L| Turn Left
R| Turn Right
S| Stop
V| Activate Horn

Speed Control

The motor speed can be adjusted using the "Speed" HTTP parameter.

Supported range: 0–1023.

Example:
"http://192.168.4.1/?Speed=800"

Movement Control Examples

Forward:
"http://192.168.4.1/?State=F"

Backward:
"http://192.168.4.1/?State=B"

Left:
"http://192.168.4.1/?State=L"

Right:
"http://192.168.4.1/?State=R"

Stop:
"http://192.168.4.1/?State=S"

Horn:
"http://192.168.4.1/?State=V"

Required Arduino Libraries

The following libraries are required:

- ESP8266WiFi.h
- ESP8266WebServer.h

These libraries are included with the ESP8266 Arduino Core.

Installation

1. Install Arduino IDE or a compatible ESP8266 development environment.
2. Install the ESP8266 Board Package.
3. Select NodeMCU 1.0 (ESP-12E Module).
4. Open the project source code.
5. Upload the code to your ESP8266.
6. Connect your smartphone to the robot's Wi-Fi network.
7. Use a compatible controller application to send commands.

Working Principle

The ESP8266 operates in Wi-Fi Access Point mode and creates a local wireless network. A smartphone connects to this network and sends HTTP requests containing movement or speed commands.

The ESP8266 processes these commands and controls the L298N motor driver's input pins to move the robot in the desired direction.

Safety Notes

- Use an appropriate external power supply for the motors.
- Ensure the ESP8266 and motor driver share a common GND.
- Do not connect motors directly to ESP8266 GPIO pins.
- Check the motor driver's voltage and current ratings.
- Keep the robot away from water.

Disclaimer

This project is developed for educational, experimental, and robotics learning purposes. Use the robot responsibly and operate it in a safe environment.

Developer

Technical BD

Exploring Electronics, IoT, Robotics, and Embedded Systems.

License

This project is licensed under the MIT License. See the LICENSE file for details.
