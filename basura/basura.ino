#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte planta[8] = {
  B00000,
  B11100,
  B00110,
  B01100,
  B00100,
  B11111,
  B01110,
  B01110
};

void setup() {
  // put your setup code here, to run once:
lcd.init();// Iniciar LCD
  lcd.backlight();//Encender backlight.
  lcd.createChar (planta, planta);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0, 0);
    lcd.print("Hola Mundo");// Escribimos el Mensaje en el LCD.
    lcd.setCursor(0, 1);// Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
    lcd.print(millis() / 1000); // Escribimos el número de segundos trascurridos
    lcd.print(" Segundos");
    lcd.setCursor(12, 0);
    lcd.write(byte(planta));
}
