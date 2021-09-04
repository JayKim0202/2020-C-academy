#include <stdio.h>

int main()
{
	/*3개의 배열을 선언 후(5개짜리 배열2개, 10개짜리 1개) 3번째 배열의 앞에는 첫번째 5개짜리 배열의 내용을 복사하고, 3번째 배열 뒤에는 2번째 배열값 5개를 저장한다.*/
	int numArr1[5];
	int numArr2[5];
	int numArr3[10];
	int j;

	printf("숫자 5개를 입력하시오 : ");

	for (int i = 0; i < sizeof(numArr1) / sizeof(int); i++)
	{
		scanf("%d", &numArr1[i]);
	}

	printf("숫자 5개를 더 입력하시오 : ");

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