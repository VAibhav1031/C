// #include <stdio.h>
//
// int newline_escape(int c);
//
// int newline_bracket_escape(int depth);
// int depth; // so this  i am going to use it here
//
// int main() {
//
//   int c;
//   while ((c = getchar()) != EOF) {
//     if (c == '\n' && depth == 0) {
//
//       c = newline_escape(c);
//     }
//     // i think  this  separation is also good nested condition would not
//     server
//     // as i want
//     if (c == '{') {
//       ++depth;
//       printf("{");
//       c = newline_bracket_escape(depth);
//     }
//
//     if (c == '}') {
//       --depth;
//     }
//     // normal  printing of the characters
//     printf("%c", c);
//   }
// }
//
// int newline_escape(int c) {
//   while ((c = getchar()) != EOF && c == '\n') {
//   }
//   printf("\n");
//   return c;
// }
//
// // with each  nested  bracket there is   \t  frequencies will increase
// // so mostly it would be ** \n\t*depth\n **   this is  pattern which will
// gonnna
// // happen
// int newline_bracket_escape(int depth) {
//   int c;
//   while ((c = getchar()) != EOF) {
//
//     if (c == '\n') {
//       int nextchar;
//       int tabscount = 0;
//
//       while ((nextchar = getchar()) != EOF && nextchar == '\t') {
//         tabscount++;
//       }
//
//       if (nextchar == '\n' && tabscount == depth) {
//         continue;
//       }
//       if (nextchar != EOF) {
//         ungetc(nextchar, stdin);
//       }
//       while (tabscount-- > 0) {
//         ungetc('\t', stdin);
//       }
//       return '\n';
//     } else
//       return c;
//   }
//   return EOF;
// }
//

#include <ctype.h>
#include <stdio.h>

int main(void) {
  int c;
  int last_was_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      if (!last_was_blank) {
        putchar('\n');
        last_was_blank = 1;
      }
      // else skip additional newlines
    } else if (isspace(c) && c != '\n') {
      // optional: collapse spaces/tabs-only lines
      putchar(c);
    } else {
      putchar(c);
      last_was_blank = 0;
    }
  }

  return 0;
}
