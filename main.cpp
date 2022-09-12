#include <stdio.h>
#include <stdlib.h>

#include "fibnim.h"
#include "matrix.h"

#define SIZE 41

enum Players
{
	PROGRAM = 0,
	PLAYER  = 1
};

int main()
{
	int fibs[SIZE] = {0};
	int total = 0, possible = 0;
	int who_moves = PROGRAM, took = 0;;
	char buffer[SIZE];

	calculate_fibs(fibs, SIZE);

	printf("Enter number of coines: ");
	fgets(buffer, SIZE, stdin);
	total = atoi(buffer);
	possible = total - 1;
	
	printf("Do you wnat to move first? (y/n) ");
	fgets(buffer, SIZE, stdin);
	who_moves = buffer[0] == 'y' ? PLAYER : PROGRAM;

	while (total > 0)
	{
		printf("\nCoins now: %d, possible to take: %d\n", total, possible);
		if (who_moves == PLAYER)
		{
			printf("How many do you want to take? ");
			fgets(buffer, SIZE, stdin);
			took = atoi(buffer);

			total -= took;
			possible = 2 * took;
			who_moves = 1 - who_moves;
		}
		else
		{
			took = next_turn(total, possible, fibs, SIZE);
			total -= took;
			possible = 2 * took;
			who_moves = 1 - who_moves;

			printf("I took %d coins\n", took);
		}
	}

	if (who_moves == PLAYER)
	{
		printf("You lost\n");
	}
	else
	{
		printf("You won\n");
	}
}