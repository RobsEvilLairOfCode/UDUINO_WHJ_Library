#include "uduino_config.h"

DAC_HandleTypeDef hdac1;
TIM_HandleTypeDef htim7;

DMA_HandleTypeDef hdma_dac1_ch1;

//User functions
void dac_init();

void dac_start(int* sample, int sample_length);

void dac_stop();

void dac_set_period(int period);


//Helper Functions
void dac_init_timer();

void dac_init_dma();