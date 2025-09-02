#include <stdio.h>
#include <string.h>

#define MAX_ALLOW 11
int main() {
  // we have to create the histogram of the lenght of the words nothing else

  // first we have to calculate the lenght of the words

  int c, state, len_, len_viltr;
  int narr[MAX_ALLOW];
  char str[50];

  len_ = len_viltr = 0;

  for (int i = 1; i < MAX_ALLOW; i++) {
    narr[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {

      if (len_ > MAX_ALLOW) {
        len_viltr++;
        len_ = 0;
        continue;
      }
      narr[len_]++;
      len_ = 0;
    } else {
      len_++;
    }
  }
  if (len_ > 0 && len_ <= MAX_ALLOW)
    narr[len_]++;
  else if (len_ > MAX_ALLOW)
    len_viltr++;

  printf("\n## OCCURRENCE TO LENGTH Mapping of words :: \n");
  printf("Ocurrences : ");
  for (int i = 1; i < MAX_ALLOW; i++) {
    printf("%d-", narr[i]);
  }
  printf("\nLength     : ");
  for (int i = 1; i < MAX_ALLOW; i++) {
    printf("%d ", i);
  }

  printf("\nTotal lenght violator words : %d\n", len_viltr);

  printf("\nNow we will Present to you the histogram  \n");
  printf("\n");
  printf("\t\tLENGTH : OCCURRENCE's \n");
  for (int i = 1; i < MAX_ALLOW; i++) {
    memset(str, '-', narr[i]);
    str[narr[i]] = '\0';
    printf("\t\t%d : %s\n", i, str);
  }

  printf("\nVERTICAL\n");
  int max = 0;
  for (int i = 1; i < MAX_ALLOW; i++) {
    if (narr[i] > max)
      max = narr[i];
  }

  for (int row = max; row >= 1; row--) {
    for (int col = 1; col < MAX_ALLOW; col++) {
      if (narr[col] >= row)
        printf(" | ");
      else
        printf("   ");
    }
    printf("\n");
  }

  // base
  for (int col = 1; col < MAX_ALLOW; col++) {
    printf("%2d ", col);
  }

  return 0;
}
