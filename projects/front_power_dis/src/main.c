#include <stdbool.h>
#include <stding.h>

#include "gpio.h"
#include "i2c.h"
#include "interrupt.h"
#include "log.h"
#include "soft_timer.h"

int main(void){

	// Enableing peripherals
	
	interrupt_init();
	soft_timer_init();
	gpio_init();
	event_queue_init();

	// main loop
	while (true) {
		//stuff here
	}


	return 0

}
