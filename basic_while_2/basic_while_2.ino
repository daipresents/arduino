void setup() {
  Serial.begin(9600);
}

void loop() {

  int i = 0;
  
  // こうすると無限ループになる
  while(true) {
    Serial.println(i);

    i = i + 1;

    if (10 < i) {
      // iが10をこえたらループをぬける
      break;
    }

    delay(1000);
  }
  
}
