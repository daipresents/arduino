// 定数としてピンの番号を定義しておく
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {

  // Red on
  digitalWrite(RED_PIN, HIGH);
  delay(1000);

  // Red off
  digitalWrite(RED_PIN, LOW);
  delay(1000);

  // Green on
  digitalWrite(GREEN_PIN, HIGH);
  delay(1000);

  //Green off
  digitalWrite(GREEN_PIN, LOW);
  delay(1000);

  // Blue on
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);

  // Blue off
  digitalWrite(BLUE_PIN, LOW);
  delay(1000);
}
