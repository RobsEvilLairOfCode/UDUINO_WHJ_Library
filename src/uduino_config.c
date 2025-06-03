/*==============================================================================
* config.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/9/2025
* University of Delaware
 * This file allows you to set up various parts of the board, such as the icache
 * and system clock with ease.
==============================================================================*/

#include "uduino_config.h"

/*
uduino_init();

Inputs:
    None
Returns:
    None

Sets up various parts of the board to their default settings.
*/
void uduino_init(){
    //Initialize Timebase
    HAL_Init();

    //Initiate the ICACHE
    icache_init();

    //Initiate the SystemClock
    sysclock_init(); 

    __HAL_RCC_PWR_CLK_ENABLE(); // Make sure PWR peripheral clock is enabled

    PWR->CR2 |= PWR_CR2_IOSV;   // Enable VDDIO2 for GPIOG/GPIOH
}

/*
icache_init();

Inputs:
    None
Returns:
    None

Sets up the ICACHE. ICACHE is a hardware block inside the microprocessor
that holds recent and frequently used instructions to help speed up execution.

The function is called by uduino_init so you do not need to call it directly.
*/
void icache_init(){
    //use Direct Mapping. 
    //This will use a mapping scheme explained in this lovely youtube video: https://www.youtube.com/watch?v=QcAaP5V2Gpc
    HAL_ICACHE_ConfigAssociativityMode(ICACHE_1WAY);

    //Enable the ICACHE
    HAL_ICACHE_Enable();
}

/*
sysclock_init();

Inputs:
    None
Returns:
    None

Sets up the System Clock. The System Clock is to run at 1 MHz.

The function is called by uduino_init so you do not need to call it directly.
*/
void sysclock_init(){

     RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;

  //The following line sets the clock to 1MHz.
  //If that is too slow, you can right-click on "RCC_MSIRANGE_4" and click "Go to Definition" on the menu
  //You will be able to go though different choices
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_4;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
}

/*
delay_ms(int ms);

Inputs:
    ms - and integer value 
Returns:
    None

Delays the processor for the given amount of milliseconds
*/
void delay_ms(int ms){
    HAL_Delay(ms);
}

//Required for HAL_Delay to funciton
//Do not call or modify this function
void SysTick_Handler(void) {
    HAL_IncTick();
}

