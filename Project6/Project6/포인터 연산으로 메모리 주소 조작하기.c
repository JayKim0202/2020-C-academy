#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];	//�迭 ����° ����� �ּҸ� �����Ϳ� ����

	numPtrB = numPtrA;
	numPtrC = numPtrA;

	numPtrB++;
	numPtrC--;

	printf("%p\n", numPtrA);	//�޸� �ּ�
	printf("%p\n", numPtrB); //sizeof(int) * 1 �̹Ƿ� numPtrA���� 4�� ������
	printf("%p\n", numPtrC); //sizeof(int) * (-1)�̹Ƿ� numPtrA���� 4�� ������

	return 0;
}