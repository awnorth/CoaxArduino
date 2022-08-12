#include <Servo.h>

byte ESCpin1 = 9;
byte ESCpin2 = 11;
byte potentiometerPin1 = A0;
byte potentiometerPin2 = A1;

Servo servo1; // Create a servo object 1
Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(ESCpin1);
  servo2.attach(ESCpin2);
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);

  delay(7000);
  // put your setup code here, to run once:
}

void loop() {
  int potVal1 = analogRead(potentiometerPin1);
  int potVal2 = analogRead(potentiometerPin2);

  int pwmVal1 = map(potVal1,0, 1023, 1100, 1900);
  int pwmVal2 = map(potVal2,0, 1023, 1100, 1900);

  servo1.writeMicroseconds(pwmVal1);
  servo2.writeMicroseconds(pwmVal2);

  Serial.print("PWM 1: ");
  Serial.print(pwmVal1);
  Serial.print("  PWM 2: ");
  Serial.println(pwmVal2);
  
  // put your main code here, to run repeatedly:
}
