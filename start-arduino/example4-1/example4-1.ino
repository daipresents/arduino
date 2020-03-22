// LEDを点滅させる

const int LED = 13;  // LED is No.13 digital pin

void setup() {
  pinMode(LED, OUTPUT); // Disital pin is output
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
