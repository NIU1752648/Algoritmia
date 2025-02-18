#include <stdio.h>
#include <stdlib.h>

int power(int base, int exp) {
	int i, result = 1;
	for (i = 0; i < exp; i++) {
		result = result * base;
	}
	return result;
}

double traca(int mida, double *a) {
	int i, sum = 0;
	for (i = 0; i < mida; i++) {
		sum = sum + a[mida * i + i];
	}
	return sum;
}

void hilbert(int mida_h, double *a) {
	int i,j;
	a = (double *) malloc(mida_h * mida_h * sizeof(double));
	
	if (a == NULL) {
		printf("Assignacio impossible per matriu de mida 3^%d", mida_h);
		exit(1);
	}

#define A(i, j) a[mida_h * i + j]
	for (i = 0; i < mida_h; i++) {
		for (j = 0; j < mida_h; j++) {
			A(i, j) = 1/(i + j + 1);
		}
	}
#undef A
	return;
}

void printmatriu(int mida, double *a) {
	int i, j;
	for (i = 0; i < mida; i++) {
		for (j = 0; j < mida; j++) {
			printf("%f ", a[mida * i + i]);
		}
		printf("\n");
	}
	return;
}

int main() {
	int m = 9;

	printf("seg f here");
	double *h1;
	printf("seg f not here");
	hilbert(m, h1);
	printf("Traca matriu mida %d: %f\n", m, traca(m, h1)); 

	free(h1);
	return 0;
}
