const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

const int RED_SW = 2;
const int GREEN_SW = 3;
const int BLUE_SW = 4;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(RED_SW, INPUT_PULLUP);
  pinMode(GREEN_SW, INPUT_PULLUP);
  pinMode(BLUE_SW, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  int rValue = digitalRead(RED_SW);
  int gValue = digitalRead(GREEN_SW);
  int bValue = digitalRead(BLUE_SW);

  Serial.println("r: " + String(rValue) + ", g: " + String(gValue) + ", b: " + String(bValue));
  
  if(digitalRead(RED_SW)) {
    digitalWrite(RED_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, LOW);
  }

  if(digitalRead(GREEN_SW)) {
    digitalWrite(GREEN_PIN, HIGH);
  } else {
    digitalWrite(GREEN_PIN, LOW);
  }

  if(digitalRead(BLUE_SW)) {
    digitalWrite(BLUE_PIN, HIGH);
  } else {
    digitalWrite(BLUE_PIN, LOW);
  }
  
  delay(1000);
}
