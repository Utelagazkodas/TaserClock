#include <Arduino.h>

#define SWITCH_PIN D1
#define OUTPUT_PIN D2

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP); // internal pull-up
  pinMode(OUTPUT_PIN, OUTPUT);

  digitalWrite(OUTPUT_PIN, LOW); // default off

  Serial.begin(9600);
}

void loop() {
  // Switch pressed = LOW (because of pull-up)
  if (digitalRead(SWITCH_PIN) == LOW) {
    digitalWrite(OUTPUT_PIN, LOW);
  } else {
    digitalWrite(OUTPUT_PIN, HIGH);
    Serial.println("this bitch is pressed");
  }
}
