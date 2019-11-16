#pragma once
#include <stdint.h>
#include "log.h"

typedef struct {
  uint8_t age;
  uint8_t height;
  char *name;
} Person;

void init_person(Person *person, uint8_t age, uint8_t height, char *name);
 
void say_hi(Person *person);

uint8_t get_height_cm(Person *person);

float get_height_m(Person *person);

void grow_by_cm(Person *person);
