#include <stdio.h>

#define IN 1
#define OUT 0
int main() {

  int c, state;
  state = IN;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else {
      if (state == OUT) {
        if (state != IN)
          putchar('\n');
        state = IN;
      }

      putchar(c);
    }
  }

  return 0;
}
