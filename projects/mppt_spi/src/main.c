#include "delay.h"
#include "gpio.h"
#include "interrupt.h"
#include "log.h"
#include "soft_timer.h"
#include "spi.h"
#include "stdbool.h"

#define NOP 0x1
#define SHUT 0x2
#define TURN_ON 0x3
#define READ_CURRENT 0x4
#define READ_VIN 0x5
#define READ_PWM 0x6
#define READ_STATUS 0x7

void send_cmd_manually_then_read(GpioAddress *cs, uint8_t input_cmd, uint8_t tx_len, uint8_t *data,
                                 uint8_t data_len) {
  gpio_set_state(cs, GPIO_STATE_LOW);
  spi_tx(SPI_PORT_2, &input_cmd, 1);
  spi_rx(SPI_PORT_2, data, 2, 0x0);
  gpio_set_state(cs, GPIO_STATE_HIGH);
}

void read_manually(GpioAddress *cs) {
  uint8_t cmd = READ_VIN;
  uint8_t data[2] = { 0 };
  GpioState state;
  gpio_set_state(cs, GPIO_STATE_LOW);
  spi_tx(SPI_PORT_2, &cmd, 1);
  spi_rx(SPI_PORT_2, data, 2, NOP);
  gpio_set_state(cs, GPIO_STATE_HIGH);
  LOG_DEBUG("Manual: v[0]:%x, v[1]:%x \n", data[0], data[1]);
}

void read_exchange(uint8_t spi_cmd, uint8_t len, char *name) {
  uint8_t cmd = spi_cmd;
  uint8_t data[len];
  GpioState state;
  spi_exchange(SPI_PORT_2, &cmd, 1, data, len);
  uint16_t output = data[0];
  if (len > 1) {
    output |= (data[1]) << 8;
  }
  LOG_DEBUG("%s: %x\n", name, output);
}

void wake_up() {
  uint8_t cmd = SHUT;
  LOG_DEBUG("Waking chip up\n");
  spi_exchange(SPI_PORT_2, &cmd, 1, NULL, 0);
  delay_us(100);
  cmd = TURN_ON;
  spi_exchange(SPI_PORT_2, &cmd, 1, NULL, 0);
}

void print(uint8_t *data, uint8_t data_len, char *name) {
  uint16_t big_data = 0;
  for (uint8_t i = 0; i < data_len; i++) {
    big_data |= (data[i] << ((data_len - i - 1) * 8));
  }
  LOG_DEBUG("%s: %x\n", name, big_data);
}

static uint16_t prv_calculate_input_voltage(uint16_t adc_output) {
  uint16_t voltage_low_mv = 6300;
  uint16_t output_low = 437;
  uint16_t voltage_high_mv = 10000;
  uint16_t output_high = 695;
  return voltage_low_mv + (voltage_high_mv - voltage_low_mv) / (output_high - output_low) *
                              (adc_output - output_low);
}

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

  spi_init(SPI_PORT_2, &spi_settings);

  uint8_t cmd = READ_CURRENT;
  uint8_t data[2] = { 0 };
  wake_up();

  while (true) {
    cmd = READ_CURRENT;
    spi_exchange(SPI_PORT_2, &cmd, 1, data, 2);
    uint16_t c = data[0] << 8 | data[1];
    delay_ms(300);
    cmd = READ_VIN;
    spi_exchange(SPI_PORT_2, &cmd, 1, data, 2);
    uint16_t v = data[0] << 8 | data[1];
    cmd = READ_PWM;
    spi_exchange(SPI_PORT_2, &cmd, 1, data, 2);
    cmd = READ_STATUS;
    uint8_t onebyte_data[1] = { 0 };
    spi_exchange(SPI_PORT_2, &cmd, 1, onebyte_data, 1);
    uint8_t s = onebyte_data[0];
    LOG_DEBUG("adc v: %x | %d, calc v: %d, curr: %x | %d, status: %x\n", v, v,
              prv_calculate_input_voltage(v), c, c, s);

    delay_ms(80);
  }
  return 0;
}
