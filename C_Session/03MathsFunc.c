/* To compile files which include mathematical functions as:
 acos, asin, atan, atan2, ceil, cos, cosh, exp, fabs, floor, fmod, frexp, ldexp, log, log10, modf, pow, sin, sinh, sqrt, tan, tanh
  we need to include the library math.h and also to compile with the option -lm
  The option -lx includes the library libx.a (which may have definitions needed in our code). In this case, it includes the definitions from libm.a .
  
  So, the compilation of this file must be:
  
  gcc -o 03MathsFunc 03MathsFunc.c -lm
*/ 
#include <stdio.h>
#include <math.h>
int main()
{
    double r;
    printf("Enter a value for r: ");
    scanf("%lf",&r);
    printf("The square root of %lf is %lf \n",r , sqrt(r));
    return 0;
}
