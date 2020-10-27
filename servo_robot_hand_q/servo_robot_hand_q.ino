#include <Servo.h>

Servo servo;

// サーボモータのピンを定数として設定する
const int SERVO_PIN = ここに値を設定する;

// 可変抵抗のピンを定数として設定する
const int POTENTIAL_PIN = ここに値を設定する;

void setup() {
  // ログ用にシリアルポートを設定
  Serial.begin(9600);

  // サーボモータのピンを初期設定する
  servo.attach(SERVO_PIN);

  // サーボモータの角度をまずは0にする
  servo.write(0);
}

void loop() {

  // 可変抵抗の値を読みこむ
  int value = ここに値を読みこむ処理を書こう

  // 値をログとして出力する
  Serial.println("value: " + String(value));

  // サーボモータを可変抵抗の値で動かす
  servo.write(value);

}
