#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned long long var = -102544684645; // unsigned integer
  long long var_1 = -102544684645;        // signed integer

  int8_t bolj = 128;

  printf("%d\n", (bolj + 1));

  printf("HEy there value :  %llu\n", var);
  printf("HEy there value :  %lld", var_1);
  printf("HEy ther letsee the value in the %d",(2147483648));
  return EXIT_SUCCESS;
}
