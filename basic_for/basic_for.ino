// for をつかったループ

void setup() {
  
  // データを確認するための設定
  Serial.begin(9600);

}

void loop() {

  // 1から10までくりかえす
  for(int i = 1; i <= 10; i++) {
    Serial.println(i);
  }

  delay(3000);
}
