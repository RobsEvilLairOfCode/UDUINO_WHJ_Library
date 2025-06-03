#include "uduino_config.h"

TIM_HandleTypeDef htim2;

TIM_HandleTypeDef htim3;

TIM_HandleTypeDef htim7;

TIM_HandleTypeDef htim15;

TIM_HandleTypeDef htim16;

TIM_HandleTypeDef htim17;

void timer_2_init(int prescaler, int period);

void timer_3_init(int prescaler, int period);

void timer_15_init(int prescaler, int period);

void timer_16_init(int prescaler, int period);

void timer_17_init(int prescaler, int period);

void timer_2_start();

void timer_3_start();

void timer_15_start();

void timer_16_start();

void timer_17_start();

void timer_2_set_priority(char, char);

void timer_3_set_priority(char, char);

void timer_16_set_duty_cycle(int ccr);

void timer_17_set_duty_cycle(int ccr);

void timer_2_stop();

void timer_3_stop();

void timer_15_stop();

void timer_16_stop();

void timer_17_stop();

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);