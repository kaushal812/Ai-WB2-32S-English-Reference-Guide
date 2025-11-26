# ⌚ Wi-Fi "F-91W" Clock Example

This project turns your **Ai-WB2-32S** into a smart internet clock. It connects to your Wi-Fi network, fetches the precise time from an NTP server (like `pool.ntp.org`), and displays it on the OLED in a digital watch format.

## 🔌 Hardware Setup (I2C)

| OLED Pin | Ai-WB2-32S Pin |
| :--- | :--- |
| **SCL** | **IO 12** |
| **SDA** | **IO 3** |
| **VCC** | **3V3** |
| **GND** | **GND** |

## ⚙️ Configuration

Before compiling, you **MUST** edit `main.c` to set your Wi-Fi credentials:

```c
#define ROUTER_SSID "Your_WiFi_Name"
#define ROUTER_PWD "Your_WiFi_Password"
#define TIMEZONE_OFFSET (5.5 * 3600) // Adjust seconds for your timezone
