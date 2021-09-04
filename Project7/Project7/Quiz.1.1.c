/*1.a,c*/

//다음 소스 코드를 완성하여 함수에서 배열의 모든 요소에 값이 저장되게 만드세요.

#include <stdio.h>

void setElement(float *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = 1.2f;
	}
}

int main()
{
	float numArr[5];

	setElement(numArr, sizeof(numArr) / sizeof(float));

	for (int i = 0; i < sizeof(numArr) / sizeof(float); i++)
	{
		printf("%f ", numArr[i]);
	}

	printf("\n");

	return 0;
}