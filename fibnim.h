#ifndef _FIBNIM_
#define _FIBNIM_

void calculate_fibs(int *fibs, int size);

int next_turn(int total, int possible, int *fibs, int size);

int find_min_fib(int total, int *fibs, int size);

int lower_bound(int l, int r, int x, int *a);

#endif