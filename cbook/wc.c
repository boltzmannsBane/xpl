#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
  int state = OUT;
  int c;
  int prev;
  while ((c = getchar()) != EOF) {
    if (c == prev)
      ;
    else if (c == ' ' || c == '\t') {
      putchar('\n');
    }
    else {
      putchar(c);
    }
    prev = c;
  }
}
