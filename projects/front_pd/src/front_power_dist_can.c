#include "front_power_dist_can.h"

#define TEST_CAN_DEVICE_ID 0x1

static CanStorage s_can_storage = { 0 };

// parse the can message
// get the EE
// use the mapping to determine the corresponding event
// raise the event

static Event* prv_get_event_id(const uint16_t *bitset) {
    Event *e;
    for(uint16_t i = 0; i < *bitset; i++){
        FrontPowerDistCanSettings *fpd_settings = front_power_dist_can_config_load();
        if(bitset[i] == 1){
            e->id = fpd_settings->event_data_lookup[i];
        }
    }
  return e;
}

StatusCode front_power_dist_can_init(FrontPowerDistCanStorage *storage,
                                    const FrontPowerDistCanSettings *fpd_can_settings,
                                    const CanSettings *can_settings){
  // Initialize CAN.
  status_ok_or_return(can_init(&storage->can_storage, can_settings));

//   // Initialize CAN RX handlers
//   // Need dif handlers for dif ID messages, props don't need as long as ou set default
//   status_ok_or_return(
//       can_register_rx_handler(SYSTEM_CAN_MESSAGE_LIGHTS_STATE, prv_rx_handler, settings));
//   status_ok_or_return(
//       can_register_rx_handler(SYSTEM_CAN_MESSAGE_LIGHTS_SYNC, prv_rx_handler, settings));

  return STATUS_CODE_OK;
}

// receive can message
static StatusCode prv_rx_handler(const CanMessage *msg, void *context, CanAckStatus *ack_reply) {
    // must raise event here
    LOG_DEBUG("Received a message!\n");

    uint8_t param = 0;

    if(msg->msg_id == SYSTEM_CAN_MESSAGE_POWER_DISTRIBUTION_FAULT){
        LOG_DEBUG("Received power dist fault message id!\n");
        status_ok_or_return(CAN_UNPACK_POWER_DISTRIBUTION_FAULT(msg, &param));
    }
    // SYSTEM_CAN_FRONT_POWER_DISTRIBUTION_NO_FAULT?? = 0
    else if(msg->msg_id == 0){
        LOG_DEBUG("Received power dist good message id!\n");

        // print message data
        // uint8_t i;
        // for (i = 0; i < msg->dlc; i++) {
        //     uint8_t byte = 0;
        //     byte = msg->data >> (i * 8);
        //     printf("%x ", byte);
        // }

        // get the bitset from message
        uint16_t bitset = msg->data;

        front_power_dist_raise_event(&bitset);
    }

    return status_msg(STATUS_CODE_INVALID_ARGS, "Invalid message id");
}



StatusCode front_power_dist_raise_event(const uint16_t *bitset){
    prv_get_event_id(bitset);
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
    can_register_rx_default_handler(prv_rx_handler, NULL);
}