# 📌 Ai-WB2-32S Hardware Reference

This document provides essential hardware specifications and pinout information for the Ai-WB2-32S development kit based on the BL602 chip.

## 1. Key Specifications

| Feature | Specification |
| :--- | :--- |
| **CPU Core** | 32-bit RISC-V |
| **Connectivity** | Wi-Fi 802.11 b/g/n, Bluetooth BLE 5.0, Bluetooth Mesh |
| **Security** | AES-128/192/256, SHA-1/224/256, ECC-256 (Secure Startup) |
| **Low Power Mode** | Deep Sleep Current: 12μA |
| **Package** | DIP-38 (Development Board Form Factor) |

## 2. On-Board Peripheral Mapping (Verified via Schematic)

| Component | BL602 GPIO Pin | Function/Notes |
| :--- | :--- | :--- |
| **On-board Red LED** | **GPIO 14** | Connected to the RGB driver chip (R channel). |
| **On-board Blue LED** | **GPIO 13** | Connected to the RGB driver chip (B channel). |
| **On-board Green LED** | **GPIO 12** | Connected to the RGB driver chip (G channel). |
| **Boot Pin** | **GPIO 8** | Must be pulled LOW during flashing sequence. |
| **KEY1 Button** | **GPIO 10** | User programmable button. |
| **KEY2 Button** | **GPIO 2** | User programmable button. |
| **Primary Serial** | U0\_TX/U0\_RX | UART 0 (Used for flashing and console output). |

## 3. Peripheral Support

The BL602 is rich in peripherals for IoT applications:

* **Communication:** SDIO, SPI, **UART** (multiple), IR remote.
* **Analog/Control:** **PWM**, **ADC**, **DAC**.
* **Sensing:** **PIR** (Passive Infrared) support.
