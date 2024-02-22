# ChronoSpin
![ChronoSpin Logo](https://repository-images.githubusercontent.com/740210808/0bc159d2-f45b-4024-8233-f8806ca4283c)

## Description
ChronoSpin is a 64-bit, true-random number generator algorithm.

Read [this article](https://medium.com/@wilparsons/chronospin-is-a-new-64-bit-trng-based-on-nanosecond-timing-without-arithmetic-operations-68637db4cc86) for an in-depth explanation.

## Usage
``` c
#include <stdio.h>
#include "chronospin.h"

int main(void) {
  printf("%llu\n", chronospin());
  printf("%llu\n", chronospin());
  printf("%llu\n", chronospin());
  return 0;
}
```

## Reference
#### `chronospin()`
This is the randomization function.

The return value data type is `uint64_t`.

It returns the 64-bit unsigned integer random number result.

## Support
ChronoSpin was designed and developed by [Wil Parsons](https://wilparsons.github.io/).

I'm available for freelance work to extend, implement or modify ChronoSpin and other algorithms.
