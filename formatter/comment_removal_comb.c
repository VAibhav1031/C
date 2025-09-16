#include "comment_removal_comb.h"

int comment_removal(FILE *in, FILE *out) {
  int c;
  int next;
  // 1. first we have checked the is this  start with comment prefix or not , if
  // so then  we will peak-a-boo next character which will make sure which type
  // it is getchar we will use if all thing is nice , else we will use the
  // ungetc cause the next character is not the one which satisfy it is a
  // comment so  we will put back  that to stdin  adn  then our normally print
  // the character in printf function
  int a, b;
  b = a / b;
  while ((c = fgetc(in)) != EOF) {
    if (c == '/') {
      next = fgetc(in);
      if (next == '/') {
        while ((c = fgetc(in) != EOF && c != '\n')) {
        }
      } else if (next == '*') {
        int next;
        while ((c = fgetc(in) != EOF)) {
          if (c == '*') {
            next = fgetc(in);
            if (next == '/')
              break;
          }
        }
        continue;
      } else {
        ungetc(next, stdin);
      }
    }

    fputc(c, out);
  }

  return 0;
}
