  
#pragma once 

// Enables and disables the throttle 
// When disabled, throttle no longer raises events with reading data 

#include "fsm.h"
#include "throttle.h"

StatusCode drive_fsm_init(Fsm *fsm, ThrottleStorage *throttle_storage);