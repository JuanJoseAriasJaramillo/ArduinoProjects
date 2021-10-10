
int led = 45;
int pulsador = 46;
int pulsadorEstado;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pulsadorEstado = digitalRead(pulsador);
  if(digitalRead(pulsador) == HIGH){
    digitalWrite(led, HIGH);
    Serial.println("pulsaste");
    delay(50);
  }else{
    Serial.println("sin pulsar");
    delay(50);}
}
