#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //
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
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  //creamos los nuevos caracteres
  lcd.createChar (planta,planta);
  
 // Escribimos el texto en el LCD
  lcd.setCursor(0, 0); 
  lcd.print("Tutorial LCD_I2C");
  lcd.setCursor(0, 1);
  
  lcd.write (byte (planta));
  

  
}

void loop () {}
