# Task 2: Servo Motor Control Using Ultrasonic Sensor and Arduino

## Project Description
This project controls a Servo Motor using an Ultrasonic Sensor (PING))) and an Arduino Uno.

The system works as follows:
- If an object is detected at a distance of 10 cm or less, the servo motor rotates to 90°.
- If the object moves farther than 10 cm, the servo motor returns to 0°.

## Components Used
- Arduino Uno
- Ultrasonic Sensor (PING)))
- Servo Motor
- Jumper Wires

## Circuit
The circuit was designed and tested using Tinkercad.

## Tinkercad Project
https://www.tinkercad.com/things/gVdtrpZUbnR-ingenious-crift-kieran2

## Arduino Code
#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int pingPin = 7;

long duration;
int distance;

void setup() {
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  distance = duration * 0.0343 / 2;

  if (distance <= 10) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }

  delay(100);
}

## Result
- Servo rotates to 90° when an object is detected within 10 cm.
- Servo returns to 0° when the object moves away.

## Author
Amal Almotiri

Tinkercad (https://www.tinkercad.com/things/gVdtrpZUbnR-ingenious-crift-kieran2)
Login - Tinkercad
