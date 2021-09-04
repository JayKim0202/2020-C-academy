// 표준 입력으로 메모리 주소가 입력됩니다. 다음 소스 코드르로안성하여 입력된 메모리 주소에서 순방향으로 6바이트, 10바이트 만큼 떨어진 메모리 주소가 각 줄에 출력되게 만드세요.

#define _CRT_SECUR_NO_WARNINGS
#include <stdio.h>

int main()
{
	short* numPtrA;
	short* numPtrB;
	short* numPtrC;

	scanf("%p", &numPtrA);

	numPtrB = numPtrA + 3;
	numPtrC = numPtrA + 5;

	printf("%x\n", numPtrB);
	printf("%x\n", numPtrC);

	return 0;
}