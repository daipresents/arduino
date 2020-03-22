// LEDのフェードインとフェードアウト
// （スリープ状態のMacのように）

const int LED = 9;  // LEDが接続されたピン
int i = 0;          // カウントアップとダウンに使用

void setup() {
  pinMode(LED, OUTPUT); // LEDのピンの出力に設定
}

void loop() {
  for (i = 0; i < 255; i++) { // 0から254までループ（フェードイン）
    analogWrite(LED, i);    // LEDの明るさをセット
    delay(10);              // 10ミリ秒停止 analogWrite()は一瞬なのでこれがないと変化が見えない
  }
  for (i = 255; i > 0; i--) { // 255から1まで（フェードアウト）
    analogWrite(LED, i);
    delay(10);
  }
}
