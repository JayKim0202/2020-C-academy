//다음 소스코드를 완성하여 55와 22가 각 줄에 출력되게 만드세요.
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