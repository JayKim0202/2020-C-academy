//ǥ�� �Է����� ���� ���� ���� �ԷµǾ� �� �迭�� ����˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ���� �� �� ��°�� �ټ� ��°�� ��µǰ� ���弼��.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int numArr1[3] = { 0, };
	int numArr2[3] = { 0, };
	int* numPtr = malloc(sizeof(int) * 3);
	void* ptr = malloc(sizeof(int) * 3);
	int num1;
	int num2;

	scanf("%d %d %d %d %d %d", &numArr1[0], &numArr1[1], &numArr1[2], &numArr2[0], &numArr2[1], &numArr2[2]); //1 2 3 4 5 6

	memcpy(numPtr, numArr1, sizeof(int) * 3);
	memcpy(ptr, numArr2, sizeof(int) * 3);
	numArr1[0] = numArr1[1] = numArr1[2] = 0;
	numArr2[0] = numArr2[1] = numArr2[2] = 0;

	num1 = numPtr[2];
	num2 = ((int*)ptr)[1];

	printf("%d %d\n", num1, num2); //3 5

	free(ptr);
	free(numPtr);

	return 0;
}