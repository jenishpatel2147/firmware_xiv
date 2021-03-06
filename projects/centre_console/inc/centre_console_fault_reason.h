#pragma once

// All the enums and definitions for fault reasons in centre console.

#include "stdint.h"

typedef enum {
  POWER_MAIN_FAULT_REASON_ACK_FAIL = 0,
  NUM_POWER_MAIN_FAULT_REASONS
} PowerMainFaultReason;

typedef enum {
  CENTRE_CONSOLE_FAULT_REASON_BMS_CARRIER_FAILED_TO_TURN_ON = 0,
  CENTRE_CONSOLE_FAULT_REASON_AUX_VOLTAGE_LOW,
  CENTRE_CONSOLE_FAULT_REASON_MCI_FAILED_TO_TURN_ON,
  CENTRE_CONSOLE_FAULT_REASON_BATTERY_RELAY_FAILED_TO_CLOSE,
  CENTRE_CONSOLE_FAULT_REASON_DCDC_NOT_SWITCHED,
  CENTRE_CONSOLE_FAULT_REASON_PRECHARGE_NOT_INITIATED,
  CENTRE_CONSOLE_FAULT_REASON_MOTOR_RELAY_FAILED_TO_CLOSE,
  NUM_CENTRE_CONSOLE_FAULT_REASONS
} CentreConsoleFaultReason;

typedef enum {
  DRIVE_FSM_FAULT_REASON_MCI_RELAY_STATE = 0,
  DRIVE_FSM_FAULT_REASON_PRECHARGE_TIMEOUT,
  DRIVE_FSM_FAULT_REASON_EBRAKE_STATE,
  DRIVE_FSM_FAULT_REASON_MCI_OUTPUT,
  NUM_DRIVE_FSM_FAULT_REASONS,
} DriveFsmFaultReason;

typedef union {
  struct {
    uint8_t fault_reason : 4;
    uint8_t fault_state : 4;
  };
  uint8_t raw;
} DriveFsmFault;
