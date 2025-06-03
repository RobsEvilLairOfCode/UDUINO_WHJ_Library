#include "stm32l5xx_hal.h"

#define TRUE 1
#define FALSE 0

void uduino_init(void);
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
void icache_init(void);

/*
sysclock_init();

Inputs:
    None
Returns:
    None

Sets up the System Clock. The System Clock is to run at 80 MHz.

The function is called by uduino_init so you do not need to call it directly.
*/
void sysclock_init(void);

void delay_ms(int ms);