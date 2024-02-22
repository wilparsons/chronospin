#include "chronospin.h"

uint64_t chronospin(void) {
  struct timespec chronospin_time;
  uint64_t entropy = 1;

  while ((entropy >> 63) != 1) {
    entropy <<= 1;
    clock_gettime(CLOCK_REALTIME, &chronospin_time);
    entropy |= chronospin_time.tv_nsec & 1;
  }

  entropy <<= 1;
  clock_gettime(CLOCK_REALTIME, &chronospin_time);
  return entropy | (chronospin_time.tv_nsec & 1);
}
