#include <Servo.h>

#define VRX_PIN     A0  // Joystick X axis
#define SERVO_PIN   9   // Servo signal pin

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
}

void loop() {
  int xValue = analogRead(VRX_PIN);
  int angle = map(xValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Joystick: ");
  Serial.print(xValue);
  Serial.print(" => Servo: ");
  Serial.print(angle);
  Serial.println("°");

  delay(15); // small delay to let servo reach position
}