#include <Servo.h>
Servo test;

void setup() {
  // put your setup code here, to run once:
test.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  test.write(0);
  delay(2000);
  test.write(30);
  delay(1000);
  
 
}
