# 🛠️ Toolchain and SDK Installation (Video Verified Steps)

This document details the required software prerequisites for developing on the BL602 chip, following the widely-accepted community tutorial workflow.

## 1. MSYS2: The Build Environment

The BL602 SDK relies on Linux-like tools. We use **MSYS2** to provide the `make` utility and a proper shell environment.

1.  **Download & Install MSYS2:** Go to [msys2.org](https://www.msys2.org/) and download the installer. Use the default installation path (usually `C:\msys64`).
2.  **Install the Build Tool (`make`):** After installation, launch the **MSYS2 MinGW 64-bit** terminal and run the following command:
    ```bash
    pacman -S make
    ```
    *When prompted, type 'y' and press Enter to confirm the installation.*

## 2. Environment Variables (Critical)

These variables tell the system and Eclipse where to find the tools.

1.  **Open System Environment Variables** (Windows Key + R, type `control panel`, search for `env`).
2.  Under **User variables**, click **New...**
    * **Variable name:** `MSYS2_PATH_TYPE` (must be all uppercase)
    * **Variable value:** `inherit` (must be all lowercase)
3.  Under **System variables**, find and select the **Path** variable, then click **Edit...**
4.  Add the path to the MSYS2 binaries:
    * **Path:** `C:\msys64\usr\bin` (or your installation's equivalent)

## 3. RISC-V GNU Toolchain

This is the cross-compiler for the chip. This toolchain should come as part of the SDK structure.

1.  **SDK Clone:** Clone the SDK structure, which contains the toolchain folder:
    ```bash
    git clone --recursive [https://github.com/bouffalolab/bl_iot_sdk](https://github.com/bouffalolab/bl_iot_sdk)
    ```
2.  **Flashing Tool:** Download the official **Bouffalo Lab Dev Cube** for easy firmware uploading (recommended).

## 4. Serial Monitor (Termite)

We use a simple serial program like **Termite** to view the chip's output (debugging logs).

1.  **Download and Install:** Download **Termite** (or any preferred terminal emulator).
2.  **Configuration:** Once your board is plugged in, determine its **COM port** in **Device Manager**. In Termite, set the port and set the **Baud Rate to 115200** (a standard debugging speed for the BL602).
