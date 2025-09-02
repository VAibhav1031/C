#include <stdio.h>

// so  we have to remove the comment from the program , currently it is for the
// c Currently first i will implement the single line comment

/* Any thing in between this  is mulitine fucking bastard
 */
int singleline_comment_destroyer(int c);
int multiline_comment_destroyer(int c);

int main() {
  int c;
  int next;

  int a, b;
  b = a / b;
  while ((c = getchar()) != EOF) {
    if (c == '/') {
      next = getchar();
      if (next == '/') {
        c = singleline_comment_destroyer(c);
      } else if (next == '*') {
        c = multiline_comment_destroyer(c);
        continue;
      } else {
        ungetc(next, stdin);
      }
    }

    printf("%c", c);
  }

  return 0;
}

int singleline_comment_destroyer(int c) {
  while ((c = getchar()) != EOF && c != '\n') {
  }
  return c;
}

int multiline_comment_destroyer(int c) {
  int next;
  while ((c = getchar()) != EOF) {

    if (c == '*') {
      next = getchar();
      if (next == '/')
        break;
    }
  }

  return c;
}
