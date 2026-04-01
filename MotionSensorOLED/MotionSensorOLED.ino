#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SENSOR_PIN 2

int motion_state = LOW;
int prev_motion_state = LOW;

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);

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
  prev_motion_state = motion_state;
  motion_state = digitalRead(SENSOR_PIN);

  if (prev_motion_state == LOW && motion_state == HIGH) {
    Serial.println("Motion detected!");
    oledDisplayCenter("Motion\nDetected!");
  }
  else if (prev_motion_state == HIGH && motion_state == LOW) {
    Serial.println("Motion stopped!");
    oledDisplayCenter("Motion\nStopped!");
  }
}

void oledDisplayCenter(String text) {
  oled.clearDisplay();
  oled.setCursor(0, 0);

  // Handle newline manually for two-line messages
  int newlineIndex = text.indexOf('\n');
  if (newlineIndex != -1) {
    String line1 = text.substring(0, newlineIndex);
    String line2 = text.substring(newlineIndex + 1);

    int16_t x1, y1;
    uint16_t w1, h1, w2, h2;
    oled.getTextBounds(line1, 0, 0, &x1, &y1, &w1, &h1);
    oled.getTextBounds(line2, 0, 0, &x1, &y1, &w2, &h2);

    // Center each line individually
    oled.setCursor((SCREEN_WIDTH - w1) / 2, 10);
    oled.println(line1);
    oled.setCursor((SCREEN_WIDTH - w2) / 2, 36);
    oled.println(line2);
  } else {
    int16_t x1, y1;
    uint16_t width, height;
    oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
    oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
    oled.println(text);
  }

  oled.display();
}