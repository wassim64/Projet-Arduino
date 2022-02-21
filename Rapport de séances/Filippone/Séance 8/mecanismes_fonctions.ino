// Test du servo
Servo servoTige;
Servo servoFlute;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoTige.attach(9);
  servoFlute.attach(8);

}

// Fonctions
  void MecaTige(){
    servoTige.write(30);
    delay(1000);
    servoTige.write(0);
    delay(1000);
  }

  void MecaFlute(){
    servoFlute.write(60);
  delay(1000);
  servoFlute.write(0);
  delay(1000);
  }

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    MecaTige();
    MecaFlute();
    }

}
