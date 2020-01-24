#include "front_power_dist_switch_driver.h"


// have some function to receive the event
// flips a GPIO pin based on the event received

static const FrontPowerDistEvent fpd_outputs[] = {
    [FRONT_POWER_DIST_EVENT_DRIVER_DISPLAY] = { .port = GPIO_PORT_B, .pin = 5 },
    [FRONT_POWER_DIST_EVENT_STEERING] = { .port = GPIO_PORT_B, .pin = 4 },
    [FRONT_POWER_DIST_EVENT_CENTRE_CONSOLE] = { .port = GPIO_PORT_B, .pin = 3 },
    [FRONT_POWER_DIST_EVENT_PEDAL] = { .port = GPIO_PORT_A, .pin = 15 },
    // etc... for all fpd events
};

