int RedLed = 33;
int GreenLed = 31;
int button = 32;
String respuestaTrue = "Encendemos pa";
String respuestaFalse = "Apagamos pa";
int cualquierCosa;
int buttonRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  /*pinMode(RedLed, OUTPUT);
    pinMode(GreenLed, OUTPUT);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(33, HIGH);
    delay(500);
    digitalWrite(33, LOW);
    delay(500);*/
  String nalgona;
  cualquierCosa = writeSheet();
  buttonRead = digitalRead(button);
  if ( buttonRead == true ) {
    Serial.println(cualquierCosa);
  }


}

void writeSheet(String respuestaTrue1) 
{
  String nalgona = respuestaTrue1;
  return nalgona;
};
