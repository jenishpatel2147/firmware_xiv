#pragma once

typedef enum {
  MCI_CAN_EVENT_RX = 0,
  MCI_CAN_EVENT_TX,
  MCI_CAN_EVENT_FAULT,
  NUM_MCI_CAN_EVENTS
} MciCanEvent;
