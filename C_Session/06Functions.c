#include <stdio.h>
 // This code has a function f which needs a double x and returns a double computed as 1/(1+x^2)
// A function may have several parameters (separated by comma) but it can just return, at most, a value.
double f(double);

void main() {
  double x;
  printf("Coordinates of x 1/(1+x^2)\n");
  for (x = 0.0; x <= 10.0; x += 0.01) printf("%lf %lf\n", x, f(x));
}

double f(double x) // we can use again "x", as the previous one only take values inside the function main.
{
  return 1. / (1. + x * x);
}
