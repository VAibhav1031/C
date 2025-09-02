#include <stdio.h>

// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines. bro in this  we dont have to give the

#define MAXLINE 1000

char *trail_blazer(char line[], int lim);
char *lead_blazer(char li[], int lim);
int main() {

  char line[MAXLINE];
  char *tr = {};

  // thinking to use both
  while ((tr != trail_blazer(line, MAXLINE))) {

    if (tr)
      printf("%s", tr); // NULL

    return 0;
  }
}
char *trail_blazer(char s[], int lim) {
  int c, i = 0, last_blank_line = -1;

  while (i < lim && (c = getchar()) != EOF) {
    if (c == '\n') {
      break;
    }
    s[i++] = c;

    if (c != ' ' && c != '\t')
      last_blank_line = i;
  }

  if (c == EOF && i == 0)
    return NULL;

  if (last_blank_line == -1)
    return NULL;

  s[last_blank_line + 1] = '\n';
  s[last_blank_line + 2] = '\0';

  return s;
}

char *lead_blazer(char m[], int lim) {
  int i = 0, c;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t') {
      break;
    }
  }

  if (c == EOF)
    return NULL;

  if (c == '\n')
    return NULL;

  m[i++] = c;
  while (i < lim - 2 && (c = getchar()) != EOF && c != '\n') {
    m[i++] = c;
  }

  m[i++] = '\n';
  m[i] = '\0';

  return m;
}
