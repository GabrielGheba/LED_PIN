const int ledPin = 4;
const int pinpulsante = 1;
int val = 0;
int lastval = 0;
int ledstate = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pinpulsante, INPUT);
}

void loop() {
  val = digitalRead(pinpulsante);  // ✅ Leggi il pulsante, non il LED
  
  // Rileva il fronte di salita (pressione del pulsante)
  if (val == HIGH && val != lastval) {
    ledstate = !ledstate;  // Inverti lo stato
    digitalWrite(ledPin, ledstate);  // Applica il nuovo stato
  }
  
  lastval = val;  // ✅ Aggiorna lastval
  
  Serial.print("Stato LED: ");
  Serial.print(ledstate);
  Serial.print(" - Ultimo valore: ");
  Serial.println(lastval);
  
  delay(50);  // Delay ridotto per migliore reattività
}
