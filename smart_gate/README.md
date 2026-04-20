# Smart Gate System (Arduino Uno)

An automated gate system built with Arduino Uno that detects nearby objects using an ultrasonic sensor and controls a servo motor to open and close a gate. The open duration is adjustable via a potentiometer and displayed in seconds on a 7-segment display.

---

## Features

*  Object detection using ultrasonic sensor
*  Automatic gate opening and closing
*  Adjustable delay time (in seconds)
*  Real-time display on 7-segment display
*  Simple, low-cost hardware setup

---

## Components

* Arduino Uno
* Ultrasonic Sensor (HC-SR04)
* Servo Motor (SG90 or similar)
* Potentiometer (10kΩ)
* 7-Segment Display
* Resistors
* Breadboard & jumper wires
* Power supply

---

## How It Works

* The ultrasonic sensor detects objects within a set distance.
* When triggered, the servo motor opens the gate.
* The potentiometer controls how long the gate stays open.
* The selected delay is shown on the 7-segment display.
* After the delay, the gate automatically closes.

---

## Getting Started

1. Assemble the hardware components
2. Upload the Arduino sketch
3. Power the system
4. Adjust delay using the potentiometer
5. Test by placing an object near the sensor

---

## Future Improvements

* Add LCD/OLED display for better readability
* Integrate Bluetooth or Wi-Fi control
* Add security features (RFID, keypad)
* Improve enclosure/design for real-world use

---


