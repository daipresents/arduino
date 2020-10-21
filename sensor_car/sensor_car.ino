const int SWITCH_PIN = 2;   // スイッチのピン

const int SENSOR_PIN = A0;  // センサーのピン

const int MOTOR_A1_PIN = 3; // モーターAのピンその1
const int MOTOR_A2_PIN = 4; // モーターAのピンその2

const int MOTOR_B1_PIN = 5; // モーターBのピンその1
const int MOTOR_B2_PIN = 6; // モーターBのピンその2

void setup() {
  Serial.begin(9600); // デバッグ用。シリアルモニタで値を確認しましょう。
  
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
}

void loop() {
  
  // スイッチの値を読み込む
  int switchData = digitalRead(SWITCH_PIN);

  // スイッチの値をシリアルモニタに出しておく
  Serial.println("switchData: " + String(switchData));

  // 無限ループ
  while(true) {

    // センサーの値を読み込む
    int sensor = analogRead(SENSOR_PIN);

    // センサーの値をシリアルモニタに出しておく
    Serial.println("sensor:" + String(sensor));

    if (sensor < 1000) {

      // 白に反応すると1000より小さくなる
      
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);
      
    } else {

      // 黒に反応すると1000を超える
      // また、障害物がなくても1000を超える
      
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
      
    }
  }
  
}
