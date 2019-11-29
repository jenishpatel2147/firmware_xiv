#include "delay.h"
#include "gpio.h"
#include "interrupt.h"
#include "log.h"
#include "sd_binary.h"
#include "soft_timer.h"
#include "spi.h"
#include "stdbool.h"

int main() {
  gpio_init();
  interrupt_init();
  soft_timer_init();
  GpioAddress cs = { .port = GPIO_PORT_B, .pin = 12 };
  SpiSettings spi_settings = {
    .baudrate = 750000,
    .mode = SPI_MODE_3,
    .mosi = { .port = GPIO_PORT_B, .pin = 15 },  // Red
    .miso = { .port = GPIO_PORT_B, .pin = 14 },  // Orange
    .sclk = { .port = GPIO_PORT_B, .pin = 13 },  // Brown
    .cs = cs                                     // White
  };
  spi_init(SPI_PORT_2, spi_settings);
  LOG_DEBUG("hello\n");
  sd_card_init(SPI_PORT_2);
  LOG_DEBUG("hello\n");

  while (true) {
    uint8_t rx_data[SD_BLOCK_SIZE] = { 0 };
    sd_read_blocks(SPI_PORT_2, rx_data, 0, 1);
    LOG_DEBUG("hello\n");
  }
  return 0;
}
