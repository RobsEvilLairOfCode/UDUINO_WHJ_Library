/*==============================================================================
* swt.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/9/2025
* University of Delaware
 * This file allows you to set up various parts of the board, such as the icache
 * and system clock with ease.
==============================================================================*/

#include "switch.h"

/*
switch_init();

Inputs:
    None
Returns:
    None

Initiates all switch pins to inputs. Call this function before using the switches.
*/
void switch_init(){
    //Initiate all pins for Switch AS input
    gpio_init_pin(PORT_E, 8, TRUE);
    gpio_init_pin(PORT_E, 9, TRUE);
    gpio_init_pin(PORT_E, 10, TRUE);
    gpio_init_pin(PORT_E, 11, TRUE);
    gpio_init_pin(PORT_E, 12, TRUE);
    gpio_init_pin(PORT_E, 13, TRUE);
    gpio_init_pin(PORT_E, 14, TRUE);
    gpio_init_pin(PORT_E, 15, TRUE);
}

char switch_read(char pos){
    return gpio_read_pin(PORT_E, pos + 8);
}
