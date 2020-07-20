void setup() {
  Serial.begin(9600);
}

void loop() {
  // 4種類の運勢を出力する占いを作ってください
  // 占いの中身は、大吉、中吉、小吉、凶です。
  // random(1, 5) を使いましょう

  int num = random(1, 5);

  if (num == 1){
    Serial.println("Daikichi");
  } else if (num == 2) {
    Serial.println("Chuukichi");
  } else if (num == 3) {
    Serial.println("Shoukichi");
  } else {
    Serial.println("Kyou!!!");
  }

  delay(1000);
}
