/**
 * タミヤ カムプログラムロボット用スケッチ
 * 赤外線センサーで操作編
*/

const int COMMON_DELAY = 300;

// 目となるLEDふたつ
const int LED_EYE_RIGHT = A2;
const int LED_EYE_LEFT = 12;

// 超音波センサー
const int TRIG_PIN = A4;
const int ECHO_PIN = A3;

// モーターA
const int A_1A = 5;
const int A_1B = 3;
// モーターB
const int B_1A = 6;
const int B_1B = 9;

void setup() {
  pinMode(LED_EYE_RIGHT, OUTPUT);
  pinMode(LED_EYE_LEFT, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Initialization. Stop all motor first");

  // 慣らし運転
  stop(0);
  blink(HIGH);
  goUp(COMMON_DELAY);
  goDown(COMMON_DELAY);    
  blink(LOW);
}

void loop() {
  //blink(HIGH);

  control();

  delay(1000);
  
  //blink(LOW);
}

/**
   LEDのオン・オフ操作
*/
void blink(int onOff) {
  String message = "LED: ";
  log(message.concat(String(onOff)));
  
  digitalWrite(LED_EYE_RIGHT, onOff);
  digitalWrite(LED_EYE_LEFT, onOff);
  
  delay(100);
}

void control() {

  // 障害物との距離を計測して障害物がなくなるまで旋回させる 
  while(true) {
    // 障害物との距離を計測
    int distance = getDistance();

    if (distance == 0) {
      stop(COMMON_DELAY);  
    } else if (distance <= 10) {
      // 地面を近くに検知できるときは前に進む
      goUp(COMMON_DELAY);
    } else {
      // 地面を近くに検知できないときは右に回避
      goDown(COMMON_DELAY + 500);
      goRight(COMMON_DELAY + 500);
    }
  }
}

/**
 * 距離を測定
 */
int getDistance() {
  
  // 超音波を出力
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 距離データ取得
  double duration = pulseIn(ECHO_PIN, HIGH);
  log("duration: ", duration);
    
  if (duration < 0) {
    // マイナスになる場合は誤作動と考えてSkip
    return 0;
  }
  
  double distance = 0;
  
  // 距離データが取得できたら距離をcmで計算する
  if (duration > 0) {
    
    // 往復距離なのでまず半分にする
    duration = duration / 2;

    // 音速を340m/sに設定
    distance = duration * 340 * 100 / 1000000;
    log("distance: ", distance);
    
  } else {
    distance = 0;
    log("distance: ", distance);
    
  }

  return distance;
}

/**
   正回転
*/
void goUp(int wait) {
  log("Go up");
  analogWriteForMotor(HIGH, LOW, HIGH, LOW);
  delay(wait);
}

/**
   逆回転
*/
void goDown(int wait) {
  log("Go down");
  analogWriteForMotor(LOW, HIGH, LOW, HIGH);
  delay(wait);
}

/**
   右回転
*/
void goRight(int wait) {
  log("Go right");
  analogWriteForMotor(HIGH, LOW, LOW, LOW);
  delay(wait);
}

/**
   左回転
*/
void goLeft(int wait) {
  log("Go left");
  analogWriteForMotor(LOW, LOW, HIGH, LOW);
  delay(wait);
}

/**
   停止
*/
void stop(int wait) {
  Serial.println("Stopping");
  analogWriteForMotor(LOW, LOW, LOW, LOW);
  delay(wait);
}

void analogWriteForMotor(int inputA, int inputB, int inputC, int inputD) {
  digitalWrite(A_1A, inputA);
  digitalWrite(A_1B, inputB);
  digitalWrite(B_1A, inputC);
  digitalWrite(B_1B, inputD);
}

void log(String message) {
  Serial.println(message);
}

void log(String name, int value) {
  Serial.println(name + ": " + String(value));
}
