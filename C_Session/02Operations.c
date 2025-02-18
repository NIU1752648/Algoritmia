#include <stdio.h>

void main(void)
{
    int i = 10, j = 3; // variable i will be of type integer
    double x = 10, y = 3; // we can define a value in the declaration
    
    printf("Operations with integers:\n");
    printf("%d + %d = %d\n",i ,j , i+j);
    printf("%d - %d = %d\n",i ,j , i-j);
    printf("%d * %d = %d\n",i ,j , i*j);
    printf("%d / %d = %d\n",i ,j , i/j);
    
    printf("Operations with long floats:\n");
    printf("%lf + %lf = %lf\n", x, y, x+y);
    printf("%lf - %lf = %lf\n", x, y, x-y);
    printf("%lf * %lf = %lf\n", x, y, x*y);
    printf("%lf / %lf = %lf\n", x, y, x/y);
    
    printf("Operations envolving integers and floats:\n");
    printf("%d + %lf = %lf\n", i, y, i+y);
    printf("%lf * %d / %d  = %lf\n", x, i, j, x*i/j);
    printf("%lf * (%d / %d) = %lf\n", x, i, j, x*(i/j));
 
}
 
