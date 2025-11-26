**
 * @file main.c
 * @brief Wi-Fi Clock with SNTP and OLED (F-91W Style)
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <FreeRTOS.h>
#include <task.h>
#include <blog.h>
#include <aos/yloop.h>
#include <aos/kernel.h>
#include <lwip/tcpip.h>
#include <wifi_mgmr_ext.h>
#include <hal_wifi.h>
#include <lwip/apps/sntp.h> // Standard SNTP header
#include <hosal_i2c.h>
#include <u8g2.h>

// --- USER CONFIGURATION ---
#define ROUTER_SSID "YOUR_WIFI_SSID"
#define ROUTER_PWD  "YOUR_WIFI_PASSWORD"
#define TIMEZONE_OFFSET (5.5 * 3600) // Example: UTC+5:30 (India)

// --- OLED HARDWARE CONFIGURATION ---
#define OLED_I2C_SCL 12
#define OLED_I2C_SDA 3
#define OLED_I2C_FREQ 100000

// --- GLOBALS ---
static wifi_conf_t conf = {
    .country_code = "CN",
};

static hosal_i2c_dev_t i2c0 = {
    .config = {
        .address_width = HOSAL_I2C_ADDRESS_WIDTH_7BIT,
        .freq = OLED_I2C_FREQ,
        .mode = HOSAL_I2C_MODE_MASTER,
        .scl = OLED_I2C_SCL,
        .sda = OLED_I2C_SDA,
    },
    .port = 0,
};

// --- u8g2 Hardware Abstraction Layer (HAL) ---
// Bridges the graphics library to the BL602 hardware I2C
uint8_t u8x8_byte_bl602_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    static uint8_t buffer[32];
    static uint8_t buf_idx;
    uint8_t *data;

    switch(msg) {
        case U8X8_MSG_BYTE_SEND:
            data = (uint8_t *)arg_ptr;
            while( arg_int > 0 ) {
                buffer[buf_idx++] = *data;
                data++;
                arg_int--;
            }
            break;
        case U8X8_MSG_BYTE_INIT:
        case U8X8_MSG_BYTE_START_TRANSFER:
            buf_idx = 0;
            break;
        case U8X8_MSG_BYTE_END_TRANSFER:
            hosal_i2c_master_send(&i2c0, u8x8_GetI2CAddress(u8x8) >> 1, buffer, buf_idx, 1000);
            break;
        default: return 0;
    }
    return 1;
}

uint8_t u8x8_gpio_and_delay_bl602(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch(msg) {
        case U8X8_MSG_DELAY_MILLI: vTaskDelay(arg_int / portTICK_PERIOD_MS); break;
        default: return 0;
    }
    return 1;
}

// --- CLOCK TASK ---
// This task runs the display loop
void clock_task(void *pvParameters) {
    // 1. Initialize Hardware
    hosal_i2c_init(&i2c0);
    
    // 2. Initialize OLED
    u8g2_t u8g2;
    u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_bl602_hw_i2c, u8x8_gpio_and_delay_bl602);
    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);

    // 3. Wait for valid time
    time_t now = 0;
    struct tm timeinfo = { 0 };
    char str_time[16];
    char str_date[32];
    char str_sec[4];

    while (1) {
        time(&now);
        
        // Check if time is valid (year > 2020)
        localtime_r(&now, &timeinfo);
        
        u8g2_ClearBuffer(&u8g2);
        u8g2_DrawFrame(&u8g2, 0, 0, 128, 64);
        u8g2_DrawHLine(&u8g2, 0, 45, 128);

        if (timeinfo.tm_year < (2022 - 1900)) {
            // Time not set yet
            u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);
            u8g2_DrawStr(&u8g2, 10, 30, "Syncing Time...");
        } else {
            // Apply Timezone Manually if needed (or use setenv TZ)
            now += TIMEZONE_OFFSET;
            localtime_r(&now, &timeinfo);

            // Draw Time (Large)
            sprintf(str_time, "%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min);
            u8g2_SetFont(&u8g2, u8g2_font_logisoso32_tn);
            u8g2_DrawStr(&u8g2, 5, 35, str_time);

            // Draw Seconds (Small)
            sprintf(str_sec, ":%02d", timeinfo.tm_sec);
            u8g2_SetFont(&u8g2, u8g2_font_luBIS14_tn);
            u8g2_DrawStr(&u8g2, 100, 35, str_sec);

            // Draw Date
            strftime(str_date, sizeof(str_date), "%a %b %d", &timeinfo);
            u8g2_SetFont(&u8g2, u8g2_font_6x10_tf);
            u8g2_DrawStr(&u8g2, 15, 58, str_date);
        }
        
        u8g2_SendBuffer(&u8g2);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

// --- WI-FI & SNTP LOGIC ---

static void start_sntp() {
    blog_info("Starting SNTP...");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
}

static void wifi_sta_connect(char* ssid, char* password) {
    wifi_interface_t wifi_interface;
    wifi_interface = wifi_mgmr_sta_enable();
    wifi_mgmr_sta_connect(wifi_interface, ssid, password, NULL, NULL, 0, 0);
}

static void event_cb_wifi_event(input_event_t* event, void* private_data) {
    switch (event->code) {
        case CODE_WIFI_ON_INIT_DONE:
            blog_info("[APP] [EVT] INIT DONE %lld", aos_now_ms());
            wifi_mgmr_start_background(&conf);
            break;
        case CODE_WIFI_ON_MGMR_DONE:
            blog_info("[APP] [EVT] MGMR DONE %lld", aos_now_ms());
            wifi_sta_connect(ROUTER_SSID, ROUTER_PWD);
            break;
        case CODE_WIFI_ON_GOT_IP:
            blog_info("[APP] [EVT] GOT IP %lld", aos_now_ms());
            // Wi-Fi Connected -> Start SNTP
            start_sntp();
            break;
        case CODE_WIFI_ON_DISCONNECT:
            blog_info("[APP] [EVT] disconnect %lld", aos_now_ms());
            // Optional: Retry logic could go here
            break;
        default:
            // Ignore other events to keep log clean
            break;
    }
}

static void proc_main_entry(void* pvParameters) {
    aos_register_event_filter(EV_WIFI, event_cb_wifi_event, NULL);
    hal_wifi_start_firmware_task();
    aos_post_event(EV_WIFI, CODE_WIFI_ON_INIT_DONE, 0);
    
    // Start the Clock Display Task immediately
    // It will show "Syncing..." until SNTP updates the system time
    xTaskCreate(clock_task, "clock_task", 2048, NULL, 10, NULL);
    
    vTaskDelete(NULL);
}

static void system_thread_init() {
    /* nothing here */
}

void main() {
    system_thread_init();
    puts("[OS] Starting TCP/IP Stack...");
    tcpip_init(NULL, NULL);
    puts("[OS] proc_main_entry task...");
    xTaskCreate(proc_main_entry, (char*)"main_entry", 1024, NULL, 15, NULL);
}
