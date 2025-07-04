// Define pin numbers
const int buttonPins[4] = {0, 1, 2, 3};  // pins for buttons
const int ledPins[4] = {4, 6, 7, 29};     // pins for LEDs

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); 
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    bool isPressed = digitalRead(buttonPins[i]) == LOW;

    digitalWrite(ledPins[i], isPressed ? HIGH : LOW);
  }

  delay(10); 
}
