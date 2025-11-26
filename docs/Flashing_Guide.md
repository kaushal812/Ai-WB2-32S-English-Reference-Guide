# 🔥 Flashing and Deployment Guide

This guide details the process of uploading your compiled firmware (`.bin` file) to the Ai-WB2-32S board.

## 1. Method A: The Eclipse One-Click Flash (Recommended)

The SDK's Makefile is often configured to combine the build and flashing steps into one command.

1.  **Ensure Termite (or your serial monitor) is running and connected** to the correct COM port.
2.  **In Eclipse, right-click the project and select Build Project.**
3.  **WATCH THE CONSOLE CLOSELY.** The console output will quickly compile the code, then stop and wait for a prompt (e.g., "Please press reset key...").
4.  **When the log indicates the board is waiting:**
    * **Immediately press the RESET button** on your Ai-WB2-32S kit.
5.  The build system will then detect the board in programming mode, and the flashing will proceed automatically.

## 2. Method B: Using BLDevCube (Manual)

If Method A fails, or if you prefer a GUI tool, use the official Bouffalo Lab Dev Cube:

1.  **Board Preparation (Programming Mode):**
    * Press and **HOLD** the **BOOT/DOWNLOAD** button.
    * While holding BOOT, press and **release** the **RESET** button.
    * Now, **release** the **BOOT/DOWNLOAD** button.
2.  **In BLDevCube:**
    * Select the chip: **BL602/BL604**.
    * Select the correct **COM Port** and **Baud Rate** (115200 is safest).
    * Load the required files (`partition.bin`, `boot2_isp_bl602_vX.X_rcX.bin`, and your compiled `blink.bin`).
3.  **Flashing:** Click the **"Create&Download"** button. The firmware will upload.

## 3. Running the Firmware

After the download succeeds (either method), click the **RESET** button on the board one more time. The firmware will boot, and you should see the serial output in your Termite window.
