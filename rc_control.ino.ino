#include <SoftwareSerial.h>

/*
  Communication 2 – Embedded Wireless Control System
  Bluetooth‑Controlled RC Platform
*/

// ===== BLUETOOTH SERIAL =====
SoftwareSerial BT(2, 3); // RX, TX

// ===== TB6612FNG PINS =====
#define PWMA 5
#define AIN1 7
#define AIN2 8
#define PWMB 6
#define BIN1 9
#define BIN2 10
#define STBY 4

// ===== SPEED CONTROL =====
int baseSpeed = 150;
int turnCommand = 0;

// ===== MOTOR TRIM =====
int trim = +8; // adjust straight movement

// ===== PID CONTROL =====
float Kp = 2.2;
float Kd = 0.8;
float lastError = 0;

// ===== PULSE MOTION =====
bool motionActive = false;
unsigned long motionStart = 0;
const unsigned long pulseTime = 200; // ms

// ===== SLIDER INPUT =====
String speedBuffer = "";
unsigned long lastDigitTime = 0;
const unsigned long digitTimeout = 120;

// =================================================
void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Bluetooth RC System Ready");
}

// =================================================
void loop() {

  // ---- READ BLUETOOTH INPUT ----
  while (BT.available()) {
    char c = BT.read();

    // Speed slider input
    if (isDigit(c)) {
      speedBuffer += c;
      lastDigitTime = millis();
    } 
    else {
      switch (c) {
        case 'F': startMotion(0); break;
        case 'L': startMotion(-40); break;
        case 'R': startMotion(40); break;
        case 'B': startBackward(); break;
        case 'S': stopMotors(); break;
      }
    }
  }

  // ---- APPLY SLIDER SPEED ----
  if (speedBuffer.length() > 0 &&
      millis() - lastDigitTime > digitTimeout) {

    int sliderVal = speedBuffer.toInt();
    speedBuffer = "";

    baseSpeed = map(sliderVal, 0, 100, 80, 255);
    baseSpeed = constrain(baseSpeed, 80, 255);
  }

  // ---- PULSE AUTO STOP ----
  if (motionActive) {
    drivePID();
    if (millis() - motionStart >= pulseTime) {
      stopMotors();
      motionActive = false;
    }
  }
}

// =================================================
void startMotion(int turn) {
  turnCommand = turn;
  motionStart = millis();
  motionActive = true;
  drivePID();
}

// =================================================
void drivePID() {
  float error = turnCommand;
  float derivative = error - lastError;
  lastError = error;

  float pid = (Kp * error) + (Kd * derivative);

  int leftSpeed  = baseSpeed - pid - trim;
  int rightSpeed = baseSpeed + pid + trim;

  leftSpeed  = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  analogWrite(PWMA, leftSpeed);
  analogWrite(PWMB, rightSpeed);
}

// =================================================
void startBackward() {
  motionActive = true;
  motionStart = millis();

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);

  analogWrite(PWMA, baseSpeed);
  analogWrite(PWMB, baseSpeed);
}

// =================================================
void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}
