#ifndef _MATRIX_
#define _MATRIX_

typedef struct
{
	int x11, x12;
	int x21, x22;
} Matrix;

Matrix matrix_mult(Matrix a, Matrix b);

Matrix matrix_pow(Matrix a, int power, int *fibs);

int break_power(int power, int *arr);

void reverse(int *arr, int size);

void swap(int *a, int *b);

void print_matrix(Matrix a);

#endif