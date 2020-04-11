/**
   タミヤ カムプログラムロボット用スケッチ
*/

const boolean DEBUG = true;
const int COMMON_DELAY = 300;

// 目となるLEDふたつ
const int LED_EYE_RIGHT = 11;
const int LED_EYE_LEFT = 12;

// モーターはPWM対応ピンに接続して速度調整できるようにもできるが
// ジョイスティックの反応が悪いので断念

// モーターA
const int A_1A = 5;
const int A_1B = 3;
// モーターB 
const int B_1A = 6;
const int B_1B = 9;

// ジョイスティック
const int VRX = 1;
const int VRY = 2;

// スピードをLOW、HIGHに分ける
// 上下の動きの閾値。コントローラーに合わせてこの値を調整する
const int VRX_UP_MIN = 0;
const int VRX_UP_MAX = 170;
const int VRX_NEUTRAL_MIN = 171;
const int VRX_NEUTRAL_MAX = 1019;
const int VRX_DOWN_MIN = 1020;
const int VRX_DOWN_MAX = 1023;

// 左右の動き
const int VRY_RIGHT_HIGH_MIN = 0;
const int VRY_RIGHT_HIGH_MAX = 169;
const int VRY_NEUTRAL_MIN = 170;
const int VRY_NEUTRAL_MAX = 999;
const int VRY_LEFT_HIGH_MIN = 1000;
const int VRY_LEFT_HIGH_MAX = 1023;

void setup() {
  pinMode(LED_EYE_RIGHT, OUTPUT);
  pinMode(LED_EYE_LEFT, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  
  Serial.begin(9600);

  Serial.println("Initialization. Stop all motor");
  stop();
}

void loop() {
  blink(HIGH);

  control();
  
  blink(LOW);
}

/**
   LEDのオン・オフ操作
*/
void blink(int onOff) {
  String message = "LED: ";
  log(message.concat(String(onOff)));
  
  digitalWrite(LED_EYE_RIGHT, onOff);
  digitalWrite(LED_EYE_LEFT, onOff);
  
  delay(300);
}

/**
   正回転
*/
void goUp() {
  log("Go up");
  analogWriteForMotor(HIGH, LOW, HIGH, LOW);
}

/**
   逆回転
*/
void goDown() {
  log("Go down");
  analogWriteForMotor(LOW, HIGH, LOW, HIGH);
}

/**
   右回転
*/
void goRight() {
  log("Go right");
  analogWriteForMotor(HIGH, LOW, LOW, HIGH);
}

/**
   左回転
*/
void goLeft() {
  log("Go left");
  analogWriteForMotor(LOW, HIGH, HIGH, LOW);
}

/**
   停止
*/
void stop() {
  Serial.println("Stopping");
  analogWriteForMotor(LOW, LOW, LOW, LOW);
  delay(COMMON_DELAY);
}

void analogWriteForMotor(int inputA, int inputB, int inputC, int inputD) {
  digitalWrite(A_1A, inputA);
  digitalWrite(A_1B, inputB);
  digitalWrite(B_1A, inputC);
  digitalWrite(B_1B, inputD);
  delay(COMMON_DELAY);
}

boolean isNeutral() {
  int x = analogRead(VRX);
  int y = analogRead(VRY);
  
  if (VRX_NEUTRAL_MIN <= x && x <= VRX_NEUTRAL_MAX) {
    if (VRY_NEUTRAL_MIN <= y && y <= VRY_NEUTRAL_MAX) {
      return true;
    }
  }
  
  return false;
}

boolean isXHigh() {
  // XかYどちらを優先するか判断
  int x = analogRead(VRX);

  if (VRX_UP_MIN <= x && x <= VRX_UP_MAX) {
    return true;
  }

  if (VRX_DOWN_MIN <= x && x <= VRX_DOWN_MAX) {
    return true;
  }

  return false;
}

boolean isYHigh() {
  // XかYどちらを優先するか判断
  int y = analogRead(VRY);

  if (VRY_RIGHT_HIGH_MIN <= y && y <= VRY_RIGHT_HIGH_MAX) {
    return true;
  }

  if (VRY_LEFT_HIGH_MIN <= y && y <= VRY_LEFT_HIGH_MAX) {
    return true;
  }

  return false;
}

boolean isUp() {
  int value = analogRead(VRX);
  if (value < VRX_NEUTRAL_MIN) {
    return true;
  } else {
    return false;
  }
}

boolean isRight() {
  int value = analogRead(VRY);
  if (value < VRY_NEUTRAL_MIN) {
    return true;
  } else {
    return false;
  }
}

void goX() {
  if (isUp()) {
    goUp();
  } else {
    goDown();
  }
}

void goY() {
  if (isRight()) {
    goRight();
  } else {
    goLeft();
  }
}

void control() {
  logXY();

  // Neutralかの確認をまずやる
  if (isNeutral()) {
    stop();
    return;
  }

  if (isXHigh()) {
    // XかYどちらを優先するか判断
    goX();
  } else {
    goY();
  }
}

void logXY() {
  String message = "x:";
  message.concat(analogRead(VRX));
  message.concat(" y:");
  message.concat(analogRead(VRY));
  log(message);
}

void log(String message) {
  if (DEBUG) {
    Serial.println(message);
  }
}
