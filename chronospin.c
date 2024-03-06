#include "chronospin.h"

bool chronospin(uint32_t *entropy) {
  struct timespec chronospin_time;
  bool is_valid = true;

  entropy[0] = 1;

  while (
    (entropy[0] & 0b10000000000000000000000000000000) != 0b10000000000000000000000000000000 &&
    clock_gettime(CLOCK_REALTIME, &chronospin_time) == 0
  ) {
    entropy[0] <<= 1;
    entropy[0] |= chronospin_time.tv_nsec & 1;
  }

  if (
    (entropy[0] & 0b10000000000000000000000000000000) == 0b10000000000000000000000000000000 &&
    clock_gettime(CLOCK_REALTIME, &chronospin_time) == 0
  ) {
    entropy[0] <<= 1;
    entropy[0] |= chronospin_time.tv_nsec & 1;
    entropy[1] = 1;

    while (
      (entropy[1] & 0b10000000000000000000000000000000) != 0b10000000000000000000000000000000 &&
      clock_gettime(CLOCK_REALTIME, &chronospin_time) == 0
    ) {
      entropy[1] <<= 1;
      entropy[1] |= chronospin_time.tv_nsec & 1;
    }

    if (
      (entropy[1] & 0b10000000000000000000000000000000) == 0b10000000000000000000000000000000 &&
      clock_gettime(CLOCK_REALTIME, &chronospin_time) == 0
    ) {
      entropy[1] <<= 1;
      entropy[1] |= chronospin_time.tv_nsec & 1;
    } else {
      is_valid = false;
    }
  } else {
    is_valid = false;
  }

  return is_valid;
}
