#include <stdio.h>

int main()
{
	/*3���� �迭�� ���� ��(5��¥�� �迭2��, 10��¥�� 1��) 3��° �迭�� �տ��� ù��° 5��¥�� �迭�� ������ �����ϰ�, 3��° �迭 �ڿ��� 2��° �迭�� 5���� �����Ѵ�.*/
	int numArr1[5];
	int numArr2[5];
	int numArr3[10];
	int j;

	printf("���� 5���� �Է��Ͻÿ� : ");

	for (int i = 0; i < sizeof(numArr1) / sizeof(int); i++)
	{
		scanf("%d", &numArr1[i]);
	}

	printf("���� 5���� �� �Է��Ͻÿ� : ");

	for (int i = 0; i < sizeof(numArr2) / sizeof(int); i++)
	{
		scanf("%d", &numArr2[i]);
	}

	for (int i = 0; i < sizeof(numArr1) / sizeof(int); i++)
	{
		numArr3[i] = numArr1[i];
	}

	for (int i = 5, j = 0; i < sizeof(numArr3) /  sizeof(int), j < sizeof(numArr2) / sizeof(int); i++, j++)
	{
		numArr3[i] = numArr2[j];
	}

	for (int i = 0; i < sizeof(numArr3) / sizeof(int); i++)
	{
		printf("%d\t", numArr3[i]);
	}

	return 0;

}