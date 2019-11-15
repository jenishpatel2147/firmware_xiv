#include "person.h"

void init_person(Person *person, uint8_t age, uint8_t height, char *name) {
  person->age = age;
  person->height = height;
  person->name = name;
}

void say_hi(Person *person) {
  LOG_DEBUG("hello, my name is %s", person->name);
}

uint8_t get_height_cm(Person *person) {
  return person->height;
}

static float prv_convert_to_m(uint8_t height) {
  return height/100;
}

float get_height_m(Person *person) {
 return prv_convert_to_m(person->height);
}


void grow_by_cm(Person *person) {
  person->height += 1;
}
