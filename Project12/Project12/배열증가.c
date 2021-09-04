#define _CRT_SEUCRE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	temp = malloc(sizeof(int) * 6);

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		temp[i] = num[i];
		printf("%d", temp[i]);
	}

	free(num);
	free(temp);

	return 0;
}