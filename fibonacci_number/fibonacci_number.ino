const int LED_PIN = 3;
  
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // フィボナッチ数を入れる変数
  // 
  int fibo = 1;
  // ひとつ前の数字を覚えておくには？
  int one = 1;
  // ふたつ前の数字を覚えておくには？
  int two = 1;
  
  // こうすると無限ループになる
  while(true) {
    Serial.println(fibo);
    if (fibo == 1) {
      // はじめだけ1を2回表示
      Serial.println(fibo);
    }

    // LED を光らせる処理を書く
    analogWrite(LED_PIN, fibo);
    
    // 次のフィボナッチ数を作る
    fibo = one + two;

    // ふたつまえの数字を覚える
    two = one; 
    
    // ひとつまえの数字を覚える
    one = fibo;

    delay(1000);
    
    if (255 <= fibo) {
      // iが255をこえたらループをぬける処理を書く
      break;
    }
  }
}
