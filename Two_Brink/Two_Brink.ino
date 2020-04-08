
// さいしょに1かいだけうごく関数（かんすう）
void setup() {
  // 2ピンを出力（しゅつりょく）にせっていする
  pinMode(2, OUTPUT);
  // 13ピンを出力（しゅつりょく）にせっていする
  pinMode(13, OUTPUT);
}

// この関数（かんすう）がずっとくりかえしじっこうされる
void loop() {
  // 2ピンと13ピンをHIGHにする
  digitalWrite(2, HIGH);
  digitalWrite(13, HIGH);
  
  // 1000ミリびょうまつ
  delay(1000);

  // 2ピンと13ピンをLOWにする
  digitalWrite(2, LOW);
  digitalWrite(13, LOW);

  // 1000ミリびょうまつ
  delay(1000);
}
