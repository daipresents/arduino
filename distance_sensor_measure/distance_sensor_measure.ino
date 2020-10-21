const int LED1_PIN = 1;  // LEDひとつめ。ピンの番号は自分で決める
const int LED2_PIN = 2;  // LEDふたつめ。ピンの番号は自分で決める
const int LED3_PIN = 3;  // LEDみっつめ。ピンの番号は自分で決める

const int SENSOR_PIN = 4; // 距離センサーのピン。ピンの番号は自分で決める

void setup() {
  Serial.begin(9600);

  // 問題： ピンを初期設定しましょう。初期設定はpinModeを使います
  
}

void loop() {

  // 問題： 距離センサーの値を取ってきましょう
  //int sensor = ????;

  // ヒント： ifを3つ作って距離によって点灯するLEDの数を変えましょう
  
  // 距離が短い場合はLEDをひとつ点灯

  // 距離が中ぐらいの場合はLEDをふたつ点灯

  // 距離が長い場合はLEDをみっつ点灯

  
}
