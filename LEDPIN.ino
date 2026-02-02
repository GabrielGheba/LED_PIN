const int ledPin = 4;
const int pinpulsante = 1;
const int pinmotor = 9;

int val = 0;
int lastval = 0;
int ledstate = LOW;
int velocitaMotore = 0;
int velocitaTarget = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pinpulsante, INPUT);
  pinMode(pinmotor, OUTPUT);
}

void loop() {
  val = digitalRead(pinpulsante);
  
  // Rileva pressione del pulsante
  if (val == HIGH && val != lastval) {
    ledstate = !ledstate;
    digitalWrite(ledPin, ledstate);
    
    // Imposta velocità target in base allo stato
    if (ledstate == HIGH) {
      velocitaTarget = 255;  // Accelera
    } else {
      velocitaTarget = 0;    // Ferma
    }
  }
  
  lastval = val;
  
  // Accelerazione/decelerazione graduale NON bloccante
  if (velocitaMotore < velocitaTarget) {
    velocitaMotore++;
  } else if (velocitaMotore > velocitaTarget) {
    velocitaMotore--;
  }
  
  analogWrite(pinmotor, velocitaMotore);
  
  // Debug
  Serial.print("LED: ");
  Serial.print(ledstate);
  Serial.print(" - Velocità motore: ");
  Serial.println(velocitaMotore);
  
  delay(20);  // Accelerazione più fluida
}