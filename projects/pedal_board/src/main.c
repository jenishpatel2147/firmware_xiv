#include "can.h"
#include "gpio.h"
#include "interrupt.h"
#include "event_quere.h"
//include all the modules
//


int main() {
	//initialize all the modules
	gpio_init();
	interrupt_init();
	event_quere_init();

	while(true) {
		
	}


	return 0;
}
