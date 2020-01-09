#pragma once 

// Module for the throttle 

#include <stdint.h>

#include "ads1015.h"
#include "exported_enums.h"
#include "soft_timer.h"
#include "interrupt.h"
#include "status.h"


// Time period between every throttle pedal reading 
#define THROTTLE_UPDATE_PERIOD_MS 10 

SoftTimerId drive_fsm_soft_timer_id = 1; 

// Possible throttle states 
typedef enum {
    THROTTLE_STATE_ENABLE = 0, 
    THROTTLE_STATE_DISABLE,
    NUM_THROTTLE_STATES
} ThrottleState; 

// Stores data of the throttle in position_raw, unmapped for now, will figure out mapping later 
typedef struct ThrottleStorage {
    ThrottleState state; 
    int32_t position_raw; 
    Ads1015Channel ads_channel; 
    Ads1015Storage ads_storage; 
} ThrottleStorage; 

StatusCode throttle_init(ThrottleStorage *throttle_storage); 

// Enables the throttle
StatusCode throttle_enable(ThrottleStorage *storage); 

// Disables the throttle 
StatusCode throttle_disable(ThrottleStorage *storage); 

// Gets the current position of the the throttle 
// StatusCode throttle_get_position(ThrottleStorage *throttle_storage, ThrottleState throttle_state, int32_t *position); 