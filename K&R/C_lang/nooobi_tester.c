#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 99;
int bss_var;

int main();
void foo() {
  int local_var = 5;
  int *heap_ptr = malloc(4);

  printf("PID: %d\n", getpid());
  printf("Addr of main()      : %p\n", main);
  printf("Addr of global_var  : %p\n", &global_var);
  printf("Addr of bss_var     : %p\n", &bss_var);
  printf("Addr of local_var   : %p\n", &local_var);
  printf("Addr of heap_ptr    : %p\n", heap_ptr);

  sleep(20); // So you can inspect it in parallel
  free(heap_ptr);
}
int main() {
  foo();
  printf("Addr of foo  : %p\n", &foo);
  return 0;
}
