#include <stdio.h>

int main()
{
	int numArr[10];
	int sum = 0;



	for ( int i = 0; i < sizeof(numArr) / sizeof(int); i++)
	{
		scanf("%d", &numArr[i]);
	}

	for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
	{
		sum += numArr[i];
	}

	printf("%d\n", sum);

	return 0;
}