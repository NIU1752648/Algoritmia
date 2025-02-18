#include <stdio.h>

const double PI = 3.1415926535897932;

int factorial(int lim) {
    int _fact = 1;
    int i;
    for (i = 1; i <= lim; i++) {
        _fact = _fact * i;
    }
    return _fact;
}

int main() {
    int fact;
    
    printf("Calculate the factorial of: ");
    scanf("%d", &fact);

    if (fact < 0) {
        printf("No s'accepta valor negatiu");
    }
    else if (fact == 0) {
        printf("0 factorial és 1");
    }
    else {
        printf("%d factorial és %d", fact, factorial(fact));
    }

    return 0;
}