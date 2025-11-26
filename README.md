# 🚀 Ai-WB2-32S Kit Reference Guide: Unlocking the BL602 RISC-V Microcontroller

This repository serves as a comprehensive, English-language reference guide for the **Ai-WB2-32S Development Kit**, featuring the powerful **Bouffalo Lab BL602 RISC-V** chip.

The official documentation is often in Chinese and relies on advanced tools. This guide breaks down the process of setting up the necessary **RISC-V toolchain** and configuring the **Eclipse IDE (CDT)** to simplify development.

---

## 🗺️ Hardware Pinout Quick Reference

For immediate connection and development, here is a visual reference of the Ai-WB2-32S module pinout. Note the location of key pins like **VCC (3V3)**, **GND**, and the **Boot/Download Pin (GPIO8)** needed for flashing.

<img width="1228" height="664" alt="image" src="https://github.com/user-attachments/assets/f6b26080-1197-4fd0-a0fd-9c7e3085dcef" />


*(For a detailed table of peripherals, see `docs/Hardware_Reference.md`)*

## ✨ Key Features of the BL602 Chip

The BL602 is a highly capable chip that offers competitive features for IoT development:

* **Core:** 32-bit RISC-V CPU.
* **Connectivity:** Integrated **Wi-Fi 802.11 b/g/n** and **Bluetooth Low Energy (BLE)** 5.0.
* **Security:** Supports ECC-256 Secure Startup, AES, SHA, and WPA3.
* **Development Framework:** Uses the **BL\_IOT\_SDK** and the **CMake** build system.

## 🏁 Quick Start Guide

Ready to get started? Here are the three main steps to flash your first program:

1.  **Install Toolchain & SDK:** Set up the required RISC-V compiler and clone the SDK. (See `docs/Setup_Toolchain.md`)
2.  **Configure Eclipse CDT:** Import an example project and set the build environment variables. (See `docs/Setup_Eclipse_CDT.md`)
3.  **Build & Flash:** Compile your code and use the **BLDevCube** utility to upload it to the board. (See `docs/Flashing_Guide.md`)

---

## 📚 Guide Index

| File | Description | Focus |
| :--- | :--- | :--- |
| `docs/Hardware_Reference.md` | Detailed pinout, LED/Button mapping, and power specifications. | **Hardware/Pinout** |
| `docs/Setup_Toolchain.md` | Step-by-step instructions for installing the RISC-V compiler, CMake, and the SDK. | **Prerequisites** |
| `docs/Setup_Eclipse_CDT.md` | How to configure Eclipse CDT for the BL602's CMake/Makefile-based build system. | **IDE Setup** |
| `docs/Flashing_Guide.md` | The exact procedure for using the official **BLDevCube** utility and the video-verified flash sequence. | **Deployment** |
| `examples/01_blink/README.md` | The first working example code (with verified pins). | **Code Example** |
