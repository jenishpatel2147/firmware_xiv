#include <stdbool.h>

#include "gpio.h"
#include "log.h"

static GpioAddress s_pin_address = { .port = GPIO_PORT_A, .pin = 6 };

int main(void) {
  gpio_init();

  GpioSettings pin_settings = {
    .direction = GPIO_DIR_IN,
    .state = GPIO_STATE_HIGH,
    .alt_function = GPIO_ALTFN_NONE,
    //.resistor = GPIO_RES_NONE,
    .resistor = GPIO_RES_PULLUP,
    //.resistor = GPIO_RES_PULLDOWN,
  };

  gpio_init_pin(&s_pin_address, &pin_settings);

  GpioState state = NUM_GPIO_STATES;
  gpio_get_state(&s_pin_address, &state);
  LOG_DEBUG("Getting GPIO state: %s\n", state ? "HIGH" : "LOW");

  while (true) {
  }
  return 0;
}
