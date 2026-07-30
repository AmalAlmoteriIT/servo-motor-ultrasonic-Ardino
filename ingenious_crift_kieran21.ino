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

  // إرسال نبضة من حساس PING)))
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // استقبال النبضة
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // حساب المسافة
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // التحكم بالسيرفو
  if (distance <= 10) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }

  delay(100);
}