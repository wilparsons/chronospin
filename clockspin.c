#include <time.h>
#include "clockspin.h"

uint64_t clockspin(void) {
  uint64_t entropy = clock() & 1;
  unsigned char i = 0;

  while (i != 63) {
    entropy <<= 1;
    entropy |= clock() & 1;
    i++;
  }

  return entropy;
}
