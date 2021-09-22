#include <Servo.h>
const int pinServo = 9;
const int anguloInicial = 20;
const int anguloFinal = 40;
const int ldr = A5;
const int limiar = 130;
int leitura;
int atraso = 180;

Servo s;

void setup() {
  Serial.begin(9600);
  s.attach(pinServo);
  s.write(anguloInicial);
}

void loop() {
  leitura = analogRead(ldr);
  if(leitura < limiar){
    delay(atraso);
    atraso = atraso - 2;
    tecla();
    delay(25);
  }
  Serial.println(leitura);
}

void tecla() {
  s.write(anguloFinal);
  delay(100);
  s.write(anguloInicial);
}
