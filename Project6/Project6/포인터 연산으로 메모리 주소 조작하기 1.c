#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = numArr;	//배열 첫 번쨰 요소의 메모리 주소를 포인터에 저장

	numPtrB = numPtrA + 1;
	numPtrC = numPtrA + 2;

	printf("%p\n", numPtrA);	//메모리 주소.
	printf("%p\n", numPtrB);	//sizeof(int) * 1이므로 numPtrA에서 4가 증가함
	printf("%p\n", numPtrC);	//sizeof(int) * 2이므로 numPtrB에서 8이 증가함

	return 0;
}