#include "lcd.h"
#include "led.h"



void lcd_init(void)
{
    MX_I2C4_Init();
    lcd_delay(100); // Wait for LCD to power up

    // Initialization sequence
    lcd_write_nibble(0x30, 0x00);
    lcd_delay(50);
    lcd_write_nibble(0x30, 0x00);
    lcd_delay(50);
    lcd_write_nibble(0x30, 0x00);
    lcd_delay(50);
    lcd_write_nibble(0x20, 0x00); // Set to 4-bit mode
    lcd_delay(50);

    

    lcd_send_cmd(0x28); // 4-bit, 2 line, 5x8 dots
    lcd_send_cmd(0x10); // Display off
    lcd_send_cmd(0x0F); // Clear display
    lcd_delay(50);
    lcd_send_cmd(0x06); // Entry mode
    lcd_send_cmd(0x0C); // Display on, cursor off, blink off
}


void lcd_write_nibble(uint8_t nibble, uint8_t control)
{
    uint8_t data = (nibble & 0xF0) | control | LCD_BACKLIGHT;
    uint8_t data_e = data | LCD_ENABLE;
    HAL_I2C_Master_Transmit(&hi2c4, LCD_ADDR, &data_e, 1, HAL_MAX_DELAY);
    HAL_Delay(1);
    HAL_I2C_Master_Transmit(&hi2c4, LCD_ADDR, &data, 1, HAL_MAX_DELAY);
    HAL_Delay(1);
}

void lcd_send_internal(uint8_t data, uint8_t mode)
{
    uint8_t high_nibble = data & 0xF0;
    uint8_t low_nibble = (data << 4) & 0xF0;

    lcd_write_nibble(high_nibble, mode);
    lcd_write_nibble(low_nibble, mode);
}

void lcd_send_cmd(uint8_t cmd)
{
    lcd_send_internal(cmd, 0x00);
}

void lcd_send_data(uint8_t data)
{
    lcd_send_internal(data, LCD_RS);
}

void lcd_send_string(char *str)
{
    while (*str)
    {
        lcd_send_data((uint8_t)(*str));
        str++;
    }
}


void lcd_delay(uint32_t ms) {
    HAL_Delay(ms);
}

void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hi2c->Instance==I2C4)
  {
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C4;
    PeriphClkInit.I2c4ClockSelection = RCC_I2C4CLKSOURCE_PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);
    HAL_PWREx_EnableVddIO2();
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;//was low freq
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C4;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    __HAL_RCC_I2C4_CLK_ENABLE();
  }

}

void MX_I2C4_Init(void)
{
  hi2c4.Instance = I2C4;
  hi2c4.Init.Timing = 0x00100D14;
  hi2c4.Init.OwnAddress1 = 0;
  hi2c4.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c4.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c4.Init.OwnAddress2 = 0;
  hi2c4.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c4.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c4.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  HAL_I2C_Init(&hi2c4);
  HAL_I2CEx_ConfigAnalogFilter(&hi2c4, I2C_ANALOGFILTER_ENABLE);
  HAL_I2CEx_ConfigDigitalFilter(&hi2c4, 0);

}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C4)
  {
    __HAL_RCC_I2C4_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_13);
  }
}

void HAL_I2C_MspPostInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hi2c->Instance==I2C4)
  {
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;//was low freq
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C4;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
  }
}
