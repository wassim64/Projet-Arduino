//LCD
#include <LiquidCrystal.h>

//horloge
#include <Wire.h>
#include <ds3231.h>

struct ts t; //déclaration de la variable t
struct ts nt; //déclaration de la variable nt

LiquidCrystal lcd(2,3,4,5,6,7); 

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.print("Bonjour");
  lcd.setCursor(0,1); // (colonne,ligne) 0 est le premier indice
  Serial.println("Test");
  lcd.print("Adam");
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN); //ligne modifiée
  //Réglage de l'heure
  nt.mday = 01; 
  nt.mon = 12;
  nt.year = 2021;
  nt.hour = 19;
  nt.min = 28;
  nt.sec=0;
  DS3231_set(nt);
  //L'heure est réglée

  
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  DS3231_get(&t);
  Serial.print("date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Heure : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
 
  delay(500);
}
