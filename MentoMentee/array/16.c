#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

void char_loc(int cl[2], int input, int base[10][10]);
void print_background(int base[10][10]);

int main()
{
	int base[10][10] = { 0 };
	int cl[2] = { 0 };
	int key;

	base[0][0] = 1;
	base[6][6] = 2;
	base[7][7] = 2;
	base[9][9] = 3;

	while (base[9][9] == 3)
	{
		print_background(base);
		key = _getch();
		if (key == 224)
			key = _getch();
		else
		{
			system("cls");
			continue;
		}

		char_loc(cl, key, base);
		system("cls");
	}

	print_background(base);
	return 0;
}

void char_loc(int cl[2], int input, int base[10][10])
{
	base[cl[0]][cl[1]] = 0;

	switch (input)
	{
	case UP:
		cl[0]--;
		break;
	case DOWN:
		cl[0]++;
		break;
	case LEFT:
		cl[1]--;
		break;
	case RIGHT:
		cl[1]++;
		break;
	}

	if (base[cl[0]][cl[1]] == 2)
		exit(0);

	if (cl[0] < 0 || cl[0] > 9 || cl[1] < 0 || cl[1] > 9)
		exit(0);

	base[cl[0]][cl[1]] = 1;
}

void print_background(int base[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (base[i][j] == 1)
				printf("#");
			else if (base[i][j] == 2)
				printf("M");
			else if (base[i][j] == 3)
				printf("G");
			else
				printf(".");
		}
		printf("\n");
	}
}