//ǥ�� �Է����� int�� ���� 10���� �Էµ˴ϴ�(�ߺ� ���� �����ϴ�). ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ������ ������������ ���ĵǰ� ���弼��.

/*8 4 2 5 3 7 10 1 6 9
  10 9 8 7 6 5 4 3 2 1*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bubble_sort(int arr[], int count)
{
	int temp;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int numArr[10];

	/*scanf("%d %d %d %d %d %d %d %d %d %d",
		&numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4],
		&numArr[5], &numArr[6], &numArr[7], &numArr[8], &numArr[9]);*/

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &numArr[i]);
	}

	bubble_sort(numArr, sizeof(numArr) / sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", numArr[i]);
	}

	printf("\n");

	return 0;
}