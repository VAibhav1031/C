#include <stdio.h>
// char frequency histogram
#define MAX_ALLOW_ 26

// this is just the simple macro ANSI color for the tex
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int main() {
  int freq[MAX_ALLOW_] = {0};
  int c;

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      ++freq[c - 'a'];
    }
  }

  int max = 0;
  for (int i = 0; i < MAX_ALLOW_; i++) {
    if (freq[i] > max)
      max = freq[i];
  }
  printf("\n-------------------------------------FREQUENCY---------------------"
         "-----"
         "----\n");

  for (int i = 0; i < MAX_ALLOW_; i++)
    printf("%2d ", freq[i]);
  printf("\n");

  for (int row = max; row >= 1; row--) {
    for (int col = 0; col < MAX_ALLOW_; col++) {
      if (freq[col] >= row)
        printf(RED " █ " RESET);
      else
        printf(" | ");
    }
    printf("\n");
  }

  for (int i = 0; i < MAX_ALLOW_; i++) {
    printf("%2c ", 'a' + i);
  }
  printf("\n");

}
