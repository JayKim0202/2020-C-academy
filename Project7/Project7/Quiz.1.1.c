/*1.a,c*/

//���� �ҽ� �ڵ带 �ϼ��Ͽ� �Լ����� �迭�� ��� ��ҿ� ���� ����ǰ� ���弼��.

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