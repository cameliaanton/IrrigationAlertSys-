#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  //lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(3, OUTPUT); // Pinul difuzorului
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Hai sa irigam");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
    lcd.print("");
    delay(3000);
  lcd.clear();
}
 
void loop() {
  int value = analogRead(A0);
  Serial.println(value);
  if (value > 950) {
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("UDA PLANTUTA");
  } else {
    digitalWrite(2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("PLANTA ARE APA");
  }
 
  if (value < 500) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : HIGH");
  } else if (value > 500 && value < 950) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : MID ");
  } else if (value > 950) {
    lcd.setCursor(0, 1);
    lcd.print("Moisture : LOW ");
    // Activează difuzorul pentru a anunța că este nevoie de apă
    tone(3, 1000); 
    delay(1000);   
    noTone(3);      
  }
  delay(1000);
}