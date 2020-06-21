
// ifとrandomのサンプル
void setup() {
  
  // データを確認するための設定
  Serial.begin(9600);

}

void loop() {

  // 1から3のランダムな数字を取得
  // ひとつめの引数は最小の値 1
  // ふたつめの引数は最大の値＋1となり4となる
  int janken = random(1, 4);
  Serial.println("janken = " + String(janken));
  
  if (janken == 1) {
    Serial.println("Rock");
  }

  if (janken == 2) {
    Serial.println("Paper");
  }

  if (janken == 3) {
    Serial.println("Scissors");
  }

  delay(3000);
  
}
