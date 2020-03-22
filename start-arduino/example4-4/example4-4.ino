// ボタンを押すとLEDが点灯し、
// ボタンから指を離したあともついたままになる（改良版）

const int LED = 13;   // LEDが接続されているピン
const int BUTTON = 7; // プッシュボタンが接続されているピン

int val = 0;      // 入力ピンの状態がこの変数（val）に記憶される
int old_val = 0;  // valの前の値を保存しておく変数
int state = 0;    // LEDの状態（0ならオフ、1ならオン）

void setup() {
  pinMode(LED, OUTPUT);   // ArduinoにLEDが出力であると伝える
  pinMode(BUTTON, INPUT); // BUTTONは入力に設定
}

void loop() {
  val = digitalRead(BUTTON);  // 入力を読み取りvalに格納

  // 変化があるかどうかチェック
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;
  }

  old_val = val; // valはもう古くなったので、保管しておく
  if (state == 1) {
    digitalWrite(LED, HIGH); // LEDオン
  } else {
    digitalWrite(LED, LOW);
  }
}
