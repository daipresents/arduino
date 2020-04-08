/**
 * ２色ドットマトリクスＬＥＤ（赤緑）　８×８ドット　ＬＴＰ－１２１８８Ｍ－０８
 * http://akizukidenshi.com/catalog/g/gI-09878/
 * 
 * 16ピン必要なのでA0からA5もデジタル（D14からD19)として利用
 */

// 要素0は使わず（0で埋めている）、要素1からがそれぞの列番号になる。
// ROW[1] ＋ COL[1]で1行1列目のドットを指す
const int ROW[9] = {0, 4, 3, 19, 18, 14, 15, 16, 17};
const int COL[9] = {0, 12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  Serial.begin(9600);
  Serial.println("Initilization start");
  
  for (int i = 1; i < 9; i++) {
    pinMode(ROW[i], OUTPUT);
    pinMode(COL[i], OUTPUT);   
  }

  
  off();
  
  Serial.println("Initilization end");
}

void loop() {
  Serial.println("All high");
  all();
  delay(1500);

  scroll();
}

void line(int *pinArray, int highLow) {
  Serial.println(highLow);
  for (int i = 1; i < 9; i++) {
    digitalWrite(pinArray[i], highLow);
  }
}

void all() {
  Serial.println("All");
  line(ROW, HIGH);
  line(COL, LOW);
}

void off() {
  Serial.println("Off");
  line(ROW, LOW);
  line(COL, LOW);  
}

void scroll() {
  for (int count = 5; 0 < count; count--) {
    for (int i = 1; i < 9; i++) {
      off();
      
      // 1列ずつLEDを光らせる
      Serial.println("One line => High");
      digitalWrite(ROW[i], HIGH);
      
      for (int i = 1; i < 9; i++) {
        line(COL, LOW);
      }
  
      delay(100);
  
      off();
    }
  }
}
