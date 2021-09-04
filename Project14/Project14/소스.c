#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void add();
void add2();

int main()
{
	add2();

	return 0;
}

void add()
{
	char a[128];
	int i = 0;
	int k = 0;
	while (1)
	{
		a[i++] = getch();
		a[i] = 0;
		printf("%s", a);
		for (k = 0; k < strlen(a); k++)
			printf("\b\b");

		if (a[i - 1] == "\n") break;
		else continue;

		printf("\n");
	}
	return;
}

void add2()
{
	char a[5][20];
	int i = 0;
	int j = 0;

	while (1)
	{
		while (1)
		{
			a[j][i++] = getch();
			a[j][i] = 0;
			system("cls");
			if (a[j][i - 1] == '\b')
			{
				a[j][i - 2] = NULL;
				i - 2;
				for (int k = 0; k < i; k++)
				{
					printf("%c", a[j][k]);
				}
			}
			else
			{
				for (int k = 0; k < i; k++)
				{
					printf("%c", a[j][k]);
				}
			}

			if (a[j][i - 1] == '\r')break;
		}
		printf("\n");
		j++;
		i = 0;
		if (j == 5) break;
	}
}
