
#include <stdio.h>
#include <stdlib.h>

void pr_mat(double *mat, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%f ", mat[size * i + j]);
		}
		printf("\n");
	}
	return;
}

void addition(int size, double *mat1, double *mat2, double **mat3) {
	int i, j;
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			int r = size * i + j;
			(*mat3)[r] = mat1[r] + mat2[r];
		}
	}
	return;
}

void product(int size, double *mat1, double *mat2, double **mat3) {
	int i, j, k;
	double el;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < size; k++) {
				el = el + mat1[size * i + k]*mat2[size * k + j];
			}
			(*mat3)[size * i + j] = el;
			el = 0;
		}
	}
	return;
}

int main() {

	int size = 3;

	double A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	double B[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	double *C;
	if ((double *) malloc(size * size * sizeof(double)) == NULL) {
		printf("Unnable to allocate matrix");
		exit(1);
	}

	pr_mat(A, size);
	pr_mat(B, size);

	addition(size, A, B, &C);

	pr_mat(C, size);

	product(size, A, B, &C);
	
	pr_mat(C, size);
}
