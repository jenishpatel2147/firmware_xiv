#include <stdint.h>
#include "log.h"

typedef struct {
  uint8_t age;
  uint8_t height;
  char *name;
} Person;

void init_person(Person *person, uint8_t age, uint8_t height, char *name) {
  *person.age = age;
  //(*person).age = age;
  person->height = height;
  person->name = name;
}


int main() {
  Person arshan = {0};
  init_person(&arshan, 23, 175, "Arshan");
  LOG_DEBUG("\nArshan's name: %s\n"
            "Arshan's age: %d\n"
            "Arshan's height: %d\n",
            arshan.name,
            arshan.age,
            arshan.height);


  return 0;
}

