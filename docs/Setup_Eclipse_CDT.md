# ⚙️ Eclipse Configuration for BL602 

This guide details the precise configuration paths needed within **Eclipse IDE for Embedded C/C++ Developers**.

## 1. Global Eclipse Preferences

This step configures the entire Eclipse instance to use the newly installed MSYS2 tools.

1.  Go to **Window > Preferences**.
2.  Navigate to **MCU > Global Build Tools Path**.
3.  Click **Browse** and set the path to your MSYS2 binaries:
    * **Path:** `C:\msys64\usr\bin` (or your installation's equivalent)
4.  Navigate to **MCU > Global RISC-V Toolchain Paths**.
5.  Click **Browse** and set the path to the compiler within your SDK folder:
    * **Path:** `[Your SDK Root]\toolchain\riscv\msys` (This path points to the specific toolchain directory inside the Bouffalo Lab SDK).
6.  Click **Apply and Close**.

## 2. Creating and Importing the Project

We import the SDK examples as **Makefile Projects**.

1.  Go to **File > New > Makefile Project with Existing Code**.
2.  In the wizard:
    * **Project name:** Enter a name (e.g., `bl602_blink`).
    * **Existing Code Location:** Click **Browse** and select the root of your example (e.g., `[Your SDK Root]/applications/get-started/blink`).
    * **Toolchain for Indexer Settings:** Select **RISC-V Cross GCC**.
3.  Click **Finish**.

## 3. Project-Specific Build Settings (Crucial)

We must override the default build command to use the SDK's internal `Makefile`.

1.  Right-click the new project (`bl602_blink`) and select **Properties** (or press Alt+Enter).
2.  Navigate to **C/C++ Build**.
3.  **Uncheck** "Use default build command."
4.  Set the **Build command** to: `make` (or `make -j8` if you want to use multiple cores for faster compilation).
5.  Navigate to the **Behavior** tab.
6.  **Clean Command:** Change the default entry to `clean`.
7.  **Build (Incremental) Command:** Change the default entry to **`flash`**.
    * *This step is a shortcut for the combined build and flash command often set up in the SDK's Makefiles.*
8.  Click **Apply and Close**.

## 4. First Build

* **Clean:** Right-click the project, select **Clean Project**.
* **Build:** Right-click the project, select **Build Project**. This will compile the code and generate the `.bin` file in the build output folder.
