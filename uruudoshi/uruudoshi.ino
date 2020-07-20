void setup() {
  Serial.begin(9600);
  
  // うるう年を計算します。
  // うるう年とは？
  //   - 400で割り切れる年はうるう年です。
  //   - 4で割り切れる年はうるう年だけど、100で割り切れる年は平年です
  // 例： 
  //  2000年は400で割り切れるのでうるう年
  //  2104年は4で割り切れるのでうるう年
  //  2100年は4で割り切れるけど、100で割り切れるのでうるう年ではない

  // 変数yearに年を設定し、設定した数字がうるう年かどうかを判定します。
  int year = 2000;

  if (year == 2000) {
    // うるう年なら以下をプリントします
    Serial.println("No leap year.");
  } else {
    // うるう年じゃない場合は以下をプリン取ります
    Serial.println("No leap year.");
  }
}

void loop() {
  // ここには書かない
}
