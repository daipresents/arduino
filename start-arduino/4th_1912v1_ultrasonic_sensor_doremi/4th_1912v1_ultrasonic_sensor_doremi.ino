// Ultrasonic Sensor
//   Vcc – 電源入力 => 5V
//   Trig – トリガー 超音波出力用の信号を送信 =>
//   Echo – エコー 超音波入力用の信号を受信
//   GND – グランド

const int TRIG_PIN = 6;  // trigピン
const int ECHO_PIN = 7;  // echoピン

int onkai[8] = {262, 294, 330, 349, 392, 440, 494, 523};
float distance = 0; //距離 cm
 
void setup() {
  Serial.begin(9600);
  pinMode( TRIG_PIN, OUTPUT );
  pinMode( ECHO_PIN, INPUT );
}

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

  Serial.println(distance);
  
  piano();
}

void piano() {
  if (1 <= distance && distance <= 10) {
    //もし距離センサの値が 5cm 以内なら
    tone(12, onkai[0]);
  } else if (10 < distance && distance <= 20) {
    tone(12, onkai[1]);
  } else if (20 < distance && distance <= 30) {
    tone(12, onkai[2]);
  } else {
    //センサの近くにものがない時
    noTone(12); // 無音
  }
  delay(500);
}
