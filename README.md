# Embedded Wireless Communication System

## 📌 Overview

<p align="justify">
<strong>Purpose:</strong> This project was developed as a major course requirement for the subject <strong>Communication 2</strong>. The objective is to apply fundamental communication and control concepts through the implementation of an embedded wireless system.
</p>

<p align="justify">
The system is a compact remote‑controlled robotic platform that demonstrates practical use of serial communication, wireless data transmission, power regulation, and actuator control. It integrates a microcontroller, motor driver, power management circuitry, and a Bluetooth Low Energy (BLE) module to convert wireless control signals into physical motion.
</p>

<p align="justify">
An Arduino Nano serves as the central controller, processing incoming wireless commands and generating control signals for motor actuation. Power is supplied using a 2‑cell lithium‑polymer (Li‑Po) battery regulated through a step‑down voltage converter to ensure safe and stable operation of the electronics. This project highlights the relationship between communication signals and real‑world system behavior, fulfilling the learning outcomes of the Communication 2 subject.
</p>

---

## 🔧 Hardware Components

- Arduino Nano microcontroller  
- JGA25 DC motors  
- TB66FNG dual motor driver  
- BLE Bluetooth communication module  
- 2‑cell Li‑Po battery (6–7.4 V)  
- DC‑DC step‑down voltage regulator  
- Metal chassis  

---

## ⚙️ Communication and Control Concept

<p align="justify">
Wireless commands are transmitted from an external controller to the robot via the BLE Bluetooth module using serial (UART) communication. The Arduino Nano decodes the received data and generates Pulse Width Modulation (PWM) signals to control the speed and direction of the DC motors through the motor driver.
</p>

<p align="justify">
This design demonstrates key Communication 2 concepts such as signal transmission, modulation using PWM, digital data decoding, and signal amplification for actuator control.
</p>

---

## 📷 System Implementation

### RC Prototype

<p align="center">
  <img src="images/rc_prototype.jpg" width="500">
</p>

<p align="justify">
The image above shows the fully assembled remote‑controlled robotic system. All electronic components are mounted on a compact metal chassis with a low center of gravity to provide mechanical stability. The layout allows efficient wiring, reliable power delivery, and proper signal interfacing between communication and control modules.
</p>

---

### Actual Weight Measurement

<p align="center">
  <img src="images/rc_weight_measurement.jpg" width="500">
</p>

<p align="justify">
The image above shows the actual weight measurement of the completed system using a digital weighing scale. The recorded weight of the robot is <strong>475 grams</strong>. This measurement includes the chassis, microcontroller, motor driver, Bluetooth module, voltage regulator, battery, and all associated wiring in their fully operational configuration.
</p>

<p align="justify">
Maintaining a total system weight of 475 grams provides a good balance between mechanical stability and portability. The mass distribution improves traction and controlled motion while remaining suitable for a compact embedded system developed for the Communication 2 course.
</p>

---

## ✅ Project Status

✔ Wireless communication implemented  
✔ Motor control verified  
✔ Power regulation stable  
✔ System weight validated (475 g)  
✔ Communication 2 requirement completed
