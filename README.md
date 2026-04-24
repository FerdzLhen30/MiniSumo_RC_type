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

<img width="1113" height="1280" alt="image" src="https://github.com/user-attachments/assets/53fcb221-73a6-4ee0-91a6-2cebc6749fd9" />

<p align="justify">
The image above shows the complete remote‑controlled robotic system with all electronic components installed on a compact metal chassis. The layout ensures stable operation, proper power distribution, and reliable signal interfacing.
</p>

---

### Actual Weight Measurement

<img width="845" height="1280" alt="image" src="https://github.com/user-attachments/assets/1f869cbd-60d6-404a-95ce-a6d5e5fb84c2" />

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

---

## ✅ Project Status

✔ Bluetooth communication implemented  
✔ Motor driver control verified  
✔ PWM speed modulation functional  
✔ System weight validated (475 g)  
✔ Communication 2 requirement completed
