/*==============================================================================
* GPIO.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/11/2025
* University of Delaware
 * The file allows you to set up and operate the gpio pins of the UDUINO Board.
==============================================================================*/
#include "gpio.h"

/*
gpio_init();

Inputs:
    None
Returns:
    None

When using GPIO, always call this function first before doing anything else.
*/
void gpio_init(){
    //Sets the bits to enable a hardware block that controls RESET and CLOCK on each GPIO port.
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();


    //Allows Port G to run at 1.8V instead of 3.3V for low power applications.
    //Comment this line out if this is not desired.
    HAL_PWREx_EnableVddIO2(); 
}

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
void gpio_init_pin(char port, char pin, char as_input){
    //we can use this handy stucture provided in stm32l5xx_hal_gpio.h to set up a pin.
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    //Convert the Selected Pin form a numerical address to a memory address(defined in stm32l5xx_hal_gpio.h)
    uint16_t selected_pin;

    //This switch-case is pretty long, you can hover over the line number it's on and click the down arrow that appears to hide it.
    switch(pin){
        case 0:
            selected_pin = GPIO_PIN_0;
        break;
        case 1:
            selected_pin = GPIO_PIN_1;
        break;
        case 2:
            selected_pin = GPIO_PIN_2;
        break;
        case 3:
            selected_pin = GPIO_PIN_3;
        break;
        case 4:
            selected_pin = GPIO_PIN_4;
        break;
        case 5:
            selected_pin = GPIO_PIN_5;
        break;
        case 6:
            selected_pin = GPIO_PIN_6;
        break;
        case 7:
            selected_pin = GPIO_PIN_7;
        break;
        case 8:
            selected_pin = GPIO_PIN_8;
        break;
        case 9:
            selected_pin = GPIO_PIN_9;
        break;
        case 10:
            selected_pin = GPIO_PIN_10;
        break;
        case 11:
            selected_pin = GPIO_PIN_11;
        break;
        case 12:
            selected_pin = GPIO_PIN_12;
        break;
        case 13:
            selected_pin = GPIO_PIN_13;
        break;
        case 14:
            selected_pin = GPIO_PIN_14;
        break;
        case 15:
            selected_pin = GPIO_PIN_15;
        break;
    }

    //Set the pin we want to set up to the pin we selected
    GPIO_InitStruct.Pin = selected_pin;

    //Set the mode of the pin
    if(as_input){GPIO_InitStruct.Mode = GPIO_MODE_INPUT;}
    else{        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;}

    //No pullups on the pin (you can either use pullups or pulldowns for things like button inputs)
    GPIO_InitStruct.Pull = GPIO_NOPULL;

    //Set the speed of the pin to a lower frequency for power consumption purposes.
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    //This switch-case will apply our setups in the init struct to the pin.
    switch(port){
        case 0:
            HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        break;
        case 1:
            HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
        break;
        case 2:
            HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
        break;
        case 3:
            HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
        break;
        case 4:
            HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
        break;
        case 5:
            HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
        break;
        case 6:
            HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
        break;
    }
}


/*
gpio_set_pin();

Inputs:
    port: Which port the pin you are trying to initiate is one.
        see gpio.h for definitions.
    pin: The pin number you are trying to initiate. You can enter the number directly
    value - a integer value which is either 0 or 1. 0 turns the pin off, 1 turns the pin on 
alue: a 
Returns:
    None

Initiates all LED pins to outputs. Call this function before using the LEDs.
*/
void gpio_set_pin(char port, char pin, char value){
   //Convert the Selected Pin form a numerical address to a memory address(defined in stm32l5xx_hal_gpio.h)
   uint16_t selected_pin;

   //Convert the pin number to a specified code.
   switch(pin){
       case 0:
           selected_pin = GPIO_PIN_0;
       break;
       case 1:
           selected_pin = GPIO_PIN_1;
       break;
       case 2:
           selected_pin = GPIO_PIN_2;
       break;
       case 3:
           selected_pin = GPIO_PIN_3;
       break;
       case 4:
           selected_pin = GPIO_PIN_4;
       break;
       case 5:
           selected_pin = GPIO_PIN_5;
       break;
       case 6:
           selected_pin = GPIO_PIN_6;
       break;
       case 7:
           selected_pin = GPIO_PIN_7;
       break;
       case 8:
           selected_pin = GPIO_PIN_8;
       break;
       case 9:
           selected_pin = GPIO_PIN_9;
       break;
       case 10:
           selected_pin = GPIO_PIN_10;
       break;
       case 11:
           selected_pin = GPIO_PIN_11;
       break;
       case 12:
           selected_pin = GPIO_PIN_12;
       break;
       case 13:
           selected_pin = GPIO_PIN_13;
       break;
       case 14:
           selected_pin = GPIO_PIN_14;
       break;
       case 15:
           selected_pin = GPIO_PIN_15;
       break;
   } 

   //Write the pin with the matching port and pin
   switch(port){
    case 0:
        HAL_GPIO_WritePin(GPIOA,selected_pin,value);
    break;
    case 1:
        HAL_GPIO_WritePin(GPIOB,selected_pin,value);
    break;
    case 2:
        HAL_GPIO_WritePin(GPIOC,selected_pin,value);
    break;
    case 3:
        HAL_GPIO_WritePin(GPIOD,selected_pin,value);
    break;
    case 4:
        HAL_GPIO_WritePin(GPIOE,selected_pin,value);
    break;
    case 5:
        HAL_GPIO_WritePin(GPIOF,selected_pin,value);
    break;
    case 6:
        HAL_GPIO_WritePin(GPIOG,selected_pin,value);
    break;
    }

    //Write to PG5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5,value);

    //Read from PG5 (If it was an input)
    value = HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_5);
}


/*
gpio_read_pin();

Inputs:
    port: Which port the pin you are trying to initiate is one.
        see gpio.h for definitions.
    pin: The pin number you are trying to initiate. You can enter the number directly
alue: a 
Returns:
    The binary state of the pin (either 1 for high or 0 for low)

Reads the value of a gpio pin. Do not use for pins configured as outputs or analog inputs. */
char gpio_read_pin(char port, char pin){
   //Convert the Selected Pin form a numerical address to a memory address(defined in stm32l5xx_hal_gpio.h)
   uint16_t selected_pin;

   //Convert the pin number to a specified code.
   switch(pin){
       case 0:
           selected_pin = GPIO_PIN_0;
       break;
       case 1:
           selected_pin = GPIO_PIN_1;
       break;
       case 2:
           selected_pin = GPIO_PIN_2;
       break;
       case 3:
           selected_pin = GPIO_PIN_3;
       break;
       case 4:
           selected_pin = GPIO_PIN_4;
       break;
       case 5:
           selected_pin = GPIO_PIN_5;
       break;
       case 6:
           selected_pin = GPIO_PIN_6;
       break;
       case 7:
           selected_pin = GPIO_PIN_7;
       break;
       case 8:
           selected_pin = GPIO_PIN_8;
       break;
       case 9:
           selected_pin = GPIO_PIN_9;
       break;
       case 10:
           selected_pin = GPIO_PIN_10;
       break;
       case 11:
           selected_pin = GPIO_PIN_11;
       break;
       case 12:
           selected_pin = GPIO_PIN_12;
       break;
       case 13:
           selected_pin = GPIO_PIN_13;
       break;
       case 14:
           selected_pin = GPIO_PIN_14;
       break;
       case 15:
           selected_pin = GPIO_PIN_15;
       break;
   } 


   char value = FALSE;
   //Write the pin with the matching port and pin
   switch(port){
    case 0:
        value = HAL_GPIO_ReadPin(GPIOA,selected_pin);
    break;
    case 1:
        value = HAL_GPIO_ReadPin(GPIOB,selected_pin);
    break;
    case 2:
        value = HAL_GPIO_ReadPin(GPIOC,selected_pin);
    break;
    case 3:
        value = HAL_GPIO_ReadPin(GPIOD,selected_pin);
    break;
    case 4:
        value = HAL_GPIO_ReadPin(GPIOE,selected_pin);
    break;
    case 5:
        value = HAL_GPIO_ReadPin(GPIOF,selected_pin);
    break;
    case 6:
        value = HAL_GPIO_ReadPin(GPIOG,selected_pin);
    break;
    }
    return value;
}
