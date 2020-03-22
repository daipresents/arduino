#include <NewPing.h>

// サーボモータ
//   茶色：    GND
//   赤：      5V
//   オレンジ： 3pin

// Ultrasonic Sensor
//   Vcc – 電源入力 => 5V
//   Trig – トリガー 超音波出力用の信号を送信 => 
//   Echo – エコー 超音波入力用の信号を受信
//   GND – グランド

#include <Servo.h>

Servo myServo;

const int TRIG_PIN = 6;  // trigピン
const int ECHO_PIN = 7;  // echoピン
const int SERVO_PIN = 3; // サーボモーター

void setup() {
  pinMode( TRIG_PIN, OUTPUT );
  pinMode( ECHO_PIN, INPUT );
  
  myServo.attach(SERVO_PIN); // 3番ピンでサーボモーターを制御
  myServo.write(90);         // 90度で初期化
}

float distance = 0; //距離 cm

void loop() {
  digitalWrite(TRIG_PIN, LOW);  //超音波を出力終了
  delayMicroseconds(2); 
  digitalWrite(TRIG_PIN, HIGH); //超音波を出力
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);  //超音波を出力終了
  
  int t = pulseIn(ECHO_PIN, HIGH); //センサからの入力

  if (t > 0) {
    distance = t * 0.017;
  }
  
  if(distance <= 5) {   //もし距離センサの値が 5cm 以内なら
    myServo.write(180); //サーボモータの角度を 180 度(箱を開ける)
  } else {              //センサの近くにものがない時
    myServo.write(0);   //サーボモータの角度を 0 度にする(箱を閉じる)
  }
  delay(500);
}
