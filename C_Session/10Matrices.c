// Matrices
#include <stdio.h>

#define DIMENSION 2

int main() {
  int a[DIMENSION][DIMENSION]; // Now a[i] contains an address of a vector with values a[i][0], ...,  a[i][DIMENSION-1]. So a conains an address of an address!
  int i, j;
  puts("We enter the values (integers)");
  for (i = 0; i < DIMENSION; i++) {
    for (j = 0; j < DIMENSION; j++) {
      printf("a(%d,%d) = ? ", i + 1, j + 1);
      scanf("%d", & (a[i][j]));
    }
  }
  puts("We print it:");
  for (i = 0; i < DIMENSION; i++) {
    for (j = 0; j < DIMENSION; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
