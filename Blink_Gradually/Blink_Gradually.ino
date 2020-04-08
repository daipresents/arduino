
// さいしょに1かいだけうごく関数（かんすう）
void setup() {
  // 13ピンを出力（しゅつりょく）にせっていする
  pinMode(13, OUTPUT);
}

// この関数（かんすう）がずっとくりかえしじっこうされる
void loop() {
  for (int i = 1000; 0 < i; i = i - 50) {
    // 13ピンをHIGHにする
    digitalWrite(13, HIGH);
    
    // iミリびょうまつ
    delay(i);
    
    // 13ピンをLOWとにする
    digitalWrite(13, LOW);
    
    // iミリびょうまつ
    delay(i);
  }
}
