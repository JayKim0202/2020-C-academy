//���� �ҽ��ڵ带 �ϼ��Ͽ� 55�� 22�� �� �ٿ� ��µǰ� ���弼��.
#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	void* ptr;

	numPtrA = &numArr[2];	//33
	ptr = numArr;

	printf("%d\n", *(numPtrA + 2));	//55
	printf("%d\n", *((int*)ptr + 1)); //22
}