//LCD
#include <LiquidCrystal.h>

//horloge
#include <Wire.h>
#include <ds3231.h>

struct ts t; //déclaration de la variable t
struct ts nt; //déclaration de la variable nt. Si j'utilise t partout ca ne marche pas

LiquidCrystal lcd(2,3,4,5,6,7); 

void setup() {
  Serial.begin(9600);

  lcd.begin(16,2);
  lcd.print("Bonjour");
  lcd.setCursor(0,1); // (colonne,ligne) 0 est le premier indice
  Serial.println("Test");
  lcd.print("Adam");
  lcd.print(" Le Boss");
  
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN); //ligne modifiée
  /*
  //Réglage de l'heure 
  nt.mday = 15; 
  nt.mon = 12;
  nt.year = 2021;
  nt.hour = 10;
  nt.min = 31;
  nt.sec=0;
  DS3231_set(nt);
  */
  

   
//L'heure est réglée

  
}
 
void loop() {
  // put your main code here, to run repeatedly:

  DS3231_get(&t);
  Serial.println(t.year);
  Serial.print("date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Heure : ");
  Serial.print(t.hour);
  lcd.setCursor(0,0);
  lcd.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  lcd.print("h ");
  lcd.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
  lcd.print("min ");
  lcd.print(t.sec);
  lcd.print("sec");
  
  delay(1000);
}
