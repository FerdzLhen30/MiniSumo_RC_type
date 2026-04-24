# MiniSumo_RC_type
A Communication 2 course project demonstrating an embedded control and wireless communication system using an Arduino Nano, BLE Bluetooth module, and motor driver integration.
# Autonomous Communication System Project

## 📌 Overview

<p align="justify">
<strong>Purpose:</strong> This project was developed as a major course requirement for the subject <strong>Communication 2</strong>. It is designed to apply theoretical concepts of modulation, signal transmission, control, and system integration into a practical hardware‑based implementation.
</p>

<p align="justify">
The project implements a compact embedded communication and control system using a microcontroller‑based platform. It emphasizes the practical use of electronic communication principles such as signal interfacing, power regulation, control signaling, and wireless data transmission. The system demonstrates how communication concepts are translated into real‑world applications using embedded hardware.
</p>

<p align="justify">
An Arduino Nano microcontroller serves as the central processing unit, handling control signals and communication tasks. Motor control is implemented through a TB66FNG dual motor driver paired with JGA25 DC motors, demonstrating signal control and power amplification concepts. A 2‑cell Li‑Po battery supplies the system, while a step‑down voltage regulator ensures stable voltage levels for logic and communication modules. Wireless communication is incorporated using a BLE Bluetooth module, enabling serial data transmission, remote control, and system monitoring.
</p>

---

## Table of Contents
- Part 1: System Planning  
- Part 2: Hardware and Communication Components  
- Part 3: Control and Communication Strategy  

---

## Part 1: System Planning

<p align="justify">
The planning phase focuses on applying Communication 2 concepts to the design of a complete embedded system. This stage defines the interaction between power electronics, control signals, and wireless communication modules while ensuring electrical compatibility and stable operation.
</p>

<p align="justify">
Careful planning was conducted to select components suitable for signal processing, motor actuation, and wireless data transmission. The Arduino Nano was chosen for its compact size and UART communication capability, while the BLE Bluetooth module was selected to demonstrate short‑range wireless communication. Power management and signal integrity were considered to avoid voltage instability and communication errors.
</p>

<p align="justify">
This phase also defines the system’s operational flow, including command transmission, signal interpretation, and actuator response. By organizing the communication and control structure early in the design, the system ensures reliable performance and clear demonstration of communication principles covered in the subject.
</p>

---

## Part 2: Hardware and Communication Components

### 2.1 Components Used
- Arduino Nano microcontroller  
- JGA25 DC motors  
- TB66FNG dual motor driver  
- 2‑cell Li‑Po battery  
- Step‑down voltage regulator  
- BLE Bluetooth module  

<p align="justify">
Each component was selected to illustrate core communication system concepts such as signal transmission, voltage regulation, and data interfacing. The BLE module enables serial communication over a wireless medium, while the motor driver converts low‑power control signals into high‑power outputs.
</p>

---

## Part 3: Control and Communication Strategy

<p align="justify">
The control strategy is based on serial communication between the BLE Bluetooth module and the Arduino Nano. Commands are transmitted wirelessly and decoded by the microcontroller, which then generates appropriate control signals for motor actuation. Pulse Width Modulation (PWM) is used to regulate motor speed, demonstrating signal modulation techniques discussed in Communication 2.
</p>

<p align="justify">
This design highlights the relationship between digital communication signals and physical system behavior. By integrating wireless communication, signal processing, and actuation, the project serves as a practical demonstration of communication system concepts applied to an embedded environment.
</p>

---

## Project Status
✔ Communication system implemented  
✔ Wireless serial transmission verified  
✔ Control signals successfully applied  
✔ Course requirement completed
