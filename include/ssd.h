#include "gpio.h"
#include "timer.h"


//First initialize
void ssd_init();

//Internal Helper Functions
void ssd_set_a(char val);
void ssd_set_b(char val);
void ssd_set_c(char val);
void ssd_set_d(char val);
void ssd_set_e(char val);
void ssd_set_f(char val);
void ssd_set_g(char val);
void ssd_set_dp(char val);
void ssd_set_anode(char anode);

//The use this function to write to SSD
void ssd_write(char a, char b, char c, char d);