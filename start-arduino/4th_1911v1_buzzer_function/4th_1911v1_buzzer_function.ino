int onkai[8] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  pinMode(2, INPUT); // 2番ピンでスイッチ状態を確認する
}

void loop() {
  int sw1 = digitalRead(2); // スイッチの状態を確認する
  // スイッチが押されているかの判断
  if(sw1 == HIGH) {
    doremi();
  } else {
    noTone(12); // 無音 
  }
}

void doremi() {
  tone(12, onkai[0]);
  delay(500);

  tone(12, onkai[1]);
  delay(500);

  tone(12, onkai[2]);
  delay(500);
}
