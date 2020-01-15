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

// User uses this instance to provide storage for the module.
typedef struct FrontPowerDistCanStorage {
  CanStorage can_storage;
} FrontPowerDistCanStorage;

// Initializes the lights_can module.
StatusCode front_power_dist_can_init(FrontPowerDistCanStorage *storage,
                                    const FrontPowerDistCanSettings *fpd_can_settings,
                                    const CanSettings *can_settings);

// raises a event based on the bitset received
StatusCode front_power_dist_raise_event(const uint16_t *bitset);

void init_can(void);