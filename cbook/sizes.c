#include <stdio.h>

#define BYTE 1*8bits

int main() {
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of char: %zu bytes\n", sizeof(char));

  unsigned int max_uint = ~0;
  int max_int = (int)(max_uint >> 1);
  int min_int = ~max_int;

  printf("Range of int: %d to %d\n", max_int, min_int);

  return 0;
}
