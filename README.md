# ChronoSpin
![ChronoSpin Logo](https://repository-images.githubusercontent.com/740210808/1e77045d-b87d-41e9-9b16-2c0da0443146)

## Description
ChronoSpin is a 64-bit, true-random number generator algorithm.

Read [this article](https://medium.com/@wilparsons/chronospin-is-a-new-64-bit-trng-based-on-nanosecond-timing-without-arithmetic-operations-68637db4cc86) for an in-depth explanation.

## Usage
``` c
#include <stdio.h>
#include "chronospin.h"

int main(void) {
  uint32_t entropy[2];

  if (chronospin(entropy) == true) {
    printf("%u%u\n", entropy[0], entropy[1]);

    if (chronospin(entropy) == true) {
      printf("%u%u\n", entropy[0], entropy[1]);

      if (chronospin(entropy) == true) {
        printf("%u%u\n", entropy[0], entropy[1]);
      } else {
        printf("There was a system clock error.");
      }
    } else {
      printf("There was a system clock error.");
    }
  } else {
    printf("There was a system clock error.");
  }

  return 0;
}
```

## Reference
#### `chronospin()`
This is the randomization function that accepts the following argument.

`entropy` is an array with 2 32-bit unsigned integers.

The return value data type is `bool`.

It returns either `true` when a random number is generated or `false` when `clock_gettime()` fails.
