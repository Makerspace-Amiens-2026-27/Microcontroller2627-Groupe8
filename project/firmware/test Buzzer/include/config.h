// include/config.h : brochage de la console
#pragma once

#include <Arduino.h>

constexpr int PIN_BUTTON          = D5;
constexpr int PIN_JOYSTICK_X      = D0;
constexpr int PIN_JOYSTICK_Y      = D1;
constexpr int PIN_JOYSTICK_SELECT = D2;
constexpr int PIN_BUZZER          = D3;   // seulement sur breadboard

constexpr int PIN_TFT_RESET = D7;
constexpr int PIN_TFT_DC    = D8;
constexpr int PIN_TFT_SCK   = D9;
constexpr int PIN_TFT_MOSI  = D10;
constexpr int PIN_TFT_CS    = -1;   // CS relié à GND : pas de broche