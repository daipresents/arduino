/*
  じんこうおんせいをつかって
  Arduinoがしゃべりだす
  
  ひつようなもの：
    ATP3011F4-PU
    スピーカー
*/

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial serial(6, 7); //RX, TX
LiquidCrystal lcd( 2, 4, 10, 11, 12, 13 );

String LINE1 = "konnitiwa watashiwa/fujihara/dai/desu.";
String LINE2 = "kyouwa yorosiku/onegai/simasu\r";

void setup() {
  serial.begin(9600);
}

void loop() {
  lcd.begin( 16, 2 );
  lcd.clear();
  lcd.setCursor(0, 0);
  
  // https://synapse.kyoto/lib/MGLCD/CharacterCode/page001.html
  // コンニチハ ワタシハ
  lcd.print("\xba\xdd\xc6\xc1\xca \xdc\xc0\xbc\xca");  
  serial.print("?");
  serial.print(LINE1);

  delay(1000);
  
  // フジハラ ダイ デス 
  lcd.setCursor(0, 1);
  lcd.print("\xcc\xbc\xde\xca\xd7 \xc0\xde\xb2 \xc3\xde\xbd");
  serial.print(LINE2);

  delay(1000);
  }
