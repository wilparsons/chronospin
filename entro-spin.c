#include "entro-spin.h"
#include <time.h>

uint64_t entro_spin(void) {
  uint64_t entropy = clock() & 1;
  unsigned char maximum_digits[19] = {8, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1, 5};
  unsigned char digit;
  unsigned char i = 0;
  unsigned char is_maximum_digit = 1;

  while (i != 19) {
    entropy = (entropy << 3) + (entropy << 1);

    if (is_maximum_digit == 1) {
      digit = clock() % (maximum_digits[i] + 1);
      entropy += digit;

      if (digit < maximum_digits[i]) {
        is_maximum_digit = 0;
      }
    } else {
      entropy += clock() % 10;
    }

    i++;
  }

  return entropy;
}
