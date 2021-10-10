int pushButton = 2;
boolean buttonState = digitalRead(pushButton);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(buttonState == true){
    Serial.println("Está encendido");
  }else{
   Serial.println("Está apagado");
  }
  delay(500);
}
