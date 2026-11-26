#include <Arduino.h>
#include "config.h"
void setup() {
    Serial.begin(115200);
    pinMode(PIN_JOYSTICK_SELECT, INPUT_PULLUP);
    analogReadResolution(12);  // lectures entre 0 et 4095
}

void loop() {
    int x = analogRead(PIN_JOYSTICK_X);
    int y = analogRead(PIN_JOYSTICK_Y);
    bool pressed = digitalRead(PIN_JOYSTICK_SELECT) == LOW;

    Serial.printf("x=%d y=%d select=%d\n", x, y, pressed);
    delay(100);
}
constexpr int JOYSTICK_DEADZONE = 300;
int joystickCenterX = 2048;

void calibrateJoystick() {
    long sum = 0;
    for (int i = 0; i < 16; i++) {
        sum += analogRead(PIN_JOYSTICK_X);
        delay(2);
    }
    joystickCenterX = sum / 16;
}

// Convertit une lecture brute (0..4095) en valeur entre -1.0 et +1.0
float normalizeJoystick(int raw, int center) {
    int offset = raw - center;
    if (abs(offset) < JOYSTICK_DEADZONE) {
        return 0.0f;
    }
    int range = (offset > 0) ? (4095 - center) : center;
    return constrain((float)offset / range, -1.0f, 1.0f);
}