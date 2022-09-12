#include "matrix.h"
#include "myassert.h"

#include <stdio.h>

Matrix matrix_mult(Matrix a, Matrix b)
{
	Matrix result = {0, 0, 0, 0};

	result.x11 = (a.x11 * b.x11) + (a.x12 * b.x21);
	result.x12 = (a.x11 * b.x12) + (a.x12 * b.x22);
	result.x21 = (a.x21 * b.x11) + (a.x22 * b.x21);
	result.x22 = (a.x21 * b.x12) + (a.x22 * b.x22);

	return result;
}

Matrix matrix_pow(Matrix a, int power, int *fibs)
{
	MYASSERT(fibs)

	Matrix result = a;
	int arr[50] = {0};
	int size = 0;

	size = break_power(power, arr);
	reverse(arr, size);

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] % 2 == 0)
		{
			result = matrix_mult(result, result);
		}
		else
		{
			result = matrix_mult(result, a);
		}
		fibs[arr[i]] = result.x12;
	}

	return result;
}

int break_power(int power, int *arr)
{
	MYASSERT(arr)

	int i = 0;
	arr[i++] = power;
	while (power)
	{
		if (power % 2 == 0)
		{
			power /= 2;
			arr[i++] = power;
		}
		else
		{
			power -= 1;
			arr[i++] = power;
		}
	}
	return i - 2;
}

void reverse(int *arr, int size)
{
	MYASSERT(arr)

	for (int i = 0; i < size / 2; ++i)
		swap(arr + i, arr + size - 1 - i);
}

void swap(int *a, int *b)
{
	MYASSERT(a)
	MYASSERT(b)
	MYASSERT(a != b)

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_matrix(Matrix a)
{
	printf("%d %d\n%d %d\n", a.x11, a.x12, a.x21, a.x22);
}