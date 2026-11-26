#include <Arduino.h>
#include "config.h"


void setup() {
    pinMode(PIN_BUZZER, OUTPUT);

    // Test 1 : buzzer passif, une gamme do-ré-mi-fa-sol
    const int notes[] = {262, 294, 330, 349, 392};  // fréquences en Hz
    for (int note : notes) {
        tone(PIN_BUZZER, note, 200);
        delay(250);  // test de démarrage : attendre la fin de la note
    }
    delay(1000);

    // Test 2 : buzzer actif, un bip d'une demi-seconde
    digitalWrite(PIN_BUZZER, HIGH);
    delay(500);
    digitalWrite(PIN_BUZZER, LOW);
}

void loop() {}