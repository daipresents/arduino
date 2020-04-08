/**
 * タミヤ カムプログラムロボット用スケッチ
 */

// 目となるLEDふたつ
const int LED_EYE_RIGHT = 11;
const int LED_EYE_LEFT = 12;

// L293D
// モータA
const int ENABLE_A = 4;
const int CH1 = 5;
const int CH2 = 3;

// モータB
const int ENABLE_B = 8;
const int CH3 = 9;
const int CH4 = 10;

void setup() {  
  pinMode(LED_EYE_RIGHT, OUTPUT);
  pinMode(LED_EYE_LEFT, OUTPUT);
  pinMode(ENABLE_A,OUTPUT);
  pinMode(CH1,OUTPUT);
  pinMode(CH2,OUTPUT);
  
  Serial.begin(9600);

  Serial.println("Initialization. Stop all motor");
  digitalWrite(ENABLE_A, LOW);
  digitalWrite(ENABLE_B, LOW);
}

void loop() {
  //blink(HIGH);
      
  goAdvance();
  //goReverse();
  //goLowSpeed();
  //goMiddleSpeed();
  //goHighSpeed();

  //stop();

  //blink(LOW);
}

/**
 * LEDのオン・オフ操作
 */
void blink(int onOff) {
  //Serial.println("LED on/off");
  digitalWrite(LED_EYE_RIGHT, onOff);
  digitalWrite(LED_EYE_LEFT, onOff);
  delay(500);  
}

/**
 * 正回転
 */
void goAdvance() {
  Serial.println("Go advance");
  digitalWriteForMotor(HIGH, LOW);
}

/**
 * 逆回転
 */
void goReverse() {
  Serial.println("Go reverse");
  digitalWriteForMotor(LOW, HIGH);
}

/**
 * 低速回転
 */
void goLowSpeed() {
  Serial.println("Go low speed");
  analogWriteForMotor(127);
}

/**
 * 中速回転
 */
void goMiddleSpeed() {  
  Serial.println("Go middle speed");
  analogWriteForMotor(181);
}


/**
 * 高速回転
 */
void goHighSpeed() {
  Serial.println("Go high speed");
  analogWriteForMotor(255);
}

/**
 * 停止
 */
void stop() {
  Serial.println("Stop");
  digitalWrite(ENABLE_A, LOW);
  digitalWrite(ENABLE_B, LOW);
}

void digitalWriteForMotor(int channelA, int channelB) {
  digitalWrite(ENABLE_A, HIGH);
  digitalWrite(CH1, channelA);    
  digitalWrite(CH2, channelB);

  digitalWrite(ENABLE_B, HIGH);
  digitalWrite(CH3, channelA);    
  digitalWrite(CH4, channelB);

  // 1秒モーターを動かす
  delay(1000);
}

void analogWriteForMotor(int speed) {
  digitalWrite(ENABLE_A, HIGH);
  analogWrite(CH1, 255);    

  digitalWrite(ENABLE_B, HIGH);
  analogWrite(CH3, 255);    
  
  delay(100);
  
  analogWrite(CH1, speed);
  digitalWrite(CH2, LOW);
  analogWrite(CH3, speed);
  digitalWrite(CH4, LOW);

  // 1秒モーターを動かす
  delay(1000);
}
