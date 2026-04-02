#include "Adafruit_Keypad.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = { 8, 9, 10, 11 };

Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String displayText = "";  // stores what's been typed so far

void setup() {
  Serial.begin(9600);
  myKeypad.begin();

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
  myKeypad.tick();

  while (myKeypad.available()) {
    keypadEvent e = myKeypad.read();
    char key = (char)e.bit.KEY;

    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      Serial.print(key);
      Serial.println(" pressed");

      if (key == '*') {
        // Use * as a clear/backspace key
        displayText = "";
        oledDisplayCenter("Cleared");
        delay(600);
        oledDisplayCenter("");
      } else {
        displayText += key;
        oledDisplayCenter(displayText);
      }
    }
  }

  delay(10);
}

void oledDisplayCenter(String text) {
  oled.clearDisplay();

  if (text.length() == 0) {
    oled.display();
    return;
  }

  // If text is too long to fit on one line, scroll/truncate to last 5 chars
  if (text.length() > 5) {
    text = text.substring(text.length() - 5);
  }

  int16_t x1, y1;
  uint16_t width, height;
  oled.setTextSize(2);
  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  oled.println(text);
  oled.display();
}