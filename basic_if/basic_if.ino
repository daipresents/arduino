void setup() {
  Serial.begin(9600);
}

void loop() {
  // 1から3のランダムな数字を取得
  int uranai = random(1,4);

  if (uranai == 1){
    Serial.println("Daikichi: " + String(uranai));
  } else if (uranai == 2) {
    Serial.println("Shokichi: " + String(uranai));
  } else {
    Serial.println("Kyou!!!!: " + String(uranai));
  }

  int num = 10;
  if (num % 5 == 0) {
    // 5で割り切れる場合はHello
    Serial.println("Hello");
  } else {
    Serial.println("Bye");
  }
  
  delay(3000);
}
