int HumedadledAzulIntermedio = 24;
int HumedadledVerdeHumedo = 25;
int HumedadledRojoSeco = 26;
int ReleBombaAgua = 28;
int ReleSolenoideAgua = 29;
void setup() {
  Serial.begin(9600);
  pinMode(HumedadledAzulIntermedio, OUTPUT);
  pinMode(HumedadledVerdeHumedo, OUTPUT);
  pinMode(HumedadledRojoSeco, OUTPUT);
  pinMode(ReleBombaAgua, OUTPUT);
  pinMode(ReleSolenoideAgua, OUTPUT);
}

void loop() {
  int humedad = analogRead(A0);
  Serial.println(humedad);
  delay(500);
 
  if (humedad <= 300){                      //Averigua si esta MUY humedo
    Serial.println("Muy humedo");
    digitalWrite(HumedadledVerdeHumedo, HIGH);
    digitalWrite(HumedadledAzulIntermedio, LOW);
    digitalWrite(HumedadledRojoSeco, LOW);
    digitalWrite(ReleBombaAgua, HIGH);
  }else if(humedad > 301 && humedad < 600){ //Averigua si esta en un termino ok
    Serial.println("A medio");
    digitalWrite(HumedadledAzulIntermedio, HIGH);
    digitalWrite(HumedadledVerdeHumedo, LOW);
    digitalWrite(HumedadledRojoSeco, LOW);
    digitalWrite(ReleBombaAgua, HIGH);
  }else if(humedad > 650){                  //Averigua si esta seco
    Serial.println("Seco");
    digitalWrite(HumedadledRojoSeco, HIGH);
    digitalWrite(HumedadledAzulIntermedio, LOW);
    digitalWrite(HumedadledVerdeHumedo, LOW);      
    digitalWrite(ReleBombaAgua, LOW); 
  }
    

}
