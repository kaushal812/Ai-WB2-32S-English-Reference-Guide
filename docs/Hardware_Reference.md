# 📌 Ai-WB2-32S Hardware Reference

This document provides essential hardware specifications and pinout information for the Ai-WB2-32S development kit based on the BL602 chip.

## 1. Key Specifications

| Feature | Specification |
| :--- | :--- |
| **CPU Core** | 32-bit RISC-V |
| **RAM / Flash** | 276KB RAM / External QSPI Flash |
| **Connectivity** | Wi-Fi 802.11 b/g/n, Bluetooth BLE 5.0, Bluetooth Mesh |
| **Wi-Fi Speed** | Max 72.2 Mbps (20MHz bandwidth) |
| **Security** | AES-128/192/256, SHA-1/224/256, ECC-256 (Secure Startup) |
| **Low Power Mode** | Deep Sleep Current: 12μA |
| **Package** | DIP-38 (Form Factor of the dev board) |

## 2. Peripheral Support

The BL602 is rich in peripherals for IoT applications:

* **Communication:** SDIO, SPI, **UART** (multiple), IR remote.
* **Analog/Control:** **PWM**, **ADC**, **DAC**.
* **Sensing:** **PIR** (Passive Infrared) support.
* **Integrated Components:** Wi-Fi MAC/BB/RF/PA/LNA/BT.

## 3. Ai-WB2-32S Pinout Diagram

Below is a partial mapping of the most common header pins. Always refer to the official datasheet for the complete pin multiplexing options.

| Header Pin | BL602 Pin Name | Primary Function | Notes |
| :--- | :--- | :--- | :--- |
| **VCC** | - | 3.3V Power Input | Connect to power supply. |
| **GND** | - | Ground | Common Ground. |
| **TXD0** | U0\_TX | UART 0 Transmit | Primary Serial Console Output. |
| **RXD0** | U0\_RX | UART 0 Receive | Primary Serial Console Input. |
| **GPIO 0** | GPIO0 | General Purpose I/O | Common control/data pin. |
| **GPIO 8** | GPIO8 | General Purpose I/O | **Boot Pin**: Must be pulled LOW during flashing. |
| **GPIO 11** | GPIO11 | General Purpose I/O | Often used for the on-board LED. |
| **ADC 0** | ADC0 | Analog Input | Used for analog sensing. |
| **SPI CS** | SPI\_CS | SPI Chip Select | Used for external flash/peripherals. |
