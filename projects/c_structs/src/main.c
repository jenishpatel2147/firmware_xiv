#include <stdint.h>
#include "log.h"

typedef struct {
  uint8_t age;
  uint8_t height;
  char *name;
} Person;


int main() {
  Person arshan = {
    .age = 22,
    .height = 175,
    .name = "Arshan"
  };

  LOG_DEBUG("\nArshan's name: %s\n"
            "Arshan's age: %d\n"
            "Arshan's height: %d\n",
            arshan.name,
            arshan.age,
            arshan.height);

  return 0;

  Person andrew;
  //Person andrew = { 0 };
  LOG_DEBUG("\nAndrew's name: %s\n"
            "Andrew's age: %d\n"
            "Andrew's height: %d\n",
            andrew.name,
            andrew.age,
            andrew.height);

  return 0;
}

