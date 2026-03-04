#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int g_init = 15;
int g_unit;

int main() {
  int local = 5;
  uint32_t sudd = -2000;
  int *p = malloc(4);
  *p = 20;

  printf("Hey there is  : %d ", sudd);
  printf("Adresses");
  printf("code      :%p\n", main);

  printf(".data       :%p\n", &g_init);

  printf(".bss    :%p\n", &g_unit);
  printf(" heap       :%p\n", p);

  printf("stack     :%p\n", &local);

  return 0;
}
