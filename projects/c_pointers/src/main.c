#include <stdint.h>
#include "log.h"

void change_this(uint8_t value) {
  value = 4;
  LOG_DEBUG("address: %p\n", &value);
}

void change_this_using_ptr(uint8_t *value) {
  *value = 4;
}


int main() {
  uint8_t a = 123;
  LOG_DEBUG("value of a: %d\n", a);
  LOG_DEBUG("address a: %p\n", &a);
 
  uint8_t *b;
  b = &a;
  LOG_DEBUG("value of b: %p\n", b);
  LOG_DEBUG("what's in that memory address: %d\n", *b);

  uint8_t c = 0;
  LOG_DEBUG("address of c: %p\n", &c);
  LOG_DEBUG("c before: %d\n", c);
  change_this(c);
  LOG_DEBUG("c after: %d\n", c);

  LOG_DEBUG("c before changing by pointer: %d\n", c);
  change_this_using_ptr(&c);
  LOG_DEBUG("c after changing by pointer: %d\n", c);

  return 0;
}

