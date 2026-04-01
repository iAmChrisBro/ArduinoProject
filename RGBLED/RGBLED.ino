#define PIN_RED   9 // Arduino UNO R4 pin connected to the LED's red pin
#define PIN_GREEN 6 // Arduino UNO R4 pin connected to the LED's green pin
#define PIN_BLUE  3 // Arduino UNO R4 pin connected to the LED's blue pin

void setup() {
  pinMode(PIN_RED, OUTPUT);   // Set red LED pin as an output
  pinMode(PIN_GREEN, OUTPUT); // Set green LED pin as an output
  pinMode(PIN_BLUE, OUTPUT);  // Set blue LED pin as an output
}

void loop() {
  // Set RGB LED to teal color #00C9CC (R = 0, G = 201, B = 204)
  analogWrite(PIN_RED,   0);
  analogWrite(PIN_GREEN, 201);
  analogWrite(PIN_BLUE,  204);

  delay(1000); // Maintain color for 1 second

  // Set RGB LED to salmon pink #F7788A (R = 247, G = 120, B = 138)
  analogWrite(PIN_RED,   247);
  analogWrite(PIN_GREEN, 120);
  analogWrite(PIN_BLUE,  138);

  delay(1000); // Maintain color for 1 second

  // Set RGB LED to Google green #34A853 (R = 52, G = 168, B = 83)
  analogWrite(PIN_RED,   52);
  analogWrite(PIN_GREEN, 168);
  analogWrite(PIN_BLUE,  83);

  delay(1000); // Maintain color for 1 second
}
