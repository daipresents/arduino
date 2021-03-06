#include <Servo.h>

const int SERVO_PIN = 9;
const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const boolean DEBUG = false;

Servo servo;
 
void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  servo.write(0);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void loop() {

  if(Serial.available() > 0) {
    moveServo(Serial.read());
    delay(100);
    Serial.write(getDistance());
  }
  
}

int moveServo(int angle){
  log("angle: ", angle);
  servo.write(angle);
}

int getDistance() {
  // 超音波を出力
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 距離データ取得
  int duration = pulseIn(ECHO_PIN, HIGH);
  int distance = 0;
  
  // 距離データが取得できたら距離をcmで計算する
  if (duration > 0) {
    log("duration: ", duration);
    
    // 往復距離なのでまず半分にする
    //duration = duration / 2;

    // 音速を340m/sに設定
    distance = duration * 0.017;
    log("distance: ", distance);
  }

  return distance;
}

void log(String message1, int message2){
  if(DEBUG){
    Serial.print(message1);
    Serial.println(message2);
  }
}
