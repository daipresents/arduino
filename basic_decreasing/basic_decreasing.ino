// だんだんへらす

void setup() {
  
  // データを確認するための設定
  Serial.begin(9600);

}

void loop() {

  int num = 5000;

  // 10回へらす
  for(int i = 0; i <= 10; i++) {
    
    Serial.println(num);

    // ループごとにはんぶんにすれば
    // だんだんへらせる
    num = num / 2;
  }

  delay(1000);
}
