#include "throttle.h"

#include "unity.h"
#include "ads1015.h"
#include "gpio.h"
#include "gpio_it.h"
#include "i2c.h"
#include "interrupt.h"
#include "log.h"
#include "soft_timer.h" 

static ThrottleStorage throttle_storage;  

void setup_test(void) {
    gpio_init();
    interrupt_init();
    gpio_it_init();
    soft_timer_init(); 



} 

void teardown_test(void){} 

void test_throttle_module_should_intialize_properly(void){
    TEST_ASSERT_EQUAL(STATUS_CODE_OK, throttle_init(&throttle_storage));
}