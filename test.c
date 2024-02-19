#include <stdio.h>
#include "clockspin.h"

int main(void) {
  uint64_t entropy = clockspin();

  printf("%llu\n", entropy);
  entropy = clockspin();
  printf("%llu\n", entropy);
  entropy = clockspin();
  printf("%llu\n", entropy);
  return 0;
}
