void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lectura = analogRead(A0);  
  //lecturas 1000 - 1023
  /*if (lectura >= 1000) {
    Serial.println("El sensor esta desconectado o fuera del suelo");
  } else if (lectura < 1000 && lectura >= 600) {
    Serial.println("Suelo seco");
  } else if (lectura < 600 && lectura >= 370) {
    Serial.println("Suelo humedo");
  } else if (lectura < 370) {
    Serial.println("Sensor casi que en agua");
  }*/
  
   int lecturaPorcentaje = map(lectura, 1023, 0, 0, 100);

   Serial.println("La humedad es del: ");  
   Serial.println(lecturaPorcentaje);
   Serial.println("%");
   delay(1000);
   
}
