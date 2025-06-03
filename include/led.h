#include "uduino_config.h"
#include "gpio.h"

/*
led_init();

Inputs:
    None
Returns:
    None

Initiates all LED pins to outputs. Call this function before using the LEDs.
*/
void led_init(void);

void led_set(char, char);

void led_set_group(char val);