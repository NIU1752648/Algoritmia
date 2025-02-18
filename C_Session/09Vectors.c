// Vectors
#include <stdio.h>

#define DIMENSION 2
void printvector(float[], int);
int main() {
  float v[DIMENSION]; // define a vector v which will have 2 positions: v[0] and v[1]. Now v contains the address and v[0] the float value in v.
  int i;
  puts("Enter the values for the vector (floats)");
  for (i = 0; i < DIMENSION; i++) {
    printf("v(%d) = ? ", i + 1);
    scanf("%f", & (v[i]));
  }
  puts("Now we print it:");
  printvector(v, DIMENSION);
  return 0;
}
void printvector(float vect[], int dim) {
  int i;
  for (i = 0; i < dim; i++) printf("%f ", vect[i]);
  printf("\n");
  return;
}
