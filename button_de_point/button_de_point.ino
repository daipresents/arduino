const int BUTTON_PIN = 3;
const int LED_PIN = 4;
int point = 0;
int berofe = 1;

void setup() {
  Serial.begin(9600);

  // ボタンの読み込み設定
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // LEDの設定
  pinMode(LED_PIN, INPUT_PULLUP);
}

void loop() {

  // ボタンの値を読み込む
  int button = digitalRead(BUTTON_PIN);

  // 読み込んだ値を出力（デバッグ）
  Serial.println("button: " + String(button));

  // もしボタンが押されたならばポイントが増える
  // おされたら0、はなされたら1になるので
  // 0から1になったときだけポイントを増やす
  if (berofe == 1) {
    if(button == 0) {
      point = point + 1;
      Serial.println("poiunt up!" + String(point));
    }
  }

  // 今の状態をおぼえておく
  berofe = button;
  
  // もしポイントが30になったらLEDがチカチカ光りつづける
  if ( point == 30 ) {
    Serial.println("30 point!!! " + String(point));
    while(true) {
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
      delay(500);
    }
  }
  
}
