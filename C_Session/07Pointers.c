// A (single) pointer is a variable which will contain an address of another variable.
// the pointer has also a type, which must match the type of the variable that is pointing to.
// The * is used both for declaring the variable and also for getting the value.
// The & is used to get the address of a variable (we have seen it when using scanf())

#include <stdio.h>


int main() {
  double x;
  double * y;

  y = & x;
  printf("Enter a value for x ");
  scanf("%lf", & x);
  printf("The value of x is %lf\n", x);
  printf("y contains an address of a double, and in this address we can find the value %lf\n", * y);
  printf("Enter a value to be written in the address y ");
  scanf("%lf", y);
  printf("Now, the value of x is %lf\n", x);
  return 0;
}
