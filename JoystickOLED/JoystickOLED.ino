#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const int xPin = A0;
const int yPin = A1;
const int swPin = 8;

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Threshold values — joystick rests around 512
#define THRESHOLD_HIGH 700
#define THRESHOLD_LOW  300

void setup() {
  pinMode(swPin, INPUT_PULLUP);
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oledDisplayCenter("Ready...");
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
  int zVal = digitalRead(swPin);

  // Print to Serial Monitor
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Z: ");
  Serial.println(zVal);

  // Determine direction
  String direction = "";

  if (zVal == LOW) {
    direction = "PRESS";
  } else if (xVal > THRESHOLD_HIGH && yVal > THRESHOLD_LOW && yVal < THRESHOLD_HIGH) {
    direction = "RIGHT";
  } else if (xVal < THRESHOLD_LOW && yVal > THRESHOLD_LOW && yVal < THRESHOLD_HIGH) {
    direction = "LEFT";
  } else if (yVal > THRESHOLD_HIGH && xVal > THRESHOLD_LOW && xVal < THRESHOLD_HIGH) {
    direction = "DOWN";
  } else if (yVal < THRESHOLD_LOW && xVal > THRESHOLD_LOW && xVal < THRESHOLD_HIGH) {
    direction = "UP";
  } else if (xVal > THRESHOLD_HIGH && yVal < THRESHOLD_LOW) {
    direction = "UP-RIGHT";
  } else if (xVal > THRESHOLD_HIGH && yVal > THRESHOLD_HIGH) {
    direction = "DN-RIGHT";
  } else if (xVal < THRESHOLD_LOW && yVal < THRESHOLD_LOW) {
    direction = "UP-LEFT";
  } else if (xVal < THRESHOLD_LOW && yVal > THRESHOLD_HIGH) {
    direction = "DN-LEFT";
  } else {
    direction = "CENTER";
  }

  oledDisplayCenter(direction);
  delay(50);
}

void oledDisplayCenter(String text) {
  oled.clearDisplay();

  int16_t x1, y1;
  uint16_t width, height;

  // Use smaller text for longer labels like "UP-RIGHT"
  if (text.length() > 6) {
    oled.setTextSize(1);
  } else {
    oled.setTextSize(2);
  }

  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  oled.println(text);
  oled.display();
}