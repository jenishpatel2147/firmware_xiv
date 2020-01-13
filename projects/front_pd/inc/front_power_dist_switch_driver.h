#pragma once
#include "can.h"
#include "event_queue.h"
#include "gpio.h"
#include "gpio_it.h"
#include "interrupt.h"
#include "log.h"
#include "soft_timer.h"
#include "status.h"
#include "front_power_dist_can.h"

typedef enum{
    FRONT_POWER_DIST_OUTPUT_DRIVER_DISPLAY,
    FRONT_POWER_DIST_OUTPUT_STEERING,
    FRONT_POWER_DIST_OUTPUT_CENTRE_CONSOLE,
    FRONT_POWER_DIST_OUTPUT_PEDAL,
    FRONT_POWER_DIST_OUTPUT_FRONT_LIGHTS,
    FRONT_POWER_DIST_OUTPUT_DASHBOARD_INDICATOR,
    FRONT_POWER_DIST_OUTPUT_HORN,
    FRONT_POWER_DIST_OUTPUT_DRIVER_FANS,
    NUM_FRONT_POWER_DIST_OUTPUTS   
}FrontPowerDistOutput;