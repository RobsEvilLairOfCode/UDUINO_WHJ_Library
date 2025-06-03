/*==============================================================================
* swt.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/9/2025
* University of Delaware
 * This file allows you to set up various parts of the board, such as the icache
 * and system clock with ease.
==============================================================================*/

#include "button.h"

/*
led_init();

Inputs:
    None
Returns:
    None

Initiates all LED pins to outputs. Call this function before using the LEDs.
*/
void button_init(){
    //Initiate all pins for LED AS output
    //Tip: Hover your cursor over "gpio_init_pin" to see a description of that function.
    gpio_init_pin(PORT_F, 8, TRUE);
    gpio_init_pin(PORT_F, 9, TRUE);
    gpio_init_pin(PORT_F, 10, TRUE);
    gpio_init_pin(PORT_F, 11, TRUE);
    gpio_init_pin(PORT_F, 12, TRUE);
}

char button_read(char button){
    switch(button){
        case 'u':
            return gpio_read_pin(PORT_F, 8);
        break;
        case 'd':
            return gpio_read_pin(PORT_F, 11);
        break;
        case 'c':
            return gpio_read_pin(PORT_F, 12);
        break;
        case 'r':
            return gpio_read_pin(PORT_F, 9);
        break;
        case 'l':
            return gpio_read_pin(PORT_F, 10);
        break;
        default:
            return 1;
        break;
    }
    
}
