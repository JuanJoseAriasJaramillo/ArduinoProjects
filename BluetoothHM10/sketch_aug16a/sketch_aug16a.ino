#include <SoftwareSerial.h>
SoftwareSerial ble(7 ,8); //RX, TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ble.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Inicia el programa");
  ble.write("La tecnolofia esta contigo..");
  delay(500);
}
