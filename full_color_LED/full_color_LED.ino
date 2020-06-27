const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  int color[] = {RED, BLUE, GREEN}; 

  // 赤（Red) => 青（Blue) => 緑（Green)
  for(int i = 0; i < sizeof(color); i++) {
    digitalWrite(color[i], HIGH);
    delay(500);
    digitalWrite(color[i], LOW);
    delay(500); 
  }

  // Red + Blue
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, LOW);
  delay(3000);
  
  // Red + Green
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, HIGH);
  delay(3000);

  // Blue + Green
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(3000);

  // Red + Blue + Green
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(3000);

  // All off
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
  delay(3000);
}
