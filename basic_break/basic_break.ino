// whileとbreak をつかったループ

void setup() {
  
  // データを確認するための設定
  Serial.begin(9600);

}

void loop() {

  int i = 1;
  
  // 無限ループ
  while(true) {
    Serial.println(i);

    // 1が10になったらループをぬける
    if(i == 10) {
      break;
    }
    
    // iを1増やす
    // i = i + 1 でも同じ
    i++;

    delay(1000);
  }

  Serial.println("break!");
}
