#include <stdio.h>
#include "entro-spin.h"

int main(void) {
  uint64_t entropy = entro_spin();

  printf("%lu\n", entropy);
  entropy = entro_spin();
  printf("%lu\n", entropy);
  entropy = entro_spin();
  printf("%lu\n", entropy);
  return 0;
}
