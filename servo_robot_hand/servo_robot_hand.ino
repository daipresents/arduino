#include <Servo.h>

Servo servo;

// サーボモータのピンを定数として設定する
const int SERVO_PIN = 9;

// 可変抵抗のピンを定数として設定する
const int POTENTIAL_PIN = A2;

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
  int value = analogRead(POTENTIAL_PIN);

  // 値をログとして出力する
  Serial.println("value: " + String(value));

  // 可変抵抗の値は0〜1024
  // サーボモータは0〜180
  // 尺度が違うので合わせる
  long newValue = map(value, 0, 1024, 0, 180);

  // 値をログとして出力する
  Serial.println("newValue: " + String(newValue));

  // サーボモータを可変抵抗の値で動かす
  servo.write(newValue);

}
