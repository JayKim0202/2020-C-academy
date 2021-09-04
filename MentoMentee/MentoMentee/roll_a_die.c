#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_die();

int main()
{
	srand((unsigned)time(NULL));

	int num_of_dice[6] = { 0 };

	for (int i = 0; i < 10000; i++)
		num_of_dice[roll_a_die()]++;

	for (int i = 0; i < 6; i++)
		printf("%d : %d\n", i + 1, num_of_dice[i]);

	return 0;
}

int roll_a_die()
{
	return rand() % 6;
}