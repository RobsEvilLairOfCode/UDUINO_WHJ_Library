#include "uduino_config.h"

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5
#define PORT_G 6

/*
gpio_init();

Inputs:
    None
Returns:
    None

When using GPIO, always call this function first before doing anything else.
*/
void gpio_init();

/*
gpio_init_pin();

Inputs:
    port: Which port the pin you are trying to initiate is one.
        see gpio.h for definitions.
    pin: The pin number you are trying to initiate. You can enter the number directly
    as_input: A boolean value of whether the pin should be initialized as an input or an output
                0 - output
                1 - input
Returns:
    None

When using GPIO, always call this function first before doing anything else.
*/
void gpio_init_pin(char, char, char);

void gpio_set_pin(char, char, char);

char gpio_read_pin(char, char);