#include "front_power_dist_can.h"

#define TEST_CAN_DEVICE_ID 0x1

static CanStorage s_can_storage;

static FrontPowerDistStorage fpd_storage = { 0 };

int main() {
    gpio_init();
    event_queue_init();
    interrupt_init();
    soft_timer_init();

    front_power_dist_storage_init(&fpd_storage);
    Event e = { 0 };
    int i = 0;

    while (true) {
        while (event_process(&e) != STATUS_CODE_OK) {
        }
        can_process_event(&e);

        // pop event from event queue 
        // pass to the the switch driver
        // determine which set of GPIO pins to turn on based on the type of event raised
    }

    return 0;
}
