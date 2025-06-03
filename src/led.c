/*==============================================================================
* led.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/9/2025
* University of Delaware
 * This file allows you to change the state of the 8 LEDs in various ways
==============================================================================*/

#include "led.h"

/*
led_init();

Inputs:
    None
Returns:
    None

Initiates all LED pins to outputs. Call this function before using the LEDs.
*/
void led_init(){
    //Initiate all pins for LED AS output
    //Tip: Hover your cursor over "gpio_init_pin" to see a description of that function.
    gpio_init_pin(PORT_F, 5, FALSE);
    gpio_init_pin(PORT_F, 6, FALSE);
    gpio_init_pin(PORT_F, 7, FALSE);
    gpio_init_pin(PORT_G, 0, FALSE);
    gpio_init_pin(PORT_G, 1, FALSE);
    gpio_init_pin(PORT_F, 14, FALSE);
    gpio_init_pin(PORT_F, 15, FALSE);
    gpio_init_pin(PORT_E, 7, FALSE);
}

/*
led_set();

Inputs:
    pos - an integer value from 0 to 7 indicating which led you want to set
    value - a integer value which is either 0 or 1. 0 turns the LED off, 1 turns the LED on 
Returns:
    None

Controls individual leds, turning them on or off.
*/
void led_set(char pos, char value){
    //match the position of the led to its address(Port and Pin Number)
    //then set it as value (0 or FALSE for off, 1 or TRUE for on)
	switch (pos){
	case 0:
        gpio_set_pin(PORT_F, 5, value);
		break;
	case 1:
        gpio_set_pin(PORT_F, 6, value);
		break;
	case 2:
        gpio_set_pin(PORT_F, 7, value);
		break;
	case 3:
        gpio_set_pin(PORT_G, 0, value);
		break;
	case 4:
        gpio_set_pin(PORT_G, 1, value);
		break;
	case 5:
        gpio_set_pin(PORT_F, 14, value);
		break;
	case 6:
        gpio_set_pin(PORT_F, 15, value);
		break;
	case 7:
        gpio_set_pin(PORT_E, 7, value);
		break;
	}
}

/*
led_set_group();

Inputs:
    value - a eight bit value, which is treated as an array of eight bits. 
Returns:
    None

Allows the leds to be set in the group. Each position bit of the value will corresponed with an led.
For example, entering 0b10000000 will turn only the first led on.

NOTE: This function can be used to replace the functionality of LATA from prior CPEG222 semesters.
*/

void led_set_group(char value){

    //set the bits to each LED
    led_set(0, value & (1 << 7));
    led_set(1, value & (1 << 6));
    led_set(2, value & (1 << 5));
    led_set(3, value & (1 << 4));
    led_set(4, value & (1 << 3));
    led_set(5, value & (1 << 2));
    led_set(6, value & (1 << 1));
    led_set(7, value & (1 << 0));
}