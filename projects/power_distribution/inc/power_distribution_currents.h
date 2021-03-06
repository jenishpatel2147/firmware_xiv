#pragma once

// Current IDs used by power_distribution_current_measurement and power_distribution_publish_data.

// These are specified at https://uwmidsun.atlassian.net/wiki/x/AYCsRw, please change there
// if you update here.
typedef enum {
  // Currents for front power distribution
  FRONT_POWER_DISTRIBUTION_CURRENT_CENTRE_CONSOLE = 0,
  FRONT_POWER_DISTRIBUTION_CURRENT_PEDAL,
  FRONT_POWER_DISTRIBUTION_CURRENT_STEERING,
  FRONT_POWER_DISTRIBUTION_CURRENT_LEFT_CAMERA,
  FRONT_POWER_DISTRIBUTION_CURRENT_RIGHT_CAMERA,
  FRONT_POWER_DISTRIBUTION_CURRENT_MAIN_DISPLAY,
  FRONT_POWER_DISTRIBUTION_CURRENT_REAR_DISPLAY,
  FRONT_POWER_DISTRIBUTION_CURRENT_DRIVER_DISPLAY,
  FRONT_POWER_DISTRIBUTION_CURRENT_LEFT_DRIVER_DISPLAY,
  FRONT_POWER_DISTRIBUTION_CURRENT_RIGHT_DRIVER_DISPLAY,
  FRONT_POWER_DISTRIBUTION_CURRENT_MAIN_PI,
  FRONT_POWER_DISTRIBUTION_CURRENT_REAR_PI,
  FRONT_POWER_DISTRIBUTION_CURRENT_LEFT_FRONT_TURN_LIGHT,
  FRONT_POWER_DISTRIBUTION_CURRENT_RIGHT_FRONT_TURN_LIGHT,
  FRONT_POWER_DISTRIBUTION_CURRENT_DAYTIME_RUNNING_LIGHTS,
  FRONT_POWER_DISTRIBUTION_CURRENT_PARKING_BRAKE,
  FRONT_POWER_DISTRIBUTION_CURRENT_SPEAKER,
  FRONT_POWER_DISTRIBUTION_CURRENT_HORN,
  FRONT_POWER_DISTRIBUTION_CURRENT_5V_SPARE_1,
  FRONT_POWER_DISTRIBUTION_CURRENT_5V_SPARE_2,
  FRONT_POWER_DISTRIBUTION_CURRENT_SPARE_1,
  FRONT_POWER_DISTRIBUTION_CURRENT_SPARE_2,

  // Currents for rear power distribution
  REAR_POWER_DISTRIBUTION_CURRENT_BMS_CARRIER,
  REAR_POWER_DISTRIBUTION_CURRENT_MCI,
  REAR_POWER_DISTRIBUTION_CURRENT_CHARGER,
  REAR_POWER_DISTRIBUTION_CURRENT_SOLAR_SENSE,
  REAR_POWER_DISTRIBUTION_CURRENT_TELEMETRY,
  REAR_POWER_DISTRIBUTION_CURRENT_REAR_CAMERA,
  REAR_POWER_DISTRIBUTION_CURRENT_LEFT_REAR_TURN_LIGHT,
  REAR_POWER_DISTRIBUTION_CURRENT_RIGHT_REAR_TURN_LIGHT,
  REAR_POWER_DISTRIBUTION_CURRENT_LEFT_BRAKE_LIGHT,
  REAR_POWER_DISTRIBUTION_CURRENT_CENTRE_BRAKE_LIGHT,
  REAR_POWER_DISTRIBUTION_CURRENT_RIGHT_BRAKE_LIGHT,
  REAR_POWER_DISTRIBUTION_CURRENT_STROBE,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_1,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_2,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_3,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_4,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_5,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_6,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_7,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_8,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_9,
  REAR_POWER_DISTRIBUTION_CURRENT_SPARE_10,

  NUM_POWER_DISTRIBUTION_CURRENTS,
} PowerDistributionCurrent;
