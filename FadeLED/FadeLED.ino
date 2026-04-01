#define LED_PIN 9  // The Arduino UNO R4 pin connected to the LED

int brightness = 0;  // how bright the LED is
int fade_step = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(LED_PIN, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fade_step;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fade_step = -fade_step;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
