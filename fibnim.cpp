#include "fibnim.h"
#include "matrix.h"
#include "myassert.h"

void calculate_fibs(int *fibs, int size)
{
	Matrix a = {1, 1, 1, 0};
	
	for (int i = size - 1; i >= 1; --i)
	{
		if (fibs[i] == 0)
			matrix_pow(a, i, fibs);
	}
}

int next_turn(int total, int possible, int *fibs, int size)
{
	int min_fib = find_min_fib(total, fibs, size);

	return min_fib <= possible ? min_fib : 1;
}

int find_min_fib(int total, int *fibs, int size)
{
	int i = lower_bound(2, size - 1, total, fibs);
	int result = 0;

	for (; i >= 2; --i)
	{
		if (fibs[i] <= total)
		{
			total -= fibs[i];
			result = fibs[i];
		}
	}

	return result;
}

int lower_bound(int l, int r, int x, int *a)
{
	while (l < r)
	{
		int m = (l + r) / 2;
		if (a[m] < x)
			l = m + 1;
		else
			r = m; 
	}

	return x == a[l] ? l : l - 1;
}