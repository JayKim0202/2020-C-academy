#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)	// 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;		// void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;		// void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)		// a가 b보다 작을 때는
		return -1;			// -1로 반환
	else if (num1 > num2)	// a가 b보다 클 때는
		return 1;			// 1로 반환
	
	return 0;	// a와 b가 같을 때는 0 반환
}

int main()
{
	int numArr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };

	// 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
	qsort(numArr, sizeof(numArr) / sizeof(int), sizeof(int), compare);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", numArr[i]);
	}

	printf("\n");

	return 0;
}