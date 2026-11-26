#include <Arduino.h>
#include "config.h"
#include "config.h"

void setup() {
    Serial.begin(115200);
    pinMode(PIN_BUTTON, INPUT_PULLUP);
}


constexpr int PRESSED_LEVEL = LOW;           // niveau lu quand on appuie (étape 1)
constexpr unsigned long DEBOUNCE_MS = 30;

struct Button {
    int pin;
    int stableLevel;              // dernier niveau confirmé
    int lastRead;                 // dernière lecture brute
    unsigned long lastChangeMs;   // date du dernier mouvement du signal
};

Button button = {PIN_BUTTON, !PRESSED_LEVEL, !PRESSED_LEVEL, 0};

// Renvoie true une seule fois par appui, au moment où il est confirmé
bool justPressed(Button& b) {
    int level = digitalRead(b.pin);
    if (level != b.lastRead) {         // le signal bouge : rebond ou vrai changement
        b.lastRead = level;
        b.lastChangeMs = millis();
    }
    if (millis() - b.lastChangeMs > DEBOUNCE_MS && level != b.stableLevel) {
        b.stableLevel = level;         // stable depuis 30 ms : changement confirmé
        return level == PRESSED_LEVEL; // vrai sur l'appui, faux sur le relâchement
    }
    return false;
}



void loop() {
    static int count = 0;
    if (justPressed(button)) {
        count++;
        Serial.printf("Appui n°%d\n", count);
    }
}