#pragma once
#include <stdbool.h>
#include "can.h"
#include "event_queue.h"
#include "gpio.h"
#include "gpio_it.h"
#include "interrupt.h"
#include "log.h"
#include "soft_timer.h"
#include "status.h"

typedef enum {
  // can events
  FRONT_POWER_DIST_EVENT_CAN_RX = 0,
  FRONT_POWER_DIST_EVENT_CAN_TX,
  FRONT_POWER_DIST_EVENT_CAN_FAULT,

  // idek if theses are needed: FPD power on/off events 
  FRONT_POWER_DIST_EVENT_ON,
  FRONT_POWER_DIST_EVENT_OFF,
}FrontPowerDistCanEvent;

// this will likely be replaced by exported enums
typedef enum {
    // events sent to fpd board, ex: Centre Console sends a message to Front Power Distribution to turn on Driver Display.
    // these are the things that fpd must power
    FRONT_POWER_DIST_DRIVER_DISPLAY,
    FRONT_POWER_DIST_PEDAL_BOARD,
    FRONT_POWER_DIST_CENTER_CONSOLE,

    // https://uwmidsun.atlassian.net/wiki/spaces/ELEC/pages/850657322/Front+Power+Distribution
    NUM_FRONT_POWER_DIST_EVENTS  
}FrontPowerDistEvent;

// event_type is to determine what type of event it received?
// event_data_lookup is to?
typedef struct FrontPowerDistCanSettings {
  FrontPowerDistCanEvent event_type[NUM_FRONT_POWER_DIST_EVENTS];
  uint16_t event_data_lookup[NUM_FRONT_POWER_DIST_EVENTS];
} FrontPowerDistCanSettings;

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