#pragma once

#include "exported_enums.h"
#include "front_power_dist_events.h"

typedef enum {
  // can events
  FRONT_POWER_DIST_EVENT_CAN_RX = 0,
  FRONT_POWER_DIST_EVENT_CAN_TX,
  FRONT_POWER_DIST_EVENT_CAN_FAULT,
}FrontPowerDistCanEvent;

typedef struct FrontPowerDistCanSettings {
  uint16_t event_data_lookup[EE_NUM_FRONT_POWER_DIST_OUTPUTS];
} FrontPowerDistCanSettings;

// Loads configuration blob for lights_can.
const FrontPowerDistCanSettings *front_power_dist_can_config_load(void);
