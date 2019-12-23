
#include "ads1015.h"
#include "gpio.h"
#include "gpio_it.h"
#include "i2c.h"
#include "interrupt.h"
#include "log.h"
#include "soft_timer.h" 

void setup_test(void) {
    gpio_init();
    interrupt_init();
    gpio_it_init();
    soft_timer_init(); 



} 

void teardown_test(void){} 

void test_