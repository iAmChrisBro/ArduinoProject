# ⚡ Arduino Projects Portfolio

A collection of beginner-to-intermediate Arduino projects exploring LEDs,
buttons, sensors, and OLED displays.

---

## 📁 Projects

### 💡 BlinkLED
The classic Arduino starter project. Blinks an LED on and off at a set interval
using `digitalWrite()` and `delay()`.

### 🔘 ButtonOnOff
Uses a push button to toggle an LED on and off. Introduces digital input reading
and basic control flow.

### 🌅 FadeLED
Fades an LED in and out smoothly using PWM via `analogWrite()`.
Demonstrates pulse-width modulation for brightness control.

### 🚶 MotionSensorOLED
Detects motion using a PIR sensor and displays the status (motion detected /
clear) on an OLED screen. Combines digital input with I2C display output.

### 🌈 RGBLED
Controls an RGB LED to produce different colors by mixing red, green, and blue
values using PWM. Great intro to color mixing and multi-pin control.

### 🚦 TrafficLight
Simulates a traffic light sequence (red → green → yellow) using multiple LEDs
and timed delays. A fun real-world logic simulation.

### 📡 UltraSonicSensorOLED
Measures distance using an HC-SR04 ultrasonic sensor and displays the reading
live on an OLED screen. Uses `pulseIn()` for echo timing.

---

## 🛠️ Common Components

- Arduino Uno
- LEDs (red, green, yellow, RGB)
- Push button
- PIR motion sensor
- HC-SR04 ultrasonic sensor
- SSD1306 OLED display (I2C)
- Resistors, breadboard, jumper wires

---

## ⚙️ Setup

1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Clone this repo:
