#include <stdio.h>

main() {
  int ndigit[10];
  int c, i;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') 
      ++ndigit[c-'0'];
  }
  printf("digits = ");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
}
