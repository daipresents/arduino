const int BUTTON_PIN = 3;
const int LED_PIN = 4;

void setup() {
  Serial.begin(9600);

  // ボタンの読み込み設定
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // LEDの設定
  pinMode(LED_PIN, INPUT_PULLUP);
}

void loop() {
  // ポイントをいれる変数
  int point = 0;

  // ボタンの値を読み込む
  int button = digitalRead(BUTTON_PIN);

  // 読み込んだ値を出力（デバッグ）
  Serial.println("button: " + String(button));

  // もしボタンが押されたならばポイントが増える
  
  // もしポイントが30になったらLEDがチカチカ光りつづける
  
}
