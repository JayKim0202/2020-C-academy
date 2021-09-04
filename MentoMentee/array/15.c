#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_background(int base[10][10]);
void set_bomb(int base[10][10]);

int main()
{
	srand((unsigned)time(NULL));

	int base[10][10] = { 0 };

	set_bomb(base);
	print_background(base);
}

void print_background(int base[10][10])
{
	for (int i = 0; i < sizeof(int) * 10 * 10 / sizeof(base[0]); i++)
	{
		for (int j = 0; j < sizeof(base[0]) / sizeof(base[0][0]); j++)
		{
			if (base[i][j] == 0)
				printf(". ");
			else
				printf("# ");
		}
		printf("\n");
	}
}

void set_bomb(int base[10][10])
{
	// sizeof(base) = int pointer¿©¼­ 4byte
	for (int i = 0; i < sizeof(int) * 10 * 10 / sizeof(base[0]); i++)
	{
		for (int j = 0; j < sizeof(base[0]) / sizeof(base[0][0]); j++)
		{
			if (rand() % 99 <= 30)
				base[i][j] = 1;
		}
	}
}