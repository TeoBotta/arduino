#include <Servo.h>

Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(6);
}

void loop()
{
  myservo.write(45);
  delay(3000);
  myservo.write(135);
  delay(3000);
}
