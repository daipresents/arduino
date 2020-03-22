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

String MESSAGE = "konnitiwa watashiwa/fujihara/dai/desu.kyouwa yorosiku/onegai/simasu\r";

void setup() {
  serial.begin(9600);
  
  lcd.begin( 16, 2 );
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello! (^_^)");
  lcd.setCursor(0, 1);
  lcd.print("My name is Dai!");
}

void loop() {
  serial.print("?");
  serial.print(MESSAGE);
  delay(1000);
}
