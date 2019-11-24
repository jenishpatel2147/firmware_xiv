#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "delay.h"       
#include "gpio.h"        
#include "interrupt.h"   
#include "misc.h"        
#include "soft_timer.h"  
#include "fsm.h"  
#include "log.h"  
#include "event_queue.h"  

static const GpioAddress led_address = { 
  .port = GPIO_PORT_B, 
  .pin = 5
};

typedef enum {
  EVENT_ON = 0,
  EVENT_OFF,
  EVENT_DELAY,
  NUM_EVENTS,
} BlinkEvent;

FSM_DECLARE_STATE(state_on);
FSM_DECLARE_STATE(state_off);
FSM_DECLARE_STATE(state_delay);

FSM_STATE_TRANSITION(state_on) {
  FSM_ADD_TRANSITION(EVENT_DELAY, state_delay);
}

FSM_STATE_TRANSITION(state_off) {
  FSM_ADD_TRANSITION(EVENT_DELAY, state_delay);
}

FSM_STATE_TRANSITION(state_delay) {
  FSM_ADD_TRANSITION(EVENT_ON, state_on);
  FSM_ADD_TRANSITION(EVENT_OFF, state_off);
}

static void prv_state_on_output(Fsm *fsm, const Event *e, void *context) {
  gpio_set_state(&led_address, GPIO_STATE_HIGH);
  LOG_DEBUG("Setting LED state to ON.\n");
}

static void prv_state_off_output(Fsm *fsm, const Event *e, void *context) {
  gpio_set_state(&led_address, GPIO_STATE_LOW);
  LOG_DEBUG("Setting LED state to OFF.\n");
}

static void prv_state_delay_output(Fsm *fsm, const Event *e, void *context) {
  delay_ms(500);
}

static Fsm s_fsm;
static void prv_init_fsm(void) {
  fsm_state_init(state_on, prv_state_on_output);
  fsm_state_init(state_off, prv_state_off_output);
  fsm_state_init(state_delay, prv_state_delay_output);
  fsm_init(&s_fsm, "Blinking LEDs FSM", &state_off, NULL);
}

int main(void) {
  interrupt_init();
  soft_timer_init();
  gpio_init();

  GpioSettings led_settings = {
    .direction = GPIO_DIR_OUT,        
    .state = GPIO_STATE_HIGH,         
    .alt_function = GPIO_ALTFN_NONE,  
    .resistor = GPIO_RES_NONE,        
  };
  gpio_init_pin(&led_address, &led_settings);
  prv_init_fsm();

  BlinkEvent blink_events[4] = {
    EVENT_OFF,
    EVENT_DELAY,
    EVENT_ON,
    EVENT_DELAY
  };

  while (true) {
    for (uint8_t i = 0 ; i < 4; i++) {
      Event e = {0};
      e.id = blink_events[i];
      fsm_process_event(&s_fsm, &e);
    }
  }

  return 0;
}



