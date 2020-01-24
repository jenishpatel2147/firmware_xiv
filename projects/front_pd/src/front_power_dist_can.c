#include "front_power_dist_can.h"

#define TEST_CAN_DEVICE_ID 0x1

static CanStorage s_can_storage = { 0 };

// parse the can message
// get the EE
// use the mapping to determine the corresponding event
// raise the event

static Event* prv_get_event_id(const uint16_t *bitset, void *context) {
    FrontPowerDistCanSettings *fpd_settings = (FrontPowerDistCanSettings *) context;
    Event *e;
    for(uint16_t i = 0; i < *bitset; i++){
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

    // Initialize CAN RX handlers
    status_ok_or_return(can_register_rx_default_handler(prv_rx_handler, fpd_can_settings));
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
    // assuming that the event SYSTEM_CAN_FRONT_POWER_DISTRIBUTION_NO_FAULT = 0
    else if(msg->msg_id == 0){
        LOG_DEBUG("Received power dist good message id!\n");

        // get the bitset from message
        uint16_t bitset = msg->data;

        //raise the event after receiving the event
        front_power_dist_raise_event(&bitset);
    }

    return status_msg(STATUS_CODE_INVALID_ARGS, "Invalid message id");
}



StatusCode front_power_dist_raise_event(const uint16_t *bitset){
    prv_get_event_id(bitset);
}
