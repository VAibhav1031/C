#include <stdio.h>

int main() {
  // long int nl;
  // int c;
  // nl = 0;
  // while ((c = getchar()) != EOF) {
  //   if (c == '\n' || c == '\t' || c == ' ') {
  //     ++nl;
  //   }
  // }
  // printf("%ld", nl);

  // int c;
  // int last_was_space = 0;
  // while ((c = getchar()) != EOF) {
  //   if (c == ' ') {
  //     if (!last_was_space) {
  //       putchar(c);
  //       last_was_space = 1;
  //     }
  //   } else {
  //     putchar(c);
  //     last_was_space = 0;
  //   }
  // }
  //

  //
  //   Write a program to copy its input to its output, replacing each tab by
  //   \t, each backspace by \b,
  // and each backslash by \\. This makes tabs and backspaces visible in an
  // unambiguous way.

  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
  }
  // return 0;
}
