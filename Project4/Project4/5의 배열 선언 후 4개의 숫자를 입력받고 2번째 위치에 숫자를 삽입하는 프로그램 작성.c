#include <stdio.h>

int main()
{
	int numArr[5];

	printf("���� 4���� �Է��Ͻÿ� :");
															   // 0 1 2 3  4
	for (int i = 0; i < sizeof(numArr) / sizeof(int) - 1; i++) // 1 2 3 4 ( )
	{
		scanf("%d", &numArr[i]);
	}

	for (int i = 3; i > 0; i--)
	{
		numArr[i + 1] = numArr[i];			//numArr[4] = numArr[3]	  numArr[3] = numArr[2]   numArr[2] = numArr[1}
	}

	printf("���� 1���� �� �Է��Ͻÿ� :");

	scanf("%d", &numArr[1]);

	for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
	{
		printf("%d\n", numArr[i]);
	}


	return 0;
}