#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int) * 5);
	int sum = 0;
	int average;

	printf("���� 5���� �Է��Ͻÿ�: \n");

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numPtr[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		sum += numPtr[i];
	}

	average = (sum / 5);


	printf("�� : %d\n", sum);
	printf("��� : %d\n", average);

	free(numPtr);

	return 0;
}