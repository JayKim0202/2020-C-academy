#include <stdio.h>

int main()
{
	//ǥ�� �Է����� ���� �ټ� ���� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ���� �߿��� ���� ���� ���� ��µȰ� ���弼��.

	int numArr[5];
	int smallestNumber;

	scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);

	if (numArr[0] < numArr[1] && numArr[0] < numArr[2] && numArr[0] < numArr[3] && numArr[0] < numArr[4])
		smallestNumber = numArr[0];
	else if (numArr[1] < numArr[0] && numArr[1] < numArr[2] && numArr[1] < numArr[3] && numArr[1] < numArr[4])
		smallestNumber = numArr[1];
	else if (numArr[2] < numArr[0] && numArr[2] < numArr[1] && numArr[2] < numArr[3] && numArr[2] < numArr[4])
		smallestNumber = numArr[2];
	else if (numArr[3] < numArr[1] && numArr[3] < numArr[2] && numArr[3] < numArr[0] && numArr[3] < numArr[4])
		smallestNumber = numArr[3];
	else if (numArr[4] < numArr[1] && numArr[4] < numArr[2] && numArr[4] < numArr[3] && numArr[4] < numArr[0])
		smallestNumber = numArr[4];

	printf("%d\n", smallestNumber);

	return 0;
}