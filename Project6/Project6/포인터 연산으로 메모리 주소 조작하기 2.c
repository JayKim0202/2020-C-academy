#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];	//배열 세 번째 요소의 메모리 주소를 포인터에 저장

	numPtrB = numPtrA - 1;
	numPtrC = numPtrA - 2;

	printf("%p\n", numPtrA); //메모리 주소
	printf("%p\n", numPtrB); //sizeof(int) * (-1)이므로 numPtrA에서 4가 감소
	printf("%p\n", numPtrC); //sizeof(int) * (-2)이므로 numPtrA에서 8이 감소

	return 0;
}