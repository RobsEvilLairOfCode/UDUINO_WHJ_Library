#include "gpio.h"

// Replace this with your actual I2C handle
I2C_HandleTypeDef hi2c4;

#define LCD_ADDR         (0x20 << 1)  // Usually 0x27 or 0x3F
#define LCD_BACKLIGHT    0x08
#define LCD_ENABLE       0x04
#define LCD_RW           0x00        // We tie RW low
#define LCD_RS           0x01

void lcd_send_cmd(uint8_t cmd);
void lcd_send_data(uint8_t data);
void lcd_send_string(char *str);
void lcd_init(void);
void lcd_delay(uint32_t ms);

// Internal helpers
void lcd_send_internal(uint8_t data, uint8_t mode);
void lcd_write_nibble(uint8_t nibble, uint8_t control);
void MX_I2C4_Init(void);
