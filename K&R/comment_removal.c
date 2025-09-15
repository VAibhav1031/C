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

  // 1. first we have checked the is this  start with comment prefix or not , if
  // so then  we will peak-a-boo next character which will make sure which type
  // it is getchar we will use if all thing is nice , else we will use the
  // ungetc cause the next character is not the one which satisfy it is a
  // comment so  we will put back  that to stdin  adn  then our normally print
  // the character in printf function
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

// 2. It is  the one place  where we will  say things  work nicely , very simple
// and nice we will move the getchar pointer to the next character until we will
// get the 'EOF' or '\n'
int singleline_comment_destroyer(int c) {
  while ((c = getchar()) != EOF && c != '\n') {
  }
  return c;
}

// 3 It is  bit  different here '\n' doesnt make sense of ending , it is only
// marked ended or finised with
// */  so  same little peak-a-boo
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
