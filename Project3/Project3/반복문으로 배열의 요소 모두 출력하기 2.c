#include <stdio.h>

int main()
{
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

	for (int i = sizeof(numArr) / sizeof(int) - 1; i >=0; i--)
	{
		printf("%d\n", numArr[i]);
	}

	return 0;
}