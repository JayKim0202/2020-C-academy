//표준 입력으로 정수 10개가 입력됩니다. 다음 소스 코드를완성하여 입력된 정수가 반대 순서로 출력되게 만드세요(각 정수는 공백으로 구분하여 출력합니다).

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
