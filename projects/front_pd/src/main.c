#include "front_power_dist_can.h"

#define TEST_CAN_DEVICE_ID 0x1

static CanStorage s_can_storage;

static FrontPowerDistCanStorage s_fpd_can_storage = { 0 };

int main() {
    gpio_init();
    event_queue_init();
    interrupt_init();
    soft_timer_init();

    CanSettings can_settings = {
        .device_id = TEST_CAN_DEVICE_ID,
        .bitrate = CAN_HW_BITRATE_500KBPS,
        .rx_event = FRONT_POWER_DIST_EVENT_CAN_RX,
        .tx_event = FRONT_POWER_DIST_EVENT_CAN_TX,
        .fault_event = FRONT_POWER_DIST_EVENT_CAN_FAULT,
        .tx = { GPIO_PORT_A, 12 },
        .rx = { GPIO_PORT_A, 11 },
        .loopback = false,
    };



    FrontPowerDistCanSettings *fdp_settings = front_power_dist_can_config_load(); 
    front_power_dist_can_init(&s_fpd_can_storage, fdp_settings, &can_settings);
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
