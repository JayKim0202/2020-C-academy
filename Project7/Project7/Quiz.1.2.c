//ǥ�� �Է����� ���� 10���� �Էµ˴ϴ�. ���� �ҽ� �ڵ带�ϼ��Ͽ� �Էµ� ������ �ݴ� ������ ��µǰ� ���弼��(�� ������ �������� �����Ͽ� ����մϴ�).

//1 2 3 4 5 6 7 8 9 10
//10 9 8 7 6 5 4 3 2 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printReverse(int* arr, int count)
{
	for (int i = count - 1; i >= 0 ; i--)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int numArr[10];

	for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
	{
		scanf("%d", &numArr[i]);
	}

	printReverse(numArr, sizeof(numArr) / sizeof(int));

	return 0;
}
