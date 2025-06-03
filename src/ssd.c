/*==============================================================================
* led.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/9/2025
* University of Delaware
 * This file allows you to change the state of the 8 LEDs in various ways
==============================================================================*/

#include "ssd.h"

char display_pos = 0;
static char values[4] = {10,10,10,10};

/*
ssd_init();

Inputs:
    None
Returns:
    None

Initiates all LED pins to outputs. Call this function before using the LEDs.
*/
void ssd_init(){

    timer_15_init(10,400);
    timer_15_start();


    //Initiate all pins for LED AS output
    //Tip: Hover your cursor over "gpio_init_pin" to see a description of that function.
    gpio_init_pin(PORT_D, 0, FALSE);
    gpio_init_pin(PORT_D, 1, FALSE);
    gpio_init_pin(PORT_D, 2, FALSE);
    gpio_init_pin(PORT_D, 3, FALSE);
    gpio_init_pin(PORT_D, 4, FALSE);
    gpio_init_pin(PORT_D, 5, FALSE);
    gpio_init_pin(PORT_D, 6, FALSE);
   // gpio_init_pin(PORT_D, 7, FALSE);

    //Anode 0
    gpio_init_pin(PORT_D, 8, FALSE);
    //Anode 1
    gpio_init_pin(PORT_G, 3, FALSE);
    //Anode 2
    gpio_init_pin(PORT_G, 4, FALSE);
    //Anode 3
    gpio_init_pin(PORT_G, 5, FALSE);
    //Anode L
    gpio_init_pin(PORT_G, 6, FALSE);
}

void ssd_set_digit(char pos, char a, char b, char c, char d, char e, char f, char g){
    ssd_set_anode(pos);
    ssd_set_a(a);
	ssd_set_b(b);
    ssd_set_c(c);
    ssd_set_d(d);
    ssd_set_e(e);
    ssd_set_f(f);
    ssd_set_g(g);
}

void ssd_set_digit_number(char pos, char digit){
	switch(digit){
	case 0:
		ssd_set_digit(pos,0,0,0,0,0,0,1);
	break;
	case 1:
		ssd_set_digit(pos,1,0,0,1,1,1,1);
		break;
	case 2:
		ssd_set_digit(pos,0,0,1,0,0,1,0);
		break;
	case 3:
		ssd_set_digit(pos,0,0,0,0,1,1,0);
		break;
	case 4:
		ssd_set_digit(pos,1,0,0,1,1,0,0);
		break;
	case 5:
		ssd_set_digit(pos,0,1,0,0,1,0,0);
		break;
	case 6:
		ssd_set_digit(pos,0,1,0,0,0,0,0);
		break;
	case 7:
		ssd_set_digit(pos,0,0,0,1,1,1,1);
		break;
	case 8:
		ssd_set_digit(pos,0,0,0,0,0,0,0);
		break;
	case 9:
		ssd_set_digit(pos,0,0,0,1,1,0,0);
		break;
	case 10:
		ssd_set_digit(pos,1,1,1,1,1,1,1);
		break;
    default:
        ssd_set_digit(pos,1,1,1,1,1,1,1);
    break;
	}
}

void ssd_set_a(char val){gpio_set_pin(PORT_D, 0, val);}
void ssd_set_b(char val){gpio_set_pin(PORT_D, 1, val);}
void ssd_set_c(char val){gpio_set_pin(PORT_D, 2, val);}
void ssd_set_d(char val){gpio_set_pin(PORT_D, 3, val);}
void ssd_set_e(char val){gpio_set_pin(PORT_D, 4, val);}
void ssd_set_f(char val){gpio_set_pin(PORT_D, 5, val);}
void ssd_set_g(char val){gpio_set_pin(PORT_D, 6, val);}
void ssd_set_dp(char val){gpio_set_pin(PORT_D, 7, val);}
void ssd_set_anode(char anode){
    switch(anode){
        case 0:
            gpio_set_pin(PORT_D, 8, FALSE);
            gpio_set_pin(PORT_G, 3, TRUE);
            gpio_set_pin(PORT_G, 4, TRUE);
            gpio_set_pin(PORT_G, 5, TRUE);
        break;
        case 1:
            gpio_set_pin(PORT_D, 8, TRUE);
            gpio_set_pin(PORT_G, 3, FALSE);
            gpio_set_pin(PORT_G, 4, TRUE);
            gpio_set_pin(PORT_G, 5, TRUE);

        break;
        case 2:
            gpio_set_pin(PORT_D, 8, TRUE);
            gpio_set_pin(PORT_G, 3, TRUE);
            gpio_set_pin(PORT_G, 4, TRUE);
            gpio_set_pin(PORT_G, 5, FALSE);
        
        break;
        case 3:
            gpio_set_pin(PORT_D, 8, TRUE);
            gpio_set_pin(PORT_G, 3, TRUE);
            gpio_set_pin(PORT_G, 4, FALSE);
            gpio_set_pin(PORT_G, 5, TRUE);
        break;
        
    }
}

void ssd_write(char a, char b, char c, char d){
    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if (htim->Instance == TIM15)
    {
        display_pos = (display_pos + 1) % 4;
        ssd_set_digit_number(display_pos,values[display_pos]);
       
    }
}

