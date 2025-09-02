#include <stdio.h>

#define LOWER 0   // lower limit
#define UPPER 300 // upper limit
#define STEP 20   //

int main() {
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
  printf("Hi there is something you must see that integer division is "
         "something else  %d/%d = %d",
         16, 25, 16 / 25);

  return 0;
}
