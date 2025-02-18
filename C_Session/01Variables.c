/* Program 01Variables.c which shows how to assign, scan and print variables. 
*/

#include <stdio.h>

#define PI 3.141562653589 // this replaces PI in all

void main(void) // type void means that doesn't expect to give any result
{
    int i; // variable i will be of type integer
    double x=3.14; // x will be of type long float and, if necessary, we can define a value in the declaration
    
    i=1;
    printf("i is an integer and i=%d\n", i);
    printf("x is an long float (double) and x=%lf\n", x);
    printf("Enter a new value for a long float x: ");
    scanf("%lf",&x); // x is the name of the variable of type double, while &x is the address where it is stored. 
    printf("The new value for x is %lf\n", x);
    printf("Another way of see x is as %e\n", x);
    printf("The area of a circle of ratio %lf is %lf\n", x, PI*x*x);
}
