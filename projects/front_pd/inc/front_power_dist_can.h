#pragma once
#include <stdbool.h>
#include "front_power_dist_can_config.h"
#include "can.h"
#include "event_queue.h"
#include "gpio.h"
#include "gpio_it.h"
#include "interrupt.h"
#include "soft_timer.h"
#include "status.h"

// this will be in exported enums
// typedef enum {
//     // these are the things that fpd must power
//     EE_FRONT_POWER_DIST_DRIVER_DISPLAY,
//     EE_FRONT_POWER_DIST_PEDAL_BOARD,
//     EE_FRONT_POWER_DIST_CENTER_CONSOLE,
//     EE_FRONT_POWER_DIST_PEDAL,
//     EE_FRONT_POWER_DIST_FRONT_LIGHTS,
//     EE_FRONT_POWER_DIST_DASHBOARD_INDICATOR,
//     EE_FRONT_POWER_DIST_HORN,
//     EE_FRONT_POWER_DIST_DRIVER_FANS,
//     EE_NUM_FRONT_POWER_DIST_EVENTS  
// }FrontPowerDistCanEvent;

// User uses this instance to provide storage for the module.
typedef struct FrontPowerDistCanStorage {
  CanStorage can_storage;
} FrontPowerDistCanStorage;

// Initializes the lights_can module.
StatusCode front_power_dist_can_init(FrontPowerDistCanStorage *storage,
                                    const FrontPowerDistCanSettings *fpd_can_settings,
                                    const CanSettings *can_settings);

// Sends a sync message.
StatusCode front_power_dist_can_process_event(const Event *);

void init_can(void);