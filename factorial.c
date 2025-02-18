#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
	int i, nf = 1;
	for (i = 1; i <= n; i++) {
		nf = nf * i;
	} 
	return nf;
}

int main(int argc, char *argv[]) {
	int a = atoi(argv[1]);
	printf("%d factorial is %d\n", a, factorial(a));
	return 0;
}
