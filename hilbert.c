#include <stdio.h>
#include <stdlib.h>

unsigned int power(int base, int exp) {
	unsigned int i, result = 1;
	
	for (i = 0; i < exp; i++) {
		result = result * base;
	}

	return result;
}

void gen_hilbert(unsigned int size, double **mat) {
	*mat = (double *) malloc(size * size * sizeof(double));
	if (*mat == NULL) {
		printf("Unnable to allocate %d bytes\n", size * size * sizeof(double));
		exit(1);
	}

	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			(*mat)[size * (i) + (j)] = 1.0/(i + j + 1);
		}
	}

	return;
}

double traca(unsigned int size, double **mat) {
	double sum = 0;
	int i;
	
	for (i = 0; i < size; i++) {
		sum = sum + (*mat)[size * i + i];
	}

	return sum;
}

void print_mat(unsigned int size, double **mat) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%f ", (*mat)[size * i + j]);
		}
		printf("\n");
	}
}

int main() {

	int m = 0;
	while (1) {
		unsigned int size = power(3, m);

		printf("Hilbert matrix size: %d\n", size);

		double *A;

		gen_hilbert(size, &A);

		printf("Trasa matriu %f\n", traca(size, &A));
		m++;
	}

	return 0;
}
