#include <stdio.h>

#define MAXLINE 1000

/* hssldf */
int getline_(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline_(line, MAXLINE)) > 0) {
    if (len >
        max) { // if we will get the longest len then only we are updating the
               // max and copying to the longest array , we can directly just
               // update the max, and print he line and nothing else
      max = len;
      copy(longest, line);
    }
  }

  // here we are checking is it greater than the 0 then only i amgonna print he
  // line else fuck it
  if (max > 0)
    printf("%d %s", max, longest);

  return 0;
}

int getline_(char s[], int lim) {
  int c = 0, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {

  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
