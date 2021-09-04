#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

void print_background(int tile[17][20], int current[2]);
void move_random(int tile[17][20], int current[2]);

int main()
{
	srand((unsigned)time(NULL));
	
	int tile[17][20] = { 0 };
	int current[2] = { 8, 9 };
	int preview[2] = { 0 };
	tile[current[0]][current[1]] = 1;

	for (int i = 0; i < 30; i++)
	{
		print_background(tile, current);
		preview[0] = current[0];
		preview[1] = current[1];
		move_random(tile, current);
		if (tile[current[0]][current[1]] == 1)
		{
			system("cls");
			current[0] = preview[0];
			current[1] = preview[1];
			continue;
		}
		tile[current[0]][current[1]] = 1;
		Sleep(1000);
		if (i < 30)
			system("cls");
	}

	return 0;
}

void print_background(int tile[17][20], int current[2])
{
	for (int i = 0; i < sizeof(int) * 17 * 20 / sizeof(tile[0]); i++)
	{
		for (int j = 0; j < sizeof(tile[0]) / sizeof(tile[0][0]); j++)
		{
			if (tile[i][j] == 0)
				printf(". ");
			else if (i == current[0] && j == current[1])
				printf("# ");
			else
				printf("* ");
		}
		printf("\n");
	}
}

void move_random(int tile[17][20], int current[2])
{
	int number = rand() % 8;

	switch (number)
	{
	case 0:
		current[0]--;
		break;
	case 1:
		current[0]--;
		current[1]++;
		break;
	case 2:
		current[1]++;
		break;
	case 3:
		current[0]++;
		current[1]++;
		break;
	case 4:
		current[0]++;
		break;
	case 5:
		current[0]++;
		current[1]--;
		break;
	case 6:
		current[1]--;
		break;
	case 7:
		current[0]--;
		current[1]--;
		break;
	}

	if (current[0] < 0 || current[1] < 0 || current[0] > 17 || current[1] > 20)
		exit(0);
}