#include <stdio.h>

int main() {
  printf("Size of int: %zu bytes\n", sizeof(int));

  unsigned int max_unsigned_int = ~0;
  int max_int = (int)(max_unsigned_int >> 1);
  int min_int = ~max_int;

  printf("Range of int: %d to %d\n", max_int, min_int);

  return 0;
}
