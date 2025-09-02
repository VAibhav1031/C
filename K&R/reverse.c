#include <stdio.h>
#include <string.h>
// Now lets apply the same thing int the lines of input

#define MAXLINE 1000

void reverse(char s[], int len);
void input_master(char m[], int limit);
int main() {
  // WE ARE going for the reverse

  char s[MAXLINE];
  int lengt;
  printf("Enter the string : \n");
  // scanf("%s", s);

  while (fgets(s, MAXLINE, stdin)) {

    lengt = strlen(s);
    if (lengt > 0 && s[lengt - 1] == '\n') {
      s[lengt - 1] = '\0';
      lengt--;
    }
    reverse(s, lengt);
    printf("%s\n", s);
  }

  return 0;
}
void reverse(char s[], int len) {
  char *start = s;
  char *end = s + len - 1;
  char temp;

  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

void reverse_copy(const char *src, char *dest, int len) {
  for (int i = 0; i < len; i++) {
    dest[i] = src[len - 1 - i];
  }
  dest[len] = '\0';
}
