#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


int Infrarojo = 52;
int cableAmarillo = 26;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  
  pinMode(cableAmarillo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool state = digitalRead(Infrarojo);

  lcd.setCursor(1, 0);  
  lcd.setCursor(0,1);
  
  lcd.setCursor(2,1);
  lcd.print("%");

  switch (state)
  {
    case true:
        digitalWrite(cableAmarillo, HIGH);
        Serial.println("te detectaun");
        lcd.backlight();
        
      break;
    case false:
        digitalWrite(cableAmarillo, LOW);
        Serial.println("no te detectaun");
        lcd.noBacklight();
      break;
  }

  delay(100);
}
