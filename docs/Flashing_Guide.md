
# 🔥 Flashing and Deployment Guide

This guide details the process of uploading your compiled firmware (`.bin` file) to the Ai-WB2-32S board. The process requires a physical board manipulation to enter **Programming Mode** and the use of the official **BLDevCube** utility.

## 1. Board Preparation (Programming Mode)

The BL602 chip needs to be forced into a special state to accept new firmware. This is often done by controlling the state of the **Boot Pin (GPIO8)** while resetting the chip.

| Jumper/Button | Action for Flashing Mode |
| :--- | :--- |
| **Boot/Download Pin (GPIO8)** | **Hold LOW (GND)** |
| **Reset Pin** | Press **RESET** button while holding the **Boot Pin** low. |

**Steps to Enter Programming Mode:**

1.  Ensure the board is connected to your PC via a reliable USB cable.
2.  Press and **hold** the **BOOT/DOWNLOAD** button.
3.  While holding the BOOT button, press and **release** the **RESET** button.
4.  Now, **release** the **BOOT/DOWNLOAD** button.
5.  The board is now in programming mode and ready to accept the firmware.

## 2. Using the Bouffalo Lab Dev Cube (BLDevCube)

BLDevCube is the official, easiest way to flash your firmware.

1.  **Launch BLDevCube** and select the chip: **BL602/BL604**.
2.  **Select Serial Port:** Choose the correct COM/TTY port for your connected board.
3.  **Set Baud Rate:** Set the speed to **115200** or higher (up to **2000000** for faster uploads, if stable).
4.  **Load Image Files:** The flashing process requires multiple files from the SDK:
    * **Partition Table:** Load the `partition.bin` file from the SDK.
    * **Bootloader:** Load the `boot2_isp_bl602_vX.X_rcX.bin` file.
    * **Application Firmware:** Load your compiled file (e.g., `blink.bin` from your Eclipse output folder).
5.  **Flashing:** Click the **"Create&Download"** button. The utility will connect, erase the flash, and write the new files.

## 3. Running the Firmware

After the download succeeds, click the **RESET** button on the board. The firmware will boot, and you should see the program running (e.g., a blinking LED or serial output).

---
