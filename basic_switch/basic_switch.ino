void setup() {
  Serial.begin(9600);
}

void loop() {
  // 1から3の数字
  int num = random(1, 4);

  switch(num) {
    case 1:
      Serial.println("Daikichi: " + String(num));
      break;
    case 2:
      Serial.println("Shokichi:" + String(num));
      break;
    default:
      Serial.println("Kyou!!!:" + String(num));
  }
  delay(3000);
}
