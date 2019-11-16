#include "log.h"
#include "interrupt.h"
#include "soft_timer.h"



static void prv_my_callback(SoftTimerId timer_id, void *context) {
  uint32_t *count_ptr = (uint32_t *) context;
  (*count_ptr)++;
  LOG_DEBUG("Hello! %d\n", *count_ptr);
  SoftTimerId soft_timer_id;
  soft_timer_start_millis(1000, prv_my_callback, count_ptr, &soft_timer_id);
}


int main() {
  interrupt_init();
  soft_timer_init();
  uint32_t count = 0;

  SoftTimerId soft_timer_id;
  soft_timer_start_millis(1000, prv_my_callback, &count, &soft_timer_id);

  while (true) {
  
  }
  return 0;
}



