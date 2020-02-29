#pragma once

#include "generic_can.h"

#define MOTOR_CONTROLLER_BRAKE_THRESHOLD 0.0f

#define MOTOR_CONTROLLER_DRIVE_TX_PERIOD_MS 200

typedef struct {
  GenericCan *motor_can;
  PedalRxStorage pedal_storage;
} MotorControllerOutputStorage;

StatusCode mci_output_init(MotorControllerOutputStorage *storage, GenericCan* motor_can_settings);
