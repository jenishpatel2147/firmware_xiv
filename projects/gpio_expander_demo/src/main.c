#include "log.h"
#include "gpio.h"
#include "i2c.h"

#define CONFIG_PIN_I2C_SCL \
  { GPIO_PORT_B, 10 }
#define CONFIG_PIN_I2C_SDA \
  { GPIO_PORT_B, 11 }

#define MCP_I2C_ADDR 0x20


#define IODIR 0x00 // direction, 1 input 0 output
#define IPOL 0x01 // polarity, corresponding GPIO bit will show inverted value on the pin
#define GPINTEN 0x02 // interrupt on change 1 enable 0 disable
#define DEFVAL 0x03 //  default compare value for interrupt, the opposite value on the pin will cause interrupt to occur
#define INTCON 0x04 // interrupt controll, interrupt-on-change vs interrupt-on-previous-val

// IO configuration register
// bit 5 (SEQOP): sequential operation register, 0 if enabled. Address pointer increments. (apparently good for polling)
// bit 4 (DISSLW): slew rate control 0 enable 1 disable
// bit 3 (HAEN): HW addr bit enable (always enabled for this model)
// bit 2 (ODR): INT pin has open drain ouptut
// bit 1 (INTPOL): polarity for INT ouput pin
#define IOCON 0x05 

#define GPPU 0x06 // pull-up-resistor 1 pulled up
#define INTF 0x07 // Interrupt flag, 1 means that pin caused interrupt
#define INTCAP 0x08 // captures the GPIO PORT value when interrupt occurs
#define GPIO 0x09 // read GPIO from here, write modifies the Output Latch
#define OLAT 0x0A // 'read' reads OLAT, write modifies the pins configured as output

typedef uint8_t Mcp2300GpioAddress;

typedef enum  {
  MCP_2300_OUPUT_CONFIG,
} Mcp2300OutputConfiguration;

int main(void) {
  gpio_init();
  I2CSettings settings = {
    .speed = I2C_SPEED_FAST,                   //
    .sda = CONFIG_PIN_I2C_SDA,  //
    .scl = CONFIG_PIN_I2C_SCL,  //
  };
  const GpioAddress spare_1_en = {.port = GPIO_PORT_A, .pin = 0};
  const GpioAddress spare_2_en = {.port = GPIO_PORT_A, .pin = 1};

  GpioSettings led_settings = {
    .direction = GPIO_DIR_OUT,        // The pin needs to output.
    .state = GPIO_STATE_HIGH,         // Start in the "on" state.
    .alt_function = GPIO_ALTFN_NONE,  // No connections to peripherals.
    .resistor = GPIO_RES_NONE,        // No need of a resistor to modify floating logic levels.
  };

  gpio_init_pin(&spare_1_en, &led_settings);
  gpio_init_pin(&spare_2_en, &led_settings);
  gpio_set_state(&spare_1_en, GPIO_STATE_HIGH);
  gpio_set_state(&spare_2_en, GPIO_STATE_HIGH);

  i2c_init(I2C_PORT_2, &settings);
  // try reading form reg 0 and see what we get
  // write 0x4 to IODIR
  uint8_t data = 0x0;
  i2c_write_reg(I2C_PORT_2, MCP_I2C_ADDR, IODIR, &data, 1); 
  uint8_t output_status = 0xff;
  i2c_write_reg(I2C_PORT_2, MCP_I2C_ADDR, GPIO, &output_status, 1);
  return 0;
}
