#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr1 = malloc(sizeof(int) * 10);
	int* numPtr2 = malloc(sizeof(int) * 10);
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &numPtr1[i]);
	}

	for (i = 0, j = 9; i < 10, j >= 0; i++, j--)
	{
		numPtr2[i] = numPtr1[j];
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", numPtr2[i]);
	}


	free(numPtr1);
	free(numPtr2);

	return 0;
}