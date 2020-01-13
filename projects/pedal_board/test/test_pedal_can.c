#include "can.h"
#include "event_queue.h"
#include "log.h"
#include "events.h"
#include "status.h"
#include "test_helpers.h"
#include "unity.h"
#include "pedal_can.h"

#define CAN_DEVICE_ID 0x1

static CanStorage can_storage;

void setup_test(void) {
  const CanSettings can_settings = {
    .device_id = CAN_DEVICE_ID,
    .bitrate = CAN_HW_BITRATE_500KBPS,
    .rx_event = CAN_RX,
    .tx_event = CAN_TX,
    .fault_event = CAN_FAULT,
    .tx = { GPIO_PORT_A, 12 },  // CHANGE
    .rx = { GPIO_PORT_A, 11 },  // CHANGE
  };
  TEST_ASSERT_OK( pedal_can_init(&can_storage, &can_settings));
}

void teardown_test(void) {}

void test_assert_trivial(void) {
  TEST_ASSERT_TRUE(true);
}

//
void test_pedal_can_brake_pressed_can(void) {
  Event e = {
    .id = CAN_BRAKE_PRESSED,
  };
  TEST_ASSERT_TRUE(pedal_can_process_event(&e));
}

void test_pedal_can_brake_released_can(void) {
  Event e = {
    .id = CAN_BRAKE_RELEASED,
  };
  TEST_ASSERT_TRUE(pedal_can_process_event(&e));
}

void test_pedal_can_rx_can(void) {
  Event e = {
    .id = CAN_RX,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_tx_can(void) {
  Event e = {
    .id = CAN_TX,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_fault_can(void) {
  Event e = {
    .id = CAN_FAULT,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_car_input_fault(void) {
  Event e = {
    .id = CAR_INPUT_FAULT,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_car_input_neutral(void) {
  Event e = {
    .id = CAR_INPUT_NEUTRAL,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_car_input_drive(void) {
  Event e = {
    .id = CAR_INPUT_DRIVE,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_brake_pressed(void) {
  Event e = {
    .id = BRAKE_PRESSED,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_brake_released(void) {
  Event e = {
    .id = BRAKE_RELEASED,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}

void test_pedal_can_throttle(void) {
  Event e = {
    .id = THROTTLE_DATA,
  };
  TEST_ASSERT_FALSE(pedal_can_process_event(&e));
}