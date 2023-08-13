#include <stdio.h>

main() {
  int ndigit[10];
  int c, i;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      printf("\n");
    else if (c >= '0' && c <= '9') 
      printf("█");
  }
}
