#include "chronospin.h"

uint64_t chronospin(void) {
  struct timespec chronospin_time;
  uint64_t entropy = 0;
  unsigned char i = 0;

  while (i != 64) {
    entropy <<= 1;
    clock_gettime(CLOCK_REALTIME, &chronospin_time);
    entropy |= chronospin_time.tv_nsec & 1;
    i++;
  }

  return entropy;
}
