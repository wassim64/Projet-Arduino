// Test du servo
#include <Servo.h>
Servo servoTige;
Servo servoFlute;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoTige.attach(9);
  servoFlute.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    MecaTige();
    MecaFlute();
    }

}

// Fonctions
  void MecaTige(){
    servoTige.write(30);
    servoTige.write(0);
    delay(750);
  }

  void MecaFlute(){
    servoFlute.write(60);
  delay(200);
  servoFlute.write(0);
  delay(1000);
  }
