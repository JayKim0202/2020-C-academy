#include <stdio.h>

int main()
{
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

	for (int i = 0; i < sizeof(numArr) / sizeof(int); i++) //sizeof(numArr) : int크기 * numArr크기 == 4byte * 10 = 40
	{													   //sizeof(numArr) / sizeof(int) : 40 / 4 = 10
		printf("%d\n", numArr[i]);
	}

	return 0;
}