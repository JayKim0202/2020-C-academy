#define _CRT_SEUCRE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* temp;
	int* num = malloc(sizeof(int) * 5);

	num[0] = 10;
	num[1] = 20;
	num[2] = 30;
	num[3] = 40;
	num[4] = 50;

	for (int i = 0; i < 5; i++)
	{
		printf("%d", num[i]);
	}
	printf("\n");

	num[2] = 0;

	for (int i = 2; i < 4; i++)
	{
		num[i] = num[i + 1];
	}

	temp = malloc(sizeof(int) * 4);

	for (int i = 0; i < 4; i++)
	{
		temp[i] = num[i];
		printf("%d", temp[i]);
	}

	free(num);

	return 0;
}