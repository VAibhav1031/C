#include <math.h>
#include <stdio.h>

int main() {
  int num;

  num = (int)(floor((double)(-18.0 / 100.0)));

  int result = (-18) - (100 * num);

  printf("Result %d", result);

  return 0;
}
