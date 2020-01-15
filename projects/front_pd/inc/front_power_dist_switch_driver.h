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
#include "front_power_dist_events.h"


// have some function to receive the event
// flips a GPIO pin based on the event received