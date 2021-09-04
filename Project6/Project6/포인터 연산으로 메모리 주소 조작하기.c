#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = &numArr[2];	//배열 세번째 요소의 주소를 포인터에 저장

	numPtrB = numPtrA;
	numPtrC = numPtrA;

	numPtrB++;
	numPtrC--;

	printf("%p\n", numPtrA);	//메모리 주소
	printf("%p\n", numPtrB); //sizeof(int) * 1 이므로 numPtrA에서 4가 증가함
	printf("%p\n", numPtrC); //sizeof(int) * (-1)이므로 numPtrA에서 4가 감소함

	return 0;
}