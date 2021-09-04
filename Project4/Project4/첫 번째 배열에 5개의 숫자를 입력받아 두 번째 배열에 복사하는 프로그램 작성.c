#include <stdio.h>

int main()
{
	int numArr1[5];
	int numArr2[5];

	for (int i = 0; i < sizeof(numArr1) / sizeof(int); i++)
	{
		scanf("%d", &numArr1[i]);
	}

	for (int i = 0; i < sizeof(numArr2) / sizeof(int); i++)
	{
		numArr2[i] = numArr1[i];
	}

	for (int i = 0; i < sizeof(numArr1) / sizeof(int); i++)
	{
		printf("%d\n", numArr2[i]);
	}

	return 0;
}