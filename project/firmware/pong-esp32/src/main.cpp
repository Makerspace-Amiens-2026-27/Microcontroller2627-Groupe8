#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // LOW allume la LED de la XIAO
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);  // HIGH l'éteint
  delay(500);
}