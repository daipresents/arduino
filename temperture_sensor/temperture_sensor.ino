int a;
int v;
int ondo;

void setup() {
  // ログを出すための設定
  Serial.begin(9600);
}

void loop() {
  // 温度センサーの値を取得する
  a = analogRead(A1);

  // センサーの値を温度に変換する
  v = map(a, 0, 1023, 0, 5000);
  ondo = map(v, 100, 1750, -40, 125);

  // 温度をログに表示する
  Serial.println(ondo);

  // ここから下は追加で考えてください。
  // 「もしも」が3つひつようなので、if elseを使います。
  //
  // 例：
  //   if (ondo >= ?????) {
  //     LED3つ光る
  //   } else if (ondo >= ?????) {
  //     LED2つ光る
  //   } else {
  //     LED1つ光る
  //   }
  
  // 温度がすごくあついときは、LEDを3つ光らせる

  // 温度がふつうのときは、LEDを2つ光らせる

  // 温度がさむいときは、LEDを1つ光らせる

  delay(1000);
}
