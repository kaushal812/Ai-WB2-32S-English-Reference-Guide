# 💡 01\_blink: Alternating LED Example (FreeRTOS)

This is the standard "Hello World" example for embedded systems, adapted for the **BL602 Ai-WB2-32S** using the **BL\_IOT\_SDK** and **FreeRTOS**.

**✅ SCHEMATIC VERIFICATION:** This code uses the correct on-board LED pins as verified from the kit's schematic: **GPIO 14** (Red) and **GPIO 13** (Blue).

## 1. Source Code: `main.c`

```c
#include <stdio.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <bl_gpio.h>

// Define GPIO pins for the LEDs (Verified via Schematic)
// R: Red, B: Blue, G: Green
#define GPIO_RED_LED 14   
#define GPIO_BLUE_LED 13  // Correct pin for the Blue LED on the Ai-WB2-32S-Kit

void blink_alternating(void *param)
{
    // red_value = 1 (ON), blue_value = 0 (OFF) on start
    uint8_t red_value = 1;
    uint8_t blue_value = 0;

    while (1)
    {
        // Set the output state of the LEDs
        bl_gpio_output_set(GPIO_RED_LED, red_value);
        bl_gpio_output_set(GPIO_BLUE_LED, blue_value);

        // Print the current state to the serial console
        printf("Red LED: %s, Blue LED: %s\r\n",
               red_value ? "ON" : "OFF",
               blue_value ? "ON" : "OFF");

        // Alternate the LED states for the next loop
        red_value = !red_value;
        blue_value = !blue_value;

        // Delay for 100 milliseconds
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

// Main function (entry point)
void main(void)
{
    // Initialize the GPIO pins for output and set initial state LOW (0)
    bl_gpio_enable_output(GPIO_RED_LED, 0, 0);
    bl_gpio_enable_output(GPIO_BLUE_LED, 0, 0);

    // Create the FreeRTOS task
    xTaskCreate(blink_alternating, "blink_alternating", 1024, NULL, 15, NULL);
}
