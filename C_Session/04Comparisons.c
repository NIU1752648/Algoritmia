#include <stdio.h>

#include <math.h>

int main() {
  double a, b, c, disc, sqdisc;

  printf("Enter the coefficient of x**2 ");
  scanf("%lf", & a);
  printf("Enter the coefficient of x ");
  scanf("%lf", & b);
  printf("Enter the constant coefficient ");
  scanf("%lf", & c);

  disc = b * b - 4 * a * c;
  if (disc < 0) printf("The discriminant of the polynomial %lfx^2+%lfx+%lf is %lf, and there are no real solutions\n", a, b, c, disc);
  else {
    sqdisc = sqrt(disc);
    printf("The roots are %lf and %lf\n", (-b + sqdisc) / (2 * a), (-b - sqdisc) / (2 * a));
  }
  return 0;
}
