#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

/**
 * タミヤ カムプログラムロボット用スケッチ
 * 赤外線センサーで操作編
*/

// 赤外線センサー
const int IR_RECEIVER = 10;
IRrecv irReceiver(IR_RECEIVER);
decode_results irResults;

const int COMMON_DELAY = 1000;

// 目となるLEDふたつ
const int LED_EYE_RIGHT = A2;
const int LED_EYE_LEFT = 12;

// モーターA
const int A_1A = 5;
const int A_1B = 3;
// モーターB
const int B_1A = 6;
const int B_1B = 9;

void setup() {
  pinMode(LED_EYE_RIGHT, OUTPUT);
  pinMode(LED_EYE_LEFT, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(IR_RECEIVER, INPUT);

  // 赤外線モジュールの入力読み込み開始
  irReceiver.enableIRIn();
  
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
  
  delay(100);
}

/**
 * 赤外線モジュールで受け取ったデータを取得
 */
int getReceivedValue() {
  int isReceived = irReceiver.decode(&irResults);
  
  if (isReceived == 1) {
    int receivedValue = irResults.value;
    irReceiver.resume();

    String message = "received: ";
    message.concat(String(receivedValue));
    log(message);
  
    return receivedValue;
  } else {
    log("No received data");
    return 0;
  }  
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

void control() {
  
  // 赤外線モジュールからの値はリモコンごとに違う
  int receivedValue = getReceivedValue();
  
  switch (receivedValue) {
    // 東芝のテレビリモコンの場合
    case 31875:
      goUp(COMMON_DELAY);
      break;
    case -8161:
      goDown(COMMON_DELAY);
      break;
    case -15811:
      goRight(COMMON_DELAY);
      break;
    case 8925:
      goLeft(COMMON_DELAY);
      break;
    
    // ELEGOOの小さいリモコンの場合
    case 25245:
      goUp(COMMON_DELAY);
      break;
    case -22441:
      goDown(COMMON_DELAY);
      break;
    //case -15811:
    //  goRight(COMMON_DELAY);
    //  break;
    //case 8925:
    //  goLeft(COMMON_DELAY);
    //  break;
    default:
      stop(0);
  }
}

void log(String message) {
  Serial.println(message);
}
