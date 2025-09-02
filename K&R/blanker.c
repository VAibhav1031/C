#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int readline(char s[], int lim);
void lead_blazer(char *s);
void trail_blazer(char *s);

int main(int argc, char *argv[]) {
  int do_lead = 0, do_trail = 0;
  char line[MAXLINE];

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-l") == 0)
      do_lead = 1;
    else if (strcmp(argv[i], "-t") == 0)
      do_trail = 1;

    else {
      fprintf(stderr, "Uknown option : %s\n", argv[i]);
      return 1;
    }
  }
  while (readline(line, MAXLINE)) {
    if (do_lead)
      lead_blazer(line);
    if (do_trail)
      trail_blazer(line);
    printf("%s", line);

    if (line[0] != '\0')
      printf("%s", line);
  }
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
    s[last_nonblank + 1] = '\n';
    s[last_nonblank + 2] = '\0';
  } else {
    s[last_nonblank] = '\0';
  }
}
