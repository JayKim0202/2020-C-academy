#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int) * 5);
	int sum = 0;
	int average;

	printf("숫자 5개를 입력하시오: \n");

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numPtr[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		sum += numPtr[i];
	}

	average = (sum / 5);


	printf("합 : %d\n", sum);
	printf("평균 : %d\n", average);

	free(numPtr);

	return 0;
}