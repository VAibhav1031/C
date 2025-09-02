#include <stdio.h>

#define MAXLINE 1000

int readline(char s[], int lim);
void lead_blazer(char *s);
void trail_blazer(char *s);
int main() {

  char line[MAXLINE];

  while (readline(line, MAXLINE)) {
    lead_blazer(line);
    trail_blazer(line);
    printf("%s", line);
  }
  if (line[0] != '\0')
    printf("%s", line);
  return 0;
}

int readline(char s[], int lim) {
  int i = 0, c;

  while (i < lim && (c = getchar()) != EOF) {
    s[i++] = c;
    if (c == '\n')
      break;
  }

  s[i] = '\0';

  if (i == 0 && c == EOF)
    return 0;

  return 1;
}

void lead_blazer(char *s) {
  int i = 0;
  while (s[i] == ' ' || s[i] == '\t') {
    i++;
  }

  if (i > 0) {
    int j = 0;
    while (s[i]) {
      s[j++] = s[i++];
    }
    s[j] = '\0';
  }
}

void trail_blazer(char *s) {
  int i = 0, last_nonblank = -1;

  while (s[i]) {
    if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
      last_nonblank = i;
    i++;
  }

  if (last_nonblank >= 0) {
    s[last_nonblank++] = '\0';
    s[last_nonblank] = '\n';
  }
}
