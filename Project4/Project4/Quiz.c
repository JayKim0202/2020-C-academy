#include <stdio.h>

int main()
{
	//ǥ�� �Է����� ���� �ټ� ���� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ���� �߿��� ���� ���� ���� ��µǰ� ���弼��.
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