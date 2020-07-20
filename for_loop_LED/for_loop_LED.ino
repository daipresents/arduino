// 定数でピンを定義
const int LED_PIN = 9;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // ループの確認用にはじめに設定しておく
  Serial.begin(9600);
}

void loop() {
  
  // だんだん明るくするループ
  for(int i = 0; i <= 255; i++) {
    
    // iの値を見てみよう
    Serial.println("i = " + String(i));
    
    analogWrite(LED_PIN, i);
    delay(10);
  }

}
