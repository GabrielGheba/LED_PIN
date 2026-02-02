int ledPin = 4;
int pinpulsante = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pinpulsante, INPUT);
}

void loop() {
  if (digitalRead(pinpulsante) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
