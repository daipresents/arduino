void setup() {
  Serial.begin(9600);

  // 1から順番に数を表示します
  // その数が3で割り切れるなら"Fizz"と言います。
  // その数が5で割り切れるなら"Buzz"と言います。
  // 両方で割り切れるなら"FizzBuzz"と言います。

  for(int i = 0; i <= 50; i++) {
    
    if(i % 15 == 0) {
      Serial.println("FizzBuzz");
    } else if (i % 3 == 0) {
        Serial.println("Fizz");
    } else if (i % 5 == 0) {
        Serial.println("Buzz");
    } else {
        Serial.println(i);
    }
  }
}

void loop() {
  // ここには書かない
}
