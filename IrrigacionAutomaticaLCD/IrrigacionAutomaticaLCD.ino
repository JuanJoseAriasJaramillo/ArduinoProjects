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
int HumedadledAzulIntermedio = 24;
int HumedadledVerdeHumedo = 25;
int HumedadledRojoSeco = 26;
int ReleBombaAgua = 28;
int ReleSolenoideAgua = 29;
int humedadProcesada;
int InfraRojo = 52;
void setup() {
  Serial.begin(9600);
  lcd.init();// Iniciar LCD
  //lcd.backlight();//Encender backlight.
  lcd.createChar (planta, planta);
  pinMode(HumedadledAzulIntermedio, OUTPUT);
  pinMode(HumedadledVerdeHumedo, OUTPUT);
  pinMode(HumedadledRojoSeco, OUTPUT);
  pinMode(ReleBombaAgua, OUTPUT);
  pinMode(ReleSolenoideAgua, OUTPUT);
  pinMode(InfraRojo, INPUT);
}
void loop() {
  bool state = digitalRead(InfraRojo);
  int humedad = analogRead(A0);
  Serial.println("Humedad RAW");
  Serial.println(humedad);
  Serial.println("Humedad en 100%");
  humedadProcesada = map(humedad, 0, 1023, 100, 0);
  Serial.println(humedadProcesada);
  switch (state)
  {
    case true:
      lcd.backlight();
      break;
    case false:
      lcd.noBacklight();
      break;
  }
  //planta 1
  lcd.setCursor(1, 0);
  lcd.write(byte(planta));// Escribimos la planta en el LCD.
  lcd.setCursor(0, 1);
  lcd.print(humedadProcesada);
  lcd.setCursor(2, 1);
  lcd.print("%");
  //planta 2
  lcd.setCursor(4, 0);
  lcd.write(byte(planta));// Escribimos la planta en el LCD.
  lcd.setCursor(3, 1);
  lcd.print("NN");
  lcd.setCursor(5, 1);
  lcd.print("%");
  //planta 3
  lcd.setCursor(7, 0);
  lcd.write(byte(planta));// Escribimos la planta en el LCD.
  lcd.setCursor(6, 1);
  lcd.print("NN");
  lcd.setCursor(8, 1);
  lcd.print("%");
  //planta 4
  lcd.setCursor(10, 0);
  lcd.write(byte(planta));// Escribimos la planta en el LCD.
  lcd.setCursor(9, 1);
  lcd.print("NN");
  lcd.setCursor(11, 1);
  lcd.print("%");
  /*lcd.setCursor(0, 1);// Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
    lcd.print(millis() / 1000); // Escribimos el número de segundos trascurridos
    lcd.print(" Segundos");
    lcd.setCursor(12, 0);*/
  delay(500);
  if (humedad <= 300) {                     //Averigua si esta MUY humedo
    Serial.println("Muy humedo");
    digitalWrite(HumedadledVerdeHumedo, HIGH);
    digitalWrite(HumedadledAzulIntermedio, LOW);
    digitalWrite(HumedadledRojoSeco, LOW);
    digitalWrite(ReleBombaAgua, HIGH);
    digitalWrite(ReleSolenoideAgua, HIGH);
  } else if (humedad > 301 && humedad < 600) { //Averigua si esta en un termino ok
    Serial.println("A medio");
    digitalWrite(HumedadledAzulIntermedio, HIGH);
    digitalWrite(HumedadledVerdeHumedo, LOW);
    digitalWrite(HumedadledRojoSeco, LOW);
    digitalWrite(ReleBombaAgua, HIGH);
    digitalWrite(ReleSolenoideAgua, HIGH);
  } else if (humedad > 650) {                //Averigua si esta seco
    Serial.println("Seco");
    digitalWrite(HumedadledRojoSeco, HIGH);
    digitalWrite(HumedadledAzulIntermedio, LOW);
    digitalWrite(HumedadledVerdeHumedo, LOW);
    digitalWrite(ReleBombaAgua, LOW);
    digitalWrite(ReleSolenoideAgua, LOW);
  }
}
