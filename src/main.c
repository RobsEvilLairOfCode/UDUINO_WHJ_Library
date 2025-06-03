/* USER CODE BEGIN Header */
#include "main.h"
#include <stdio.h>
#include "string.h"



#define FALSE 0
#define TRUE 1

/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

#include <math.h>


SPI_HandleTypeDef hspi1;

#define SAMPLES 64
#define SAMPLE_RATE 8000  // Hz (adjust timer period to match this)
#define V_CENTER 3100
#define V_AMPLITUDE 1000
#define PI 3.1415

int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  uduino_init();
  gpio_init();
  led_init();
  button_init();
  ssd_init();
  switch_init();
  //ssd_write(5,5,5,5);
  timer_16_init(10,5000);
  timer_17_init(10,5000);

  timer_16_set_duty_cycle(100);
  timer_17_set_duty_cycle(200);




  dac_init();



  int sine_wave[SAMPLES];

 for(int i = 0; i < SAMPLES; i++){
  if(i%10 < 5){
    sine_wave[i] = 4000;
 }else{
    sine_wave[i] = 0;
  }
}



 // gpio_init_pin(PORT_G,7,0);
  //gpio_set_pin(PORT_G,7,1);

//gpio_init_pin(PORT_D,12,0);
//gpio_init_pin(PORT_D,13,0);
char started = 0;
char time = 0;
while(1){
    for(int i = 0; i < 4; i++){
      led_set(i,switch_read(i));
    }
    led_set(4,button_read('r'));
    led_set(5,button_read('l'));
    led_set(6,button_read('u'));
    led_set(7,button_read('d'));
    if(button_read('c')){
      dac_start(sine_wave,SAMPLES);
    }else{
      dac_stop();
    }
  }
}







