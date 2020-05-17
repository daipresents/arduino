const int MOISTURE_SENSOR = A6;
const int MOTOR_IN_A = 5;
const int MOTOR_IN_B = 6;
const int PRESSURE_SENSOR = A1;

void setup() {
  pinMode(MOISTURE_SENSOR, INPUT);
  pinMode(MOTOR_IN_A, OUTPUT);
  pinMode(MOTOR_IN_B, OUTPUT);
  pinMode(PRESSURE_SENSOR, INPUT);

  Serial.begin(9600);
  Serial.println("Initialized");

  handlePump(LOW, LOW, "Stop pump"); 
}

void loop() {
  int moisture = analogRead(MOISTURE_SENSOR);
  int pressure = analogRead(PRESSURE_SENSOR);
  Serial.println("moisture: " + String(moisture) + " pressure: " + String(pressure));
  
  if (isWater(pressure) && isPump(moisture)) {
    handlePump(HIGH, LOW, "Pump up");  
  } else {
    handlePump(LOW, LOW, "Stop pump"); 
  }
  delay(500);
}

boolean isWater(int pressure) {
  
  // Full: 450
  // Middle: 500
  // Low: 600
  if (600 <= pressure) {
    // Max value of empty is 1023
    Serial.println("Water is empty.");
    return false;
  } else {
    Serial.println("Water is enough.");
    return true;
  }
}

boolean isPump(int moisuture) {
  
  if (760 <= moisuture) {
    // 湿度低 MAX1023
    return true;
  } else {
    // 湿度高（センサーを水中につけて344ぐらい、十分湿らせて650ぐらい）
    return false;
  }  
}

void handlePump(int motorA, int motorB, String message) {
  Serial.println(message);
  digitalWrite(MOTOR_IN_A, motorA);
  digitalWrite(MOTOR_IN_B, motorB);
  delay(500);
}
