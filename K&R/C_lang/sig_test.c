// sig_test.c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void foo(int sig) { printf("Signal %d received!\n", sig); }

int main() {
  signal(SIGUSR1, foo);
  printf("PID: %d\n", getpid());

  while (1) {
    // simulate doing "nothing"
  }

  return 0;
}
