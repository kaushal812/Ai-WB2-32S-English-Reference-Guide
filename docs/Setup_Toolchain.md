# 🛠️ Toolchain and SDK Installation

This document details the required software prerequisites for developing on the BL602 chip.

## 1. RISC-V GNU Toolchain

The BL602 is a RISC-V architecture, requiring a specific cross-compiler.

1.  **Download:** Download the latest stable version of the **`riscv64-unknown-elf-gcc`** toolchain.
    * *(Tip: Search for "Bouffalo Lab toolchain" or use a reputable source like the SiFive/RISC-V official distribution.)*
2.  **Installation Path:** Install the toolchain to a short, simple path **without spaces** (e.g., `C:\riscv` on Windows).
3.  **PATH Variable:** **Crucially**, add the `bin` directory of your toolchain (e.g., `C:\riscv\riscv64-unknown-elf-gcc-xxx\bin`) to your operating system's **PATH environment variable**.
    * *Verification: Open a new terminal and run `riscv64-unknown-elf-gcc -v`. If it returns version information, the setup is correct.*

## 2. Build and Utility Tools

| Tool | Purpose | Installation Notes |
| :--- | :--- | :--- |
| **CMake** | The SDK uses CMake to manage the build files. | Download and install from the official site. **Ensure it is added to your PATH.** |
| **Git** | Used to clone the SDK and manage project versions. | Download and install Git. |
| **BLDevCube** | The official, proprietary GUI flashing utility. | Download the latest version of **Bouffalo Lab Dev Cube** for reliable firmware uploading. |
| **Serial Driver** | For the USB-to-UART converter (often CH340 or CP210x). | Install the appropriate driver for your board's serial chip if needed. |

## 3. Clone the SDK

The official SDK contains the necessary headers, libraries, and build scripts.

1.  Navigate to your chosen development directory.
2.  Clone the Bouffalo Lab SDK (or a stable community fork):
    ```bash
    git clone --recursive [https://github.com/bouffalolab/bl_iot_sdk](https://github.com/bouffalolab/bl_iot_sdk)
    ```
3.  Change into the SDK directory:
    ```bash
    cd BL_IOT_SDK
    ```

---

**Next Step:** Once all prerequisites are installed, we can configure Eclipse to recognize them in `docs/Setup_Eclipse_CDT.md`.
