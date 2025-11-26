# ⚙️ Eclipse Configuration for BL602 (Ai-WB2-32S)

The BL602 SDK relies on a **RISC-V cross-compiler** and **CMake** to manage the build process. This guide details how to configure the **Eclipse IDE for C/C++ Developers (CDT)** to handle this toolchain.

## 1. Install and Prepare Eclipse

1.  **Download and Install:** Download the latest version of the **Eclipse IDE for Embedded C/C++ Developers**.
2.  **Start Workspace:** Launch Eclipse and select a clean workspace folder (e.g., `~/bl602_workspace`).

## 2. Setting Up a New CMake Project

The most reliable way to integrate the SDK is by using the **Makefile Project** option, then manually configuring the build command, as the SDK often provides its own build scripts.

1.  Go to **File > New > C/C++ Project**.
2.  In the wizard:
    * **Project name:** Enter the name of the example you are importing (e.g., `bl602_blink`).
    * **Project type:** Expand **Makefile Project** and choose **Empty Project**.
    * **Toolchains:** Select **<none>** for now, as we will configure the RISC-V toolchain manually.
3.  Click **Finish**.

## 3. Configuring Project Properties

### A. Define the RISC-V Toolchain

We need to tell the project where the compiler is located.

1.  Right-click the new project (`bl602_blink`) and select **Properties**.
2.  Navigate to **C/C++ Build > Tool Chain Editor**.
3.  Set the **Current toolchain** to **"Cross GCC"**.
4.  Go back to the left menu and select **C/C++ Build > Settings**.
5.  Under the **Tool Settings** tab, navigate to **Cross GCC Compiler** and **Cross GCC Linker**.
    * **Command:** Change the command prefix from `riscv-none-embed-` (or similar) to **`riscv64-unknown-elf-`**.
    * **Path:** Ensure the path points to your `riscv64-unknown-elf-gcc` `bin` directory (as set in `Setup_Toolchain.md`).

### B. Configure the Build Command

This is the critical step that links Eclipse to the SDK's CMake/Make build system.

1.  In **Project Properties**, navigate to **C/C++ Build**.
2.  **Uncheck** "Use default build command."
3.  Set the **Build command** to:
    ```bash
    make -j8
    ```
4.  Set the **Build directory** to the location of your example project's root folder (where the `CMakeLists.txt` is located).
    * *Example:* If your workspace is `~/bl602_workspace`, the path might be `~/bl602_workspace/BL_IOT_SDK/examples/blink`.
    * 

### C. Set Environment Variables

The SDK may rely on environment variables to find the toolchain or source files.

1.  In **Project Properties**, navigate to **C/C++ Build > Environment**.
2.  Add a new variable to specify the toolchain root:
    | Name | Value |
    | :--- | :--- |
    | **TOOLCHAIN\_PATH** | `[Path to the parent folder of your RISC-V toolchain]` |

### 4. Code Navigation and Indexer

To ensure code completion and file indexing work correctly (so Eclipse knows where to find the SDK files):

1.  In **Project Properties**, navigate to **C/C++ General > Paths and Symbols**.
2.  In the **Includes** tab, add the paths to the SDK's core include directories (e.g., `BL_IOT_SDK/components/include`, `BL_IOT_SDK/drivers/include`, etc.). This tells the Eclipse Indexer where the headers are located.

## 5. First Build

1.  Select your project in the **Project Explorer**.
2.  Click the **"hammer" (Build)** icon in the toolbar.
3.  The **Console** window should now show the output of the `make -j8` command.
4.  Upon success, the binary file (`.bin`) and the ELF file (`.elf`) will be generated in the output folder specified by the SDK (usually `out` or `build`).
