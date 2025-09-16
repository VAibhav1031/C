#include "extra_newline_removal_comb.h"
#include <stdio.h>
int newline_remover(FILE *in, FILE *out) {
  int c;
  int last_was_blank = 0;

  while ((c = fgetc(in)) != EOF) {
    if (c == '\n') {
      if (!last_was_blank) {
        fputc('\n', out);
        last_was_blank = 1;
      }
      // else skip additional newlines
    } else if (isspace(c) && c != '\n') {
      // optional: collapse spaces/tabs-only lines
      fputc(c, out);
    } else {
      fputc(c, out);
      last_was_blank = 0;
    }
  }

  return 0;
}
