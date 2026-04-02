# ⚡ Arduino Projects Portfolio

A collection of beginner-to-intermediate Arduino projects exploring LEDs,
buttons, sensors, servos, and OLED displays.

---

## 📁 Projects

### 🔢 7SegmentDisplay
Controls a 7-segment display to show numbers and characters. Introduces
multiplexing pins and segment mapping to render digits using `digitalWrite()`.

### 💡 BlinkLED
The classic Arduino starter project. Blinks an LED on and off at a set interval
using `digitalWrite()` and `delay()`.

### 🔘 ButtonOnOff
Uses a push button to toggle an LED on and off. Introduces digital input reading
and basic control flow.

### 🌅 FadeLED
Fades an LED in and out smoothly using PWM via `analogWrite()`.
Demonstrates pulse-width modulation for brightness control.

### 🕹️ JoystickOLED
Reads X/Y axis values from an analog joystick and displays the coordinates live
on an OLED screen. Uses `analogRead()` and I2C display output.

### ⌨️ KeypadOLED
Reads key presses from a matrix keypad and displays the input on an OLED screen.
Great introduction to matrix scanning and real-time display updates.

### 🚶 MotionSensorOLED
Detects motion using a PIR sensor and displays the status (motion detected /
clear) on an OLED screen. Combines digital input with I2C display output.

### 🌈 RGBLED
Controls an RGB LED to produce different colors by mixing red, green, and blue
values using PWM. Great intro to color mixing and multi-pin control.

### ⚙️ Servo
Controls a servo motor to sweep or move to specific angles using the
`Servo.h` library. Demonstrates PWM-based motor control.

### 🕹️⚙️ ServoJoystick
Combines a joystick and a servo motor — joystick input controls the servo's
position in real time. A hands-on intro to analog input driving mechanical output.

### 🚦 TrafficLight
Simulates a traffic light sequence (red → green → yellow) using multiple LEDs
and timed delays. A fun real-world logic simulation.

### 📡 UltraSonicSensorOLED
Measures distance using an HC-SR04 ultrasonic sensor and displays the reading
live on an OLED screen. Uses `pulseIn()` for echo timing.

---

## 🛠️ Common Components

- Arduino Uno / Nano
- LEDs (red, green, yellow, RGB)
- 7-segment display
- Push button
- Analog joystick module
- 4x4 matrix keypad
- PIR motion sensor
- HC-SR04 ultrasonic sensor
- SG90 servo motor
- SSD1306 OLED display (I2C)
- Resistors, breadboard, jumper wires

---

## ⚙️ Setup

1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Clone this repo:
   ```
   git clone https://github.com/your-username/ArduinoProject.git
   ```
3. Open any project's `.ino` file in Arduino IDE
4. Install required libraries via **Sketch > Include Library > Manage Libraries**:
   - **Adafruit SSD1306** — for all OLED projects
   - **Adafruit GFX** — required by SSD1306
   - **Adafruit Keypad** — for KeypadOLED
   - **Servo** — built-in, for Servo & ServoJoystick
5. Select your board & port, then hit **Upload**
