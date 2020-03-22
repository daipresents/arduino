// サーボモータ
//   茶色：    GND
//   赤：      5V
//   オレンジ： 3pin

#include <Servo.h>

Servo myServo;

const int SERVO_PIN = 3; // 3番ピンでサーボモーターを制御

void setup() {
  myServo.attach(SERVO_PIN); // 3番ピンでサーボモーターを制御
  myServo.write(90);         // 90度で初期化
}

void loop() {
  for(int i = 0; i <= 180; i += 20){ // 0から180まで20度ずつ増える
    myServo.write(i);
      delay(1000);
  }
}
