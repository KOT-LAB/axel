#include "pinout.h"
#include <Arduino.h>

#define BLINK_DELAY 500

bool ledState = false;

void setup() { pinMode(LED, OUTPUT); }

void loop() {
  ledState = !ledState;
  digitalWrite(LED, ledState ? HIGH : LOW);
  delay(BLINK_DELAY);
}
