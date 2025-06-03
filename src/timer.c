
/*==============================================================================
* timer.c version 1.0.0
* Author: Robert Freeman
* CPEG222
* 4/19/2025
* University of Delaware
 * This library lets you use timer 2 and timer 3 as general interrupt timers, and timer 16 and timer 17 as PMW outputs for servos. 
==============================================================================*/
#include "timer.h"

/*
timer_2_init();

Inputs:
    prescaler: The 32 bit prescaler value for timer 2
    period: The 32 bit period value for timer 2
Returns:
    None

Initializes timer 2 with the give prescaler and period values. Timer 2 is a 32 bit timer. In addition, it takes a 32 bit prescaler and period
*/
void timer_2_init(int prescaler, int period){
    htim2.Instance = TIM2;
    htim2.Init.Prescaler = prescaler;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = period;
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    /* TIM2 interrupt Init */
    HAL_TIM_Base_Init(&htim2);
}

/*
timer_3_init();

Inputs:
    prescaler: The 16 bit prescaler value for timer 3
    period: The 16 bit period value for timer 3
Returns:
    None

Initializes timer 3 with the give prescaler and period values. Timer 3 is a 16 bit timer. In addition, it takes a 16 bit prescaler and period
*/
void timer_3_init(int prescaler, int period){
    htim3.Instance = TIM3;
    htim3.Init.Prescaler = prescaler;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = period;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    /* TIM3 interrupt Init */
    HAL_TIM_Base_Init(&htim3);
}

/*
timer_15_init();

Inputs:
    prescaler: The 16 bit prescaler value for timer 15
    period: The 16 bit period value for timer 15
Returns:
    None

Initializes timer 15 with the give prescaler and period values. Timer 15 is a 16 bit timer. In addition, it takes a 16 bit prescaler and period
*/
void timer_15_init(int prescaler, int period){
    htim15.Instance = TIM15;
    htim15.Init.Prescaler = prescaler;
    htim15.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim15.Init.Period = period;
    htim15.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim15.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    /* TIM15 interrupt Init */
    HAL_TIM_Base_Init(&htim15);
}

/*
timer_16_init();

Inputs:
    prescaler: The 16 bit prescaler value for timer 16
    period: The 16 bit period value for timer 16
Returns:
    None

WARNING: Do no use timer 16 or timer 17 from this library as general purpose interrupt timers. They are tied directly to the PWM pins.

Initializes timer 16 with the give prescaler and period values. Timer 16 is a 16 bit timer. In addition, it takes a 16 bit prescaler and period.
The library uses timer 16 exclusively to output PWM signals.
*/
void timer_16_init(int prescaler, int period){
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = prescaler;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = period;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  
  HAL_TIM_Base_Init(&htim16);
  HAL_TIM_PWM_Init(&htim16);
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  //Note: the following line initializes the pulse at 0, effective making it a 0% duty cycle. To change the duty cycle, use timer_17_set_duty_cycle
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  HAL_TIM_PWM_ConfigChannel(&htim16, &sConfigOC, TIM_CHANNEL_1);
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  
  HAL_TIMEx_ConfigBreakDeadTime(&htim16, &sBreakDeadTimeConfig);
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */
  HAL_TIM_MspPostInit(&htim16);
}

/*
timer_17_init();

Inputs:
    prescaler: The 16 bit prescaler value for timer 17
    period: The 16 bit period value for timer 17
Returns:
    None

WARNING: Do no use timer 16 or timer 17 from this library as general purpose interrupt timers. They are tied directly to the PWM pins.

Initializes timer 17 with the give prescaler and period values. Timer 17 is a 16 bit timer. In addition, it takes a 16 bit prescaler and period.
The library uses timer 17 exclusively to output PWM signals.
*/
void timer_17_init(int prescaler, int period){

  /* USER CODE BEGIN TIM17_Init 0 */

  /* USER CODE END TIM17_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM17_Init 1 */

  /* USER CODE END TIM17_Init 1 */
  htim17.Instance = TIM17;
  htim17.Init.Prescaler = prescaler;
  htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim17.Init.Period = period;
  htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim17.Init.RepetitionCounter = 0;
  htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_Base_Init(&htim17);
  HAL_TIM_PWM_Init(&htim17);
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  //Note: the following line initializes the pulse at 0, effective making it a 0% duty cycle. To change the duty cycle, use timer_17_set_duty_cycle
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  HAL_TIM_PWM_ConfigChannel(&htim17, &sConfigOC, TIM_CHANNEL_1);
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  HAL_TIMEx_ConfigBreakDeadTime(&htim17, &sBreakDeadTimeConfig);
  /* USER CODE BEGIN TIM17_Init 2 */

  /* USER CODE END TIM17_Init 2 */
  HAL_TIM_MspPostInit(&htim17);

}

/*
timer_2_start();

Inputs:
    None
Returns:
    None

Starts timer 2. Only call after timer 2 has been initialized
*/
void timer_2_start(){
    HAL_TIM_Base_Start_IT(&htim2);
}


/*
timer_3_start();

Inputs:
    None
Returns:
    None

Starts timer 3. Only call after timer 3 has been initialized
*/
void timer_3_start(){
    HAL_TIM_Base_Start_IT(&htim3);
}

/*
timer_15_start();

Inputs:
    None
Returns:
    None

Starts timer 15. Only call after timer 15 has been initialized
*/
void timer_15_start(){
    HAL_TIM_Base_Start_IT(&htim15);
}

/*
timer_16_start();

Inputs:
    None
Returns:
    None

Starts the Servo 0 Pin PWM. Only call after timer 16 has been initialized
*/
void timer_16_start(){
    HAL_TIM_PWM_Start(&htim16,TIM_CHANNEL_1);
}


/*
timer_17_start();

Inputs:
    None
Returns:
    None

Starts the Servo 1 Pin PWM. Only call after timer 17 has been initialized
*/
void timer_17_start(){
    HAL_TIM_PWM_Start(&htim17,TIM_CHANNEL_1);
}

/*
timer_2_set_subpriority()

Inputs:
    value - The desired subpriority the timer, from 0 to 7
Returns:
    None

Sets the supriority of timer 2.
All interrupts that are general purpose have a priority of 0 by default.
*/
void timer_2_set_priority(char priority, char subpriority){
  HAL_NVIC_SetPriority(TIM2_IRQn, priority, subpriority);
}

/*
timer_3_set_subpriority()

Inputs:
    value - The desired subpriority the timer, from 0 to 7
Returns:
    None

Sets the supriority of timer 3. All interrupts that are general purpose have a priority of 0 by default.
*/
void timer_3_set_priority(char priority, char subpriority){
  //timer_3_subpriority = value;
  HAL_NVIC_SetPriority(TIM3_IRQn, priority, subpriority);
}

/*
timer_16_set_duty_cycle();

Inputs:
    ccr: An integer value that will be used to adjust the duty cycle.
Returns:
    None

To adjust the duty cycle, input a number (CRR) that is less that the timer 16 period.
The duty cycle will be equal to crr / (timer_16_period + 1).
*/
void timer_16_set_duty_cycle(int ccr){
  __HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, ccr);
}

/*
timer_17_set_duty_cycle();

Inputs:
    ccr: An integer value that will be used to adjust the duty cycle.
Returns:
    None

To adjust the duty cycle, input a number (CRR) that is less that the timer 16 period.
The duty cycle will be equal to crr / (timer_17_period + 1).
*/
void timer_17_set_duty_cycle(int ccr){
  __HAL_TIM_SET_COMPARE(&htim17, TIM_CHANNEL_1, ccr);
}

/*
timer_2_stop();

Inputs:
    None
Returns:
    None

Stop timer 2.
*/
void timer_2_stop(){
  HAL_TIM_Base_Stop_IT(&htim2);
}

/*
timer_3_stop();

Inputs:
    None
Returns:
    None

Stop timer 3.
*/
void timer_3_stop(){
  HAL_TIM_Base_Stop_IT(&htim3);
}

/*
timer_15_stop();

Inputs:
    None
Returns:
    None

Stop timer 3.
*/
void timer_15_stop(){
  HAL_TIM_Base_Stop_IT(&htim15);
}

/*
timer_16_stop();

Inputs:
    None
Returns:
    None

Stop timer 16.
*/
void timer_16_stop(){
  HAL_TIM_Base_Stop(&htim16);
}

/*
timer_17_stop();

Inputs:
    None
Returns:
    None

Stop timer 17.
*/
void timer_17_stop(){
  HAL_TIM_Base_Stop(&htim17);
}



//------------------------------------------------Do not directly call functions below-------------------------------------

void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM16_IRQn 1 */

  /* USER CODE END TIM16_IRQn 1 */
}

void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM16_IRQn 1 */

  /* USER CODE END TIM16_IRQn 1 */
}

void TIM15_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim15);
  /* USER CODE BEGIN TIM16_IRQn 1 */

  /* USER CODE END TIM16_IRQn 1 */
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{
  if(tim_baseHandle->Instance==TIM2)
  {
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 interrupt Init */
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  }
  if(tim_baseHandle->Instance==TIM3)
  {
    /* TIM3 clock enable */
    __HAL_RCC_TIM3_CLK_ENABLE();

    /* TIM3 interrupt Init */
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  }
  if(tim_baseHandle->Instance==TIM7)
  {
    /* TIM16 clock enable */
    __HAL_RCC_TIM7_CLK_ENABLE();

    /* TIM16 interrupt Init */
    HAL_NVIC_SetPriority(TIM7_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM7_IRQn);
  }
    if(tim_baseHandle->Instance==TIM15)
  {
    /* TIM3 clock enable */
    __HAL_RCC_TIM15_CLK_ENABLE();

    /* TIM3 interrupt Init */
    HAL_NVIC_EnableIRQ(TIM15_IRQn);
  }
    if(tim_baseHandle->Instance==TIM16)
  {
    /* USER CODE BEGIN TIM16_MspInit 0 */

    /* USER CODE END TIM16_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TIM16_CLK_ENABLE();
    /* USER CODE BEGIN TIM16_MspInit 1 */

    /* USER CODE END TIM16_MspInit 1 */
  }
  else if(tim_baseHandle->Instance==TIM17)
  {
    /* USER CODE BEGIN TIM17_MspInit 0 */

    /* USER CODE END TIM17_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TIM17_CLK_ENABLE();
    /* USER CODE BEGIN TIM17_MspInit 1 */

    /* USER CODE END TIM17_MspInit 1 */
  }
}

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htim->Instance==TIM16)
  {
    /* USER CODE BEGIN TIM16_MspPostInit 0 */

    /* USER CODE END TIM16_MspPostInit 0 */

    /**TIM16 GPIO Configuration
    PA6     ------> TIM16_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_TIM16;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* USER CODE BEGIN TIM16_MspPostInit 1 */

    /* USER CODE END TIM16_MspPostInit 1 */
  }
  else if(htim->Instance==TIM17)
  {
    /* USER CODE BEGIN TIM17_MspPostInit 0 */

    /* USER CODE END TIM17_MspPostInit 0 */
    /**TIM17 GPIO Configuration
    PA7     ------> TIM17_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_TIM17;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* USER CODE BEGIN TIM17_MspPostInit 1 */

    /* USER CODE END TIM17_MspPostInit 1 */
  }

}

