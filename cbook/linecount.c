#include <stdio.h>

main()
{
  // int c, nl;
  // nl = 0;
  // while ((c = getchar()) != EOF) 
  //   if (c == '\n')
  //     ++nl;
  // printf("%d\n", nl);
  int c;
  while ((c = getchar()) != EOF) 
    if (c == '\t')
      putchar('\t');
    else if (c == '\b')
      putchar('\b');
    else if (c == '\\')
      putchar('\\');
    else 
      putchar(c);
}
