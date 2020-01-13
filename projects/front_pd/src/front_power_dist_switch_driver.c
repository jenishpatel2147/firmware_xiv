#include "front_power_dist_switch_driver.h"




static const FrontPowerDistEvent event1[] = {
    [FRONT_POWER_DIST_DRIVER_DISPLAY] = { .port = GPIO_PORT_B, .pin = 5 },
    { .port = GPIO_PORT_B, .pin = 4 },
    { .port = GPIO_PORT_B, .pin = 3 },
    { .port = GPIO_PORT_A, .pin = 15 },
};