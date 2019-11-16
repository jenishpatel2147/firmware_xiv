#include "log.h"
#include "person.h"

static Person s_arshan = { 0 };

int main() {
  init_person(&s_arshan, 23, 175, "Arshan");
  LOG_DEBUG("\nArshan's name: %s\n"
            "Arshan's age: %d\n"
            "Arshan's height: %d\n",
            s_arshan.name,
            s_arshan.age,
            s_arshan.height);
  
  say_hi(&s_arshan);
  return 0;
}


