#include "clockspin.h"
#include "rainshift.h"

uint64_t clockspin(void) {
  uint64_t entropy = time((void *) 0);
  unsigned char i = 0;

  while (i != 64) {
    entropy <<= 1;
    entropy |= (rainshift(rainshift(entropy + clock()) + clock()) + clock()) & 1;
    i++;
  }

  return entropy;
}
