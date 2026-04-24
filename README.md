# Embedded Wireless Communication System

## 📌 Overview

<p align="justify">
<strong>Purpose:</strong> This project was developed as a major course requirement for the subject <strong>Communication 2</strong>. The project demonstrates the application of wireless communication, serial data transmission, and control signal processing using an embedded microcontroller system.
</p>

<p align="justify">
The system is a compact remote‑controlled robotic platform that converts wireless commands into physical motion through motor actuation. It integrates an Arduino Nano microcontroller, Bluetooth Low Energy (BLE) module, motor driver, power regulation circuitry, and DC motors. The project emphasizes practical implementation of communication concepts such as UART communication, signal decoding, PWM modulation, and power management.
</p>

---

## 🔧 Hardware Components

- Arduino Nano microcontroller  
- JGA25 DC motors  
- TB6612FNG dual motor driver  
- BLE Bluetooth module (UART)  
- 2‑cell Li‑Po battery (6–7.4 V)  
- DC‑DC step‑down voltage regulator  
- Metal chassis  

---

## ⚙️ Communication and Control Concept

<p align="justify">
Wireless commands are transmitted via Bluetooth using serial (UART) communication. The Arduino Nano interprets received characters and translates them into motor speed and direction control signals. Pulse Width Modulation (PWM) is used to regulate motor speed, demonstrating signal modulation as discussed in the Communication 2 course.
</p>

---

## 📷 System Implementation

### RC Prototype

<p align="center">
  <img src="images/rc_prototype.jpg" width="450">
</p>

<p align="justify">
The image above shows the complete remote‑controlled robotic system with all electronic components installed on a compact metal chassis. The layout ensures stable operation, proper power distribution, and reliable signal interfacing.
</p>

---

### Actual Weight Measurement

<p align="center">
  <img src="images/rc_weight_measurement.jpg" width="450">
</p>

<p align="justify">
The image above shows the actual weight measurement of the complete system using a digital weighing scale. The measured weight of the system is <strong>475 grams</strong>, which includes the chassis, electronics, battery, and wiring in full operational condition.
</p>

<p align="justify">
This weight provides a balance between stability and portability, contributing to controlled movement and reliable operation for a compact embedded communication system.
</p>

---

## 🧠 Control Software

<p align="justify">
The control program is written in Arduino C/C++ and implements Bluetooth‑based command reception, pulse‑based motion control, speed adjustment via live slider input, and PID‑assisted turning correction. The software demonstrates serial communication, signal timing, and PWM motor control.
</p>

📂 **Source File:** `src/rc_control.ino`

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


---

## ✅ Project Status

✔ Bluetooth communication implemented  
✔ Motor driver control verified  
✔ PWM speed modulation functional  
✔ System weight validated (475 g)  
✔ Communication 2 requirement completed
