const int LED_PIN = 3;
  
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

/**
 * フィボナッチ数 ＝ 2つ前の数字 ＋ 1つ前の数字
 */
void loop() {
  // フィボナッチ数を入れる変数を用意する
  // それ以外に必要な変数はなにか？
    // ひとつ前の数字を覚えておくには？
    // ふたつ前の数字を覚えておくには？
  
  // こうすると無限ループになる
  while(true) {
    // ここで表示
    Serial.println(fibo);

    // はじめだけ1を2回表示する

    // LED を光らせる処理を書く
    
    // 次のフィボナッチ数を作る

    // ひとつまえ、ふたつまえの数字をおぼえておく

    delay(1000);
    
    // iが255をこえたらループをぬける処理を書く
  }
}
