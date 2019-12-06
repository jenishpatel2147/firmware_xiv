#include <string.h>
#include "can.h"
#include "event_queue.h"
#include "events.h"
#include "log.h"

#define CAN_DEVICE_ID 0x1

CanMessage messages[NUM_BRAKE_CAN_EVENTS] = { [CAN_BRAKE_PRESSED] = { CAN_DEVICE_ID, 1, 0, 0 },
                                        [CAN_BRAKE_RELEASED] = { CAN_DEVICE_ID, 2, 0, 0 } };

StatusCode pedal_can_init(CanStorage *can_storage, CanSettings *can_settings) {
  return can_init(&can_storage, &can_settings);
}

bool pedal_can_process_event(Event *e) {
  if (e->id < NUM_CAN_EVENTS) {
    can_transmit(&messages[e->id], NULL);
    return true;
  }
  return false;
}