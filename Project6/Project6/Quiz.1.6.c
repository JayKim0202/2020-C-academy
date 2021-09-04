//표준 입력으로 *바이트 크기의 16진 정수가 입력됩니다. 다음 소스 코드를 완성하여 16진 정수의 낮은 자릿수 4바이트가 출력되게 만드세요.

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long* numPtr1 = malloc(sizeof(unsigned long long));
	unsigned int* numPtr2;

	scanf("%llx", numPtr1);

	numPtr2 = (unsigned int*)numPtr1;

	printf("0x%x\n", *numPtr2);

	free(numPtr1);

	return 0;
}