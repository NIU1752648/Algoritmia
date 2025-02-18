// Program to show how to use pointers in functions
#include <stdio.h>

void computations(double, double, double * , double * , double * , double * );
void main() {
  double x, y;
  double sum, substract, prod, quot;
  printf("Give values for x and y separated by comma: ");
  scanf("%lf,%lf", & x, & y);
  computations(x, y, & sum, & substract, & prod, & quot);
  printf("The sum is: %f\n", sum);
  printf("The difference is: %f\n", substract);
  printf("The product is: %f\n", prod);
  printf("The quotient is: %f\n", quot);
}
void computations(double x, double y, double * s, double * r, double * p, double * q) {
  * s = x + y;
  * r = x - y;
  * p = x * y;
  * q = x / y; // Will give an error if y=0
}
