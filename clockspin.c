#include "clockspin.h"
#include "rainshift.h"

uint64_t clockspin(void) {
  uint64_t entropy = 0;
  unsigned char i = 0;

  while (i != 64) {
    entropy <<= 1;
    entropy += rainshift(entropy) & 1;
    entropy >>= 1;
    entropy <<= 1;
    entropy |= clock() & 1;
    i++;
  }

  return entropy;
}
