#include <stdio.h>

int main()
{
	//표준 입력으로 정수 다섯 개가 입력됩니다. 다음 소스 코드를 완성하여 입력된 정수 중에서 가장 작은 수가 출력되게 만드세요.
	int numArr[5];
	int smallestNumber;

	scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);
	
	smallestNumber = numArr[0];

	for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
	{
		if (numArr[i] <= smallestNumber)
			smallestNumber = numArr[i];
	}


	printf("%d\n", smallestNumber);

	return 0;
}
/*
	numArr[0] = 10
	numArr[1] = 50
	numArr[2] = 20
	numArr[3] = 30
	numArr[4] = 40

	smallestNumber = numArr[0] == 10

	numArr[0] <= smallestNumber
	smallestNumber = numArr[0]

	numArr[1] <= smallestNumber
	smallestNumber = numArr[0]

	numArr[2] <= smallestNumber
	smallestNumber = numArr[0]
	.
	.
	.
	smallestNumber = numArr[0]
*/