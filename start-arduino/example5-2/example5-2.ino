// ボタンを押すとLEDが点灯し、
// ボタンから指を離したあともついたままにする
// バウンシングを解消する簡単な方法を取り入れる
// ボタンを押したままにすると明るさが変化する

const int LED = 9;     // LEDが接続されたボタン
const int BUTTON = 7;  // プッシュボタンが接続された入力ピン

int val = 0;       // 入力ピンの状態がこの変数（val）に記憶される
int old_val = 0;   // valの前の値を保存しておく変数
int state = 0;     // LEDの状態（０ならオフ、1ならオン）

int brightness = 128;        // 明るさの値を保存する
unsigned long startTime = 0; // いつ押し始めたか？

void setup() {
  pinMode(LED, OUTPUT);   // ArduinoにLEDが出力であると伝える
  pinMode(BUTTON, INPUT); // BUTTONは入力に設定
}

void loop() {
  val = digitalRead(BUTTON);  // 入力を読みvalに新鮮な値を保存

  // 変化があるかどうかチェック
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;      // オフからオンへ、オンからオフへ
    startTime = millis();   // millis()はArduinoの時計
                            // ボードがリセットされてからの時間を
                            // ミリ秒（ms）単位で返す
                            // （最後にボタンが押された時間を記憶）

    delay(10);
  }

  // ボタンが押し続けられているかをチェック
  if ((val == HIGH) && (old_val == HIGH)) {
    // 500ms以上押されているか？
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++;   // brightnessに1を足す
      delay(10);      // brightnessの増加が速くなりすぎないように
      if (brightness > 255) {  // 255が最大値
        brightness = 0;        // 255を超えたら0に戻す
      }
    }
  }

  old_val = val;  // valはもう古いので、しまっておく

  if (state == 0) {
    analogWrite(LED, brightness); // 現在の明るさでLEDを点灯
  } else {
    analogWrite(LED, 0);          // LEDをオフ
  }
}
