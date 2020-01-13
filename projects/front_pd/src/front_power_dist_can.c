#include "front_power_dist_can.h"

#define TEST_CAN_DEVICE_ID 0x1

static CanStorage s_can_storage = { 0 };

StatusCode front_power_dist_can_init(FrontPowerDistCanStorage *storage,
                                    const FrontPowerDistCanSettings *fpd_can_settings,
                                    const CanSettings *can_settings){
  // Initialize CAN.
  status_ok_or_return(can_init(&storage->can_storage, can_settings));

  // Initialize CAN RX handlers.
  status_ok_or_return(
      can_register_rx_handler(SYSTEM_CAN_MESSAGE_LIGHTS_STATE, prv_rx_handler, settings));
  status_ok_or_return(
      can_register_rx_handler(SYSTEM_CAN_MESSAGE_LIGHTS_SYNC, prv_rx_handler, settings));
  status_ok_or_return(can_register_rx_handler(SYSTEM_CAN_MESSAGE_HORN, prv_rx_handler, settings));

  return STATUS_CODE_OK;
}

// receive can message
static void prv_can_callback(const CanMessage *msg, void *context, CanAckStatus *ack_reply) {
    // must raise event here

    LOG_DEBUG("Received a message!\n");
    char log_message[30];
    printf("Data:\n\t");
    uint8_t i;
    for (i = 0; i < msg->dlc; i++) {
        uint8_t byte = 0;
        byte = msg->data >> (i * 8);
        printf("%x ", byte);
    }
    printf("\n");
    return STATUS_CODE_OK;
}

void init_can(void) {
    CanSettings can_settings = {
        .device_id = TEST_CAN_DEVICE_ID,
        .bitrate = CAN_HW_BITRATE_500KBPS,
        .rx_event = FRONT_POWER_DIST_EVENT_CAN_RX,
        .tx_event = FRONT_POWER_DIST_EVENT_CAN_TX,
        .fault_event = FRONT_POWER_DIST_EVENT_CAN_FAULT,
        .tx = { GPIO_PORT_A, 12 },
        .rx = { GPIO_PORT_A, 11 },
        .loopback = false,
    };

    StatusCode ret = can_init(&s_can_storage, &can_settings);
    can_register_rx_default_handler(prv_can_callback, NULL);
}

// send can message
StatusCode front_power_dist_can_process_event(const Event *e){
    // depending
    if (e->id == some part of fpd) {
        LOG_DEBUG("Transmitting a _____ message.\n");
        // return CAN_TRANSMIT_...(...);
    }
    if (e->id == some other part of fpd) {
        LOG_DEBUG("Transmitting a _____ message.\n");
        // return CAN_TRANSMIT_...(...);
    }
    return STATUS_CODE_OK;
}